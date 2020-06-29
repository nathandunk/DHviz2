#pragma once

#include <Params.hpp>
#include <Mahi/Util.hpp>
#include <Eigen/Dense>

using namespace mahi::util;

Eigen::VectorXd get_G(const Eigen::VectorXd Qs){
	double q1 = Qs(0); double q2 = Qs(1); double q3 = Qs(2);

	Eigen::VectorXd G = Eigen::VectorXd::Zero(3); 

	G[0] = g*(6.12323399573677e-17*Pc2x*m2*cos(q2 + 1.5707963267949) - 6.12323399573677e-17*Pc2y*m2*sin(q2 + 1.5707963267949) + 6.12323399573677e-17*Pc3x*m3*(-1.0*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*cos(q3)*cos(q2 + 1.5707963267949)) - 6.12323399573677e-17*Pc3y*m3*(1.0*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*sin(q2 + 1.5707963267949)*cos(q3)) + 5.510910815147e-18*m3*(-1.0*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*cos(q3)*cos(q2 + 1.5707963267949))*cos(q3) + 5.510910815147e-18*m3*(1.0*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*sin(q2 + 1.5707963267949)*cos(q3))*sin(q3) + 1.0*(6.12323399573677e-17*Pc2y*m2 - 1.0*Pc2z*m2*cos(q2 + 1.5707963267949) - (-6.12323399573677e-17*Pc3x*m3 + Pc3z*m3*(1.0*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*sin(q2 + 1.5707963267949)*cos(q3)))*sin(q3) + (6.12323399573677e-17*Pc3y*m3 - Pc3z*m3*(-1.0*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*cos(q3)*cos(q2 + 1.5707963267949)))*cos(q3))*sin(q2 + 1.5707963267949) + 1.0*(-6.12323399573677e-17*Pc2x*m2 + 1.0*Pc2z*m2*sin(q2 + 1.5707963267949) - 5.510910815147e-18*m3 + (-6.12323399573677e-17*Pc3x*m3 + Pc3z*m3*(1.0*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*sin(q2 + 1.5707963267949)*cos(q3)))*cos(q3) + (6.12323399573677e-17*Pc3y*m3 - Pc3z*m3*(-1.0*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*cos(q3)*cos(q2 + 1.5707963267949)))*sin(q3))*cos(q2 + 1.5707963267949));
	G[1] = g*(1.0*Pc2x*m2*cos(q2 + 1.5707963267949) - 1.0*Pc2y*m2*sin(q2 + 1.5707963267949) + 1.0*Pc3x*m3*(-1.0*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*cos(q3)*cos(q2 + 1.5707963267949)) - 1.0*Pc3y*m3*(1.0*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*sin(q2 + 1.5707963267949)*cos(q3)) + 0.0900000035762787*m3*(-1.0*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*cos(q3)*cos(q2 + 1.5707963267949))*cos(q3) + 0.0900000035762787*m3*(1.0*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*sin(q2 + 1.5707963267949)*cos(q3))*sin(q3));
	G[2] = g*(1.0*Pc3x*m3*(-1.0*sin(q3)*sin(q2 + 1.5707963267949) + 1.0*cos(q3)*cos(q2 + 1.5707963267949)) - 1.0*Pc3y*m3*(1.0*sin(q3)*cos(q2 + 1.5707963267949) + 1.0*sin(q2 + 1.5707963267949)*cos(q3)));

	return G;
}