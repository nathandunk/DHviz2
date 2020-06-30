# Though Python for Unity currently uses Python 2.7,
# We are ready for the coming of Python 3.x.
from __future__ import division, print_function

# This import fixes our sys.path if it's missing the package root.
# It also adds threading.get_ident if it's missing.
from unity_python.client import unity_client

import os
import socket
import sys
import threading
import time
import subprocess

import numpy as np
from sympy import *
from sympy import codegen
import json

try_to_connect = True

# A client requires a unique name.
client_name = "dynamics.client"

def dh2tf(a, alpha, d, theta):
    if not all(len(lst) == len(a) for lst in [alpha, d, theta]):
        print("Incorrect length of a, alpha, d, theta. Returning 0")
        return 0
    Ti  = []

    for i in range(0,len(a)):
        sinTheta = sin(theta[i])
        cosTheta = cos(theta[i])
        sinAlpha = sin(alpha[i])
        cosAlpha = cos(alpha[i])
        T = np.array([[         cosTheta,         -sinTheta,       0.0,           a[i]],
                    [sinTheta*cosAlpha, cosTheta*cosAlpha, -sinAlpha, -sinAlpha*d[i]],
                    [sinTheta*sinAlpha, cosTheta*sinAlpha,  cosAlpha,  cosAlpha*d[i]],
                    [              0.0,               0.0,       0.0,            1.0]])
        Ti.append(T)

    return Ti

def dynamics_newtonian(m,Pc,Ic,Ti,Qd,Qdd,g0):
    num = len(m)

    w = []
    wd = []
    vd = []
    vcd = []
    F = []
    N = []

    # Pad vectors for notation consistency
    m = list(m)
    m.insert(0,0)
    Pc = list(Pc)
    Pc.insert(0,0)
    Ic = list(Ic)
    Ic.insert(0,0)
    Qd = list(Qd)
    Qd.insert(0,0)
    Qdd = list(Qdd)
    Qdd.insert(0,0)

    Z = np.array([[0, 0, 1.0]]).T

    w = [np.array([[0, 0, 0]]).T] * (num+1)
    wd = [np.array([[0, 0, 0]]).T] * (num+1)
    vd = [np.array([[0, 0, 0]]).T] * (num+1)
    vcd = [np.array([[0, 0, 0]]).T] * (num+1)
    F = [np.array([[0, 0, 0]]).T] * (num+1)
    N = [np.array([[0, 0, 0]]).T] * (num+1)

    f = [np.array([[0, 0, 0]]).T] * (num+1)
    n = [np.array([[0, 0, 0]]).T] * (num+1)
    
    Tau = [0] * (num+1)

    G = -g0
    vd[0] = G

    for i in range(0,num):
        R        = Ti[i,0:3,0:3].T                                                                        # ^i+1_i R
        P        = Ti[i,0:3,3]                                                                            # ^i P_i+1
        w[i+1]   = R.dot(w[i]) + Z * Qd[i+1]                                                                # 6.45
        wd[i+1]  = R.dot(wd[i]) + np.cross(R.dot(w[i]),Z * Qd[i+1],axis=0) + Z * Qdd[i+1]                  # 6.46
        vd[i+1]  = R.dot(np.cross(wd[i],P,axis=0) + np.cross(w[i],np.cross(w[i],P,axis=0),axis=0) + vd[i]) # 6.47
        vcd[i+1] = np.cross(wd[i+1],np.array(Pc[i+1]).T,axis=0) + np.cross(w[i+1],np.cross(w[i+1],np.array(Pc[i+1]).T,axis=0),axis=0) + vd[i+1]          # 6.48
        F[i+1]   = m[i+1]*vcd[i+1]                                                                          # 6.49
        N[i+1]   = Ic[i+1].dot(wd[i+1]) + np.cross(w[i+1],Ic[i+1].dot(w[i+1]),axis=0)                       # 6.50

    for i in range(num,0,-1):
        if i == num:
            f[i] = F[i]                                           # 6.51
            n[i] = N[i] + np.cross(np.array(Pc[i]).T,F[i],axis=0) # 6.52
        else:
            R = Ti[i,0:3,0:3]
            P = Ti[i,0:3,3]    
            f[i] = R.dot(f[i+1]) + F[i]  # 6.51
            n[i] = N[i] + R.dot(n[i+1]) + np.cross(np.array(Pc[i]).T,F[i],axis=0) + np.cross(P,R.dot(f[i+1]),axis=0) # 6.52
        Tau[i] = (n[i].T.dot(Z))[0,0] # 6.53
    
    return Tau[1:]

def dynamics(a, alpha, d, theta):
    T_array = dh2tf(a,alpha,d,theta)

    T_array = np.array(T_array)

    ints = range(1,len(a)+1)

    Q = symbols([('q' + str(i) + ' ') for i in ints][:-1])

    Qd = symbols([('q' + str(i) + 'd ') for i in ints][:-1])
    
    Qdd = symbols([('q' + str(i) + 'dd ') for i in ints][:-1])
    
    m = symbols([('m' + str(i) + ' ') for i in ints][:-1])
    
    Pc = []
    Ic = []
    for i in range(1,len(a)+1):
        Pci = symbols('Pc' + str(i) + 'x Pc' + str(i) + 'y Pc' + str(i) + 'z')
        Pc.append([list(Pci)])

        Icivars = symbols('Ic' + str(i) + 'xx Ic' + str(i) + 'xy Ic' + str(i) + 'xz Ic' + str(i) + 'yy Ic' + str(i) + 'yz Ic' + str(i) + 'zz')
        Ic.append(np.array([[ Icivars[0], -Icivars[1], -Icivars[2]],
                            [-Icivars[1],  Icivars[3], -Icivars[4]],
                            [-Icivars[2], -Icivars[4],  Icivars[5]]]))

    g = symbols('g')
    g0 = np.array([[0,0,-g]]).T

    Tau = dynamics_newtonian(m, Pc, Ic, T_array, Qd, Qdd, g0)

    return separate_mvg(Tau, Qdd, g)

def separate_mvg(Tau, Qdd, g):
    n = len(Tau)
    # M = [[0]*n]*n
    M = [[0 for i in range(n)] for j in range(n)] 
    G = [0]*n
    V = [0]*n
    for i in range(0,n):
        for j in range(0,n):
            M[i][j] = diff(Tau[i],Qdd[j])
        G[i] = diff(Tau[i],g) * g
        V[i] = Tau[i].subs([(qdd, 0) for qdd in Qdd] + [(g,0)])
    return (M, V, G)

def WriteFiles(M, V, G):
    num = len(V)

    file_header = ["#pragma once\n\n",
                "#include <Params.hpp>\n",
                "#include <Mahi/Util.hpp>\n",
                "#include <Eigen/Dense>\n\n"
                "using namespace mahi::util;\n\n"]

    #Write M
    Mh = open("cpp/src/M.hpp", "w")
    M_func_setup = ["Eigen::MatrixXd get_M(const Eigen::VectorXd Qs){\n",
                "\t" + ' '.join(["double q" + str(i+1) + " = Qs(" + str(i) + ");" for i in range(0,num)]) + "\n\n",
                "\tEigen::MatrixXd M = Eigen::MatrixXd::Zero(" + str(num) + "," + str(num) + "); \n\n"]

    Mh.writelines(file_header + M_func_setup)

    for i in range(0,num):
        for j in range(0,num):
            Mh.writelines("\t" + ccode(M[i][j],assign_to=("M(" + str(i) + "," + str(j) + ")")) + "\n")

    Mh.writelines("\n\treturn M;\n}")
    Mh.close()
    
    Mh.close()
                
    #Write V
    Vh = open("cpp/src/V.hpp", "w")
    V_func_setup = ["Eigen::VectorXd get_V(const Eigen::VectorXd Qs, const Eigen::VectorXd Qds){\n",
                "\t" + ' '.join(["double q" + str(i+1) + " = Qs(" + str(i) + ");" for i in range(0,num)]) + "\n",
                "\t" + ' '.join(["double q" + str(i+1) + "d = Qds(" + str(i) + ");" for i in range(0,num)]) + "\n\n",
                "\tEigen::VectorXd V = Eigen::VectorXd::Zero(" + str(num) + "); \n\n"]

    Vh.writelines(file_header + V_func_setup)

    for i in range(0,num):
        Vh.writelines("\t" + ccode(V[i],assign_to=("V[" + str(i) + "]")) + "\n")

    Vh.writelines("\n\treturn V;\n}")
    Vh.close()

    #Write G
    Gh = open("cpp/src/G.hpp", "w")
    G_func_setup = ["Eigen::VectorXd get_G(const Eigen::VectorXd Qs){\n",
                "\t" + ' '.join(["double q" + str(i+1) + " = Qs(" + str(i) + ");" for i in range(0,num)]) + "\n\n",
                "\tEigen::VectorXd G = Eigen::VectorXd::Zero(" + str(num) + "); \n\n"]

    Gh.writelines(file_header + G_func_setup)

    for i in range(0,num):
        Gh.writelines("\t" + ccode(G[i],assign_to=("G[" + str(i) + "]")) + "\n")

    Gh.writelines("\n\treturn G;\n}")

    Gh.close()

def write_params(num_joints):
    
    params_file = open("cpp/Params.json", "r")
    params_data = params_file.read()
    params_file.close()
    params_json = json.loads(params_data)

    params_hpp = open("cpp/src/Params.hpp", "w")

    prefixes = ["Ic", "Pc", "m"]
    suffixes = [["xx", "xy", "xz", "yy", "yz", "zz"],
                ["x", "y", "z"],
                [""]]

    params_hpp.writelines("#pragma once\n\n")

    params_hpp.writelines("constexpr size_t num_joints = " + str(num_joints) + ";\n\n")

    for i in range(0,num_joints):
        joint_num = params_json["joints"][i]["jointNum"]
        params_hpp.writelines("// Joint " + str(joint_num) + "\n\n")
        for num, prefix in enumerate(prefixes):
            for suffix in suffixes[num]:
                val = params_json["joints"][i][prefix + suffix]
                params_hpp.writelines("constexpr double " + prefix + str(joint_num) + suffix + " = " + str(val) + ";\n")
            params_hpp.writelines("\n")
    params_hpp.writelines("constexpr double g =  9.80665000;")
    params_hpp.close()

class RunDynamics(unity_client.UnityClientService):
    """
    A generic client that allows eval, exec, and access to the globals.

    Override the name and you can use this service to connect to any framework.
    """
    def __init__(self):
        self._globals = dict()

    # The client name is used for logging and calls from Unity.
    def exposed_client_name(self):
        return client_name

    # def exposed_globals(self):
    #     return self._globals

    # # Eval function which can be called from Unity.
    # # The text will print on the client's stdout.
    # def exposed_eval(self, string):
    #     print("eval({})".format(string))
    #     return eval(string, self._globals)

    # def exposed_exec(self, string):
    #     print("exec({})".format(string))
    #     exec(string, self._globals)

    # # The on_server_shutdown service tells the client that Unity has disconnected from it.
    # # The following function determines how this is handled.
    # # The 'invite_retry' flag is a bloolean.
    # def exposed_on_server_shutdown(self, invite_retry):
    #     global try_to_connect
    #     try_to_connect = invite_retry
    #     super(EvalExecClientService, self).exposed_on_server_shutdown(invite_retry)

    def exposed_test(self, dh_params):
        a = dh_params[0]
        alpha = dh_params[1]
        d = dh_params[2]
        theta = dh_params[3]
        for i in range(0,len(theta)-1):
            theta[i] = np.deg2rad(theta[i]) + symbols('q'+str(i+1))
            alpha[i] = np.deg2rad(alpha[i])
            
        M, V, G = dynamics(a, alpha, d, theta)

        WriteFiles(M,V,G)
        write_params(len(theta)-1)
        print("Dynamics have been written to file.")
        print("Running cmake.")
        os.chdir('cpp/build')
        os.system('cmake .. -G "Visual Studio 16 2019" -A x64')
        os.system('cmake --build . --config Release')

"""
This client is set up to be run from the command-line, or via C# API (PythonRunner.SpawnClient).
An exterior application could also be made to connect to Unity.
"""
if __name__ == '__main__':
    # This is the loop which maintains the connection to Unity.
    # It handles reconnection, and whether it is needed (try_to_connect may be false).
    while try_to_connect:
        time.sleep(0.5)
        try:
            # Here starts a new thread connecting to Unity.
            # It listens to incoming messages, and uses the defined service.
            c = unity_client.connect(RunDynamics)
        except socket.error:
            print("failed to connect; try again later")
            continue

        print("connected")
        try:
            
            c.thread.join() # Wait for KeyboardInterrupt (^c or server quit)
        except KeyboardInterrupt:
            c.close()
            c.thread.join() # Wait for the thread to notice the close()
        print("disconnected")
