#pragma once

#include <Params.hpp>
#include <Mahi/Util.hpp>
#include <Eigen/Dense>

using namespace mahi::util;

Eigen::VectorXd get_V(const Eigen::VectorXd Qs, const Eigen::VectorXd Qds){
	double q1 = Qs(0); double q2 = Qs(1); double q3 = Qs(2);
	double q1d = Qds(0); double q2d = Qds(1); double q3d = Qds(2);

	Eigen::VectorXd V = Eigen::VectorXd::Zero(3); 

	V[0] = -6.12323399573677e-17*Ic2xz*q1d*q2d*cos(q2 + 1.5707963267949) + 6.12323399573677e-17*Ic2yz*q1d*q2d*sin(q2 + 1.5707963267949) - 6.12323399573677e-17*Ic3xz*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) - 6.12323399573677e-17*Ic3yz*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 6.12323399573677e-17*Pc2x*m2*(-1.0*Pc2z*q1d*q2d*cos(q2 + 1.5707963267949) - 1.0*q1d*(-1.0*Pc2x*q1d*cos(q2 + 1.5707963267949) + 1.0*Pc2y*q1d*sin(q2 + 1.5707963267949))*sin(q2 + 1.5707963267949) + (6.12323399573677e-17*q1d + 1.0*q2d)*(-Pc2y*(6.12323399573677e-17*q1d + 1.0*q2d) + 1.0*Pc2z*q1d*cos(q2 + 1.5707963267949))) - 6.12323399573677e-17*Pc2y*m2*(-1.0*Pc2z*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*q1d*(-1.0*Pc2x*q1d*cos(q2 + 1.5707963267949) + 1.0*Pc2y*q1d*sin(q2 + 1.5707963267949))*cos(q2 + 1.5707963267949) - (6.12323399573677e-17*q1d + 1.0*q2d)*(Pc2x*(6.12323399573677e-17*q1d + 1.0*q2d) - 1.0*Pc2z*q1d*sin(q2 + 1.5707963267949))) + 6.12323399573677e-17*Pc3x*m3*(-Pc3z*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*pow(q1d, 2)*sin(q2 + 1.5707963267949)*cos(q3)*cos(q2 + 1.5707963267949) - (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q3)) - 6.12323399573677e-17*Pc3y*m3*(Pc3z*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 0.0900000035762787*pow(q1d, 2)*sin(q3)*sin(q2 + 1.5707963267949)*cos(q2 + 1.5707963267949) + (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q3)) + 5.510910815147e-18*m3*(-Pc3z*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*pow(q1d, 2)*sin(q2 + 1.5707963267949)*cos(q3)*cos(q2 + 1.5707963267949) - (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q3))*cos(q3) + 5.510910815147e-18*m3*(Pc3z*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 0.0900000035762787*pow(q1d, 2)*sin(q3)*sin(q2 + 1.5707963267949)*cos(q2 + 1.5707963267949) + (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q3))*sin(q3) - 6.12323399573677e-17*q1d*(1.0*Ic2xx*q1d*sin(q2 + 1.5707963267949) - 1.0*Ic2xy*q1d*cos(q2 + 1.5707963267949) - Ic2xz*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q2 + 1.5707963267949) + 6.12323399573677e-17*q1d*(-1.0*Ic2xy*q1d*sin(q2 + 1.5707963267949) + 1.0*Ic2yy*q1d*cos(q2 + 1.5707963267949) - Ic2yz*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q2 + 1.5707963267949) - 6.12323399573677e-17*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))*(Ic3xx*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - Ic3xy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3xz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)) + 6.12323399573677e-17*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))*(-Ic3xy*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + Ic3yy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3yz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)) + 1.0*(1.0*Ic2xx*q1d*q2d*cos(q2 + 1.5707963267949) + 1.0*Ic2xy*q1d*q2d*sin(q2 + 1.5707963267949) + Pc2y*m2*(1.0*Pc2x*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*Pc2y*q1d*q2d*cos(q2 + 1.5707963267949) + 1.0*q1d*(Pc2x*(6.12323399573677e-17*q1d + 1.0*q2d) - 1.0*Pc2z*q1d*sin(q2 + 1.5707963267949))*sin(q2 + 1.5707963267949) - 1.0*q1d*(-Pc2y*(6.12323399573677e-17*q1d + 1.0*q2d) + 1.0*Pc2z*q1d*cos(q2 + 1.5707963267949))*cos(q2 + 1.5707963267949)) - Pc2z*m2*(-1.0*Pc2z*q1d*q2d*cos(q2 + 1.5707963267949) - 1.0*q1d*(-1.0*Pc2x*q1d*cos(q2 + 1.5707963267949) + 1.0*Pc2y*q1d*sin(q2 + 1.5707963267949))*sin(q2 + 1.5707963267949) + (6.12323399573677e-17*q1d + 1.0*q2d)*(-Pc2y*(6.12323399573677e-17*q1d + 1.0*q2d) + 1.0*Pc2z*q1d*cos(q2 + 1.5707963267949))) + 1.0*q1d*(-1.0*Ic2xz*q1d*sin(q2 + 1.5707963267949) - 1.0*Ic2yz*q1d*cos(q2 + 1.5707963267949) + Ic2zz*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q2 + 1.5707963267949) - (6.12323399573677e-17*q1d + 1.0*q2d)*(-1.0*Ic2xy*q1d*sin(q2 + 1.5707963267949) + 1.0*Ic2yy*q1d*cos(q2 + 1.5707963267949) - Ic2yz*(6.12323399573677e-17*q1d + 1.0*q2d)) + (Ic3xx*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) - Ic3xy*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + Pc3y*m3*(-Pc3x*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + Pc3y*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*q1d*(5.510910815147e-18*q1d + 0.0900000035762787*q2d)*sin(q2 + 1.5707963267949) + (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) - Pc3z*m3*(-Pc3z*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*pow(q1d, 2)*sin(q2 + 1.5707963267949)*cos(q3)*cos(q2 + 1.5707963267949) - (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q3)) + (-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))*(-Ic3xz*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - Ic3yz*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Ic3zz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)) - (6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)*(-Ic3xy*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + Ic3yy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3yz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)))*cos(q3) - (-Ic3xy*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + Ic3yy*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) - Pc3x*m3*(-Pc3x*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + Pc3y*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*q1d*(5.510910815147e-18*q1d + 0.0900000035762787*q2d)*sin(q2 + 1.5707963267949) + (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + Pc3z*m3*(Pc3z*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 0.0900000035762787*pow(q1d, 2)*sin(q3)*sin(q2 + 1.5707963267949)*cos(q2 + 1.5707963267949) + (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q3)) - (1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))*(-Ic3xz*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - Ic3yz*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Ic3zz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)) + (6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)*(Ic3xx*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - Ic3xy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3xz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)))*sin(q3))*sin(q2 + 1.5707963267949) + 1.0*(-1.0*Ic2xy*q1d*q2d*cos(q2 + 1.5707963267949) - 1.0*Ic2yy*q1d*q2d*sin(q2 + 1.5707963267949) - Pc2x*m2*(1.0*Pc2x*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*Pc2y*q1d*q2d*cos(q2 + 1.5707963267949) + 1.0*q1d*(Pc2x*(6.12323399573677e-17*q1d + 1.0*q2d) - 1.0*Pc2z*q1d*sin(q2 + 1.5707963267949))*sin(q2 + 1.5707963267949) - 1.0*q1d*(-Pc2y*(6.12323399573677e-17*q1d + 1.0*q2d) + 1.0*Pc2z*q1d*cos(q2 + 1.5707963267949))*cos(q2 + 1.5707963267949)) + Pc2z*m2*(-1.0*Pc2z*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*q1d*(-1.0*Pc2x*q1d*cos(q2 + 1.5707963267949) + 1.0*Pc2y*q1d*sin(q2 + 1.5707963267949))*cos(q2 + 1.5707963267949) - (6.12323399573677e-17*q1d + 1.0*q2d)*(Pc2x*(6.12323399573677e-17*q1d + 1.0*q2d) - 1.0*Pc2z*q1d*sin(q2 + 1.5707963267949))) - 0.0900000035762787*m3*(-Pc3x*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + Pc3y*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*q1d*(5.510910815147e-18*q1d + 0.0900000035762787*q2d)*sin(q2 + 1.5707963267949) + (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) - 1.0*q1d*(-1.0*Ic2xz*q1d*sin(q2 + 1.5707963267949) - 1.0*Ic2yz*q1d*cos(q2 + 1.5707963267949) + Ic2zz*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q2 + 1.5707963267949) + (6.12323399573677e-17*q1d + 1.0*q2d)*(1.0*Ic2xx*q1d*sin(q2 + 1.5707963267949) - 1.0*Ic2xy*q1d*cos(q2 + 1.5707963267949) - Ic2xz*(6.12323399573677e-17*q1d + 1.0*q2d)) + (Ic3xx*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) - Ic3xy*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + Pc3y*m3*(-Pc3x*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + Pc3y*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*q1d*(5.510910815147e-18*q1d + 0.0900000035762787*q2d)*sin(q2 + 1.5707963267949) + (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) - Pc3z*m3*(-Pc3z*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*pow(q1d, 2)*sin(q2 + 1.5707963267949)*cos(q3)*cos(q2 + 1.5707963267949) - (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q3)) + (-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))*(-Ic3xz*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - Ic3yz*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Ic3zz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)) - (6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)*(-Ic3xy*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + Ic3yy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3yz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)))*sin(q3) + (-Ic3xy*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + Ic3yy*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) - Pc3x*m3*(-Pc3x*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + Pc3y*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*q1d*(5.510910815147e-18*q1d + 0.0900000035762787*q2d)*sin(q2 + 1.5707963267949) + (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + Pc3z*m3*(Pc3z*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 0.0900000035762787*pow(q1d, 2)*sin(q3)*sin(q2 + 1.5707963267949)*cos(q2 + 1.5707963267949) + (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q3)) - (1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))*(-Ic3xz*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - Ic3yz*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Ic3zz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)) + (6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)*(Ic3xx*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - Ic3xy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3xz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)))*cos(q3))*cos(q2 + 1.5707963267949);
	V[1] = -1.0*Ic2xz*q1d*q2d*cos(q2 + 1.5707963267949) + 1.0*Ic2yz*q1d*q2d*sin(q2 + 1.5707963267949) - 1.0*Ic3xz*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) - 1.0*Ic3yz*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 1.0*Pc2x*m2*(-1.0*Pc2z*q1d*q2d*cos(q2 + 1.5707963267949) - 1.0*q1d*(-1.0*Pc2x*q1d*cos(q2 + 1.5707963267949) + 1.0*Pc2y*q1d*sin(q2 + 1.5707963267949))*sin(q2 + 1.5707963267949) + (6.12323399573677e-17*q1d + 1.0*q2d)*(-Pc2y*(6.12323399573677e-17*q1d + 1.0*q2d) + 1.0*Pc2z*q1d*cos(q2 + 1.5707963267949))) - 1.0*Pc2y*m2*(-1.0*Pc2z*q1d*q2d*sin(q2 + 1.5707963267949) + 1.0*q1d*(-1.0*Pc2x*q1d*cos(q2 + 1.5707963267949) + 1.0*Pc2y*q1d*sin(q2 + 1.5707963267949))*cos(q2 + 1.5707963267949) - (6.12323399573677e-17*q1d + 1.0*q2d)*(Pc2x*(6.12323399573677e-17*q1d + 1.0*q2d) - 1.0*Pc2z*q1d*sin(q2 + 1.5707963267949))) + 1.0*Pc3x*m3*(-Pc3z*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*pow(q1d, 2)*sin(q2 + 1.5707963267949)*cos(q3)*cos(q2 + 1.5707963267949) - (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q3)) - 1.0*Pc3y*m3*(Pc3z*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 0.0900000035762787*pow(q1d, 2)*sin(q3)*sin(q2 + 1.5707963267949)*cos(q2 + 1.5707963267949) + (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q3)) + 0.0900000035762787*m3*(-Pc3z*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*pow(q1d, 2)*sin(q2 + 1.5707963267949)*cos(q3)*cos(q2 + 1.5707963267949) - (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q3))*cos(q3) + 0.0900000035762787*m3*(Pc3z*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 0.0900000035762787*pow(q1d, 2)*sin(q3)*sin(q2 + 1.5707963267949)*cos(q2 + 1.5707963267949) + (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q3))*sin(q3) - 1.0*q1d*(1.0*Ic2xx*q1d*sin(q2 + 1.5707963267949) - 1.0*Ic2xy*q1d*cos(q2 + 1.5707963267949) - Ic2xz*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q2 + 1.5707963267949) + 1.0*q1d*(-1.0*Ic2xy*q1d*sin(q2 + 1.5707963267949) + 1.0*Ic2yy*q1d*cos(q2 + 1.5707963267949) - Ic2yz*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q2 + 1.5707963267949) - 1.0*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))*(Ic3xx*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - Ic3xy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3xz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)) + 1.0*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))*(-Ic3xy*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + Ic3yy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3yz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d));
	V[2] = -1.0*Ic3xz*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) - 1.0*Ic3yz*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 1.0*Pc3x*m3*(-Pc3z*(-1.0*q1d*q2d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*q2d*cos(q3)*cos(q2 + 1.5707963267949) + 1.0*q3d*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))) + 0.0900000035762787*pow(q1d, 2)*sin(q2 + 1.5707963267949)*cos(q3)*cos(q2 + 1.5707963267949) - (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + (-Pc3y*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + Pc3z*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*sin(q3)) - 1.0*Pc3y*m3*(Pc3z*(-1.0*q1d*q2d*sin(q3)*cos(q2 + 1.5707963267949) - 1.0*q1d*q2d*sin(q2 + 1.5707963267949)*cos(q3) - 1.0*q3d*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))) + 0.0900000035762787*pow(q1d, 2)*sin(q3)*sin(q2 + 1.5707963267949)*cos(q2 + 1.5707963267949) + (-Pc3x*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) + Pc3y*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - (Pc3x*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) - Pc3z*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)))*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d) + (-0.0900000035762787*pow(q1d, 2)*pow(cos(q2 + 1.5707963267949), 2) - (5.510910815147e-18*q1d + 0.0900000035762787*q2d)*(6.12323399573677e-17*q1d + 1.0*q2d))*cos(q3)) - 1.0*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949))*(Ic3xx*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) - Ic3xy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3xz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d)) + 1.0*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3))*(-Ic3xy*(1.0*q1d*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*q1d*sin(q2 + 1.5707963267949)*cos(q3)) + Ic3yy*(-1.0*q1d*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*q1d*cos(q3)*cos(q2 + 1.5707963267949)) - Ic3yz*(6.12323399573677e-17*q1d + 1.0*q2d + 1.0*q3d));

	return V;
}