using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System;

public class Model : MonoBehaviour
{
    bool started = false;

    public double[] Qs = new double[3];
    public double[] Qref = new double[3];
    private double[] Qrefrad = new double[3];
    public float[] thetas = new float[3];

    public double[] Taus = new double[3];
    // private double[] TausSend = new double[3];
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if(started){
            // Debug.Log("here");
            get_Q(Qs);
            for (int i = 0; i < JointTracker.num_joints-1; i++){
                thetas[i] = (float)(Mathf.Rad2Deg*Qs[i]);
                // TausSend[i] = Taus[i]/100;
                Qrefrad[i] = Qref[i]*Mathf.Deg2Rad;
            }

            for (int i = 0; i < JointTracker.num_joints-1; i++){
                GameObject frame = GameObject.Find("Frame" + (i+1).ToString());
                frame.transform.localRotation = Quaternion.AngleAxis(-(float)JointTracker.alpha[i],Vector3.right)*Quaternion.AngleAxis(-((float)JointTracker.theta[i]+thetas[i]), Vector3.up);
            }

            set_Qref(Qref);
        }
    }

    public void start_sim(){
        start();
        started = true;
    }

    private void OnApplicationQuit() {
        if(started) stop();
    }

    [DllImport("dynamic_model")]
    public static extern void start();
    
    [DllImport("dynamic_model")]
    public static extern void stop();
    
    [DllImport("dynamic_model")]
    public static extern void get_Q(double[] Qs); 

    [DllImport("dynamic_model")]
    public static extern void set_Tau(double[] Tau);

    [DllImport("dynamic_model")]
    public static extern void set_Qref(double[] Qref);
}
