#pragma once

constexpr size_t num_joints = 3;

// Joint 1

constexpr double Ic1xx = 0.005309;
constexpr double Ic1xy = 0.000758;
constexpr double Ic1xz = 0.000687;
constexpr double Ic1yy = 0.008995;
constexpr double Ic1yz = 0.000368;
constexpr double Ic1zz = 0.010378;

constexpr double Pc1x = 0.022471;
constexpr double Pc1y = 0.040422;
constexpr double Pc1z = 0.115783;

constexpr double m1 = 1.792653;

// Joint 2

constexpr double Ic2xx = 0.003754;
constexpr double Ic2xy = 0.000527;
constexpr double Ic2xz = -7.1e-05;
constexpr double Ic2yy = 0.001519;
constexpr double Ic2yz = 0.000324;
constexpr double Ic2zz = 0.004516;

constexpr double Pc2x = -0.009454;
constexpr double Pc2y = -0.027149;
constexpr double Pc2z = -0.078162;

constexpr double m2 = 0.89143;

// Joint 3

constexpr double Ic3xx = 0.000419;
constexpr double Ic3xy = 2.6e-05;
constexpr double Ic3xz = 0.00014;
constexpr double Ic3yy = 0.00047;
constexpr double Ic3yz = 2.9e-05;
constexpr double Ic3zz = 0.000287;

constexpr double Pc3x = 0.049368;
constexpr double Pc3y = -0.021117;
constexpr double Pc3z = 0.060728;

constexpr double m3 = 0.192063;

constexpr double g =  9.80665000;