#pragma once

constexpr size_t num_joints = 3;

// Joint 1

constexpr double Ic1xx = 0.00031659;
constexpr double Ic1xy = -3.2e-07;
constexpr double Ic1xz = -2.6e-07;
constexpr double Ic1yy = 7.459e-05;
constexpr double Ic1yz = -2.138e-05;
constexpr double Ic1zz = 0.00028662;

constexpr double Pc1x = -6.629e-05;
constexpr double Pc1y = 0.02685796;
constexpr double Pc1z = 0.00341708;

constexpr double m1 = 0.23250015;

// Joint 2

constexpr double Ic2xx = 1.379e-05;
constexpr double Ic2xy = 0.0;
constexpr double Ic2xz = -7.28e-06;
constexpr double Ic2yy = 3.47e-05;
constexpr double Ic2yz = 0.0;
constexpr double Ic2zz = 2.156e-05;

constexpr double Pc2x = 0.06332032;
constexpr double Pc2y = 1.183e-05;
constexpr double Pc2z = -0.01300296;

constexpr double m2 = 0.02350003;

// Joint 3

constexpr double Ic3xx = 6.6e-07;
constexpr double Ic3xy = 0.0;
constexpr double Ic3xz = -1e-08;
constexpr double Ic3yy = 1.068e-05;
constexpr double Ic3yz = 0.0;
constexpr double Ic3zz = 1.043e-05;

constexpr double Pc3x = 0.03091769;
constexpr double Pc3y = 0.0;
constexpr double Pc3z = 2.952e-05;

constexpr double m3 = 0.011;

constexpr double g =  9.80665000;