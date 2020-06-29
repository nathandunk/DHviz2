#include <Mahi/Robo.hpp>
#include <Mahi/Util.hpp>
#include <Params.hpp>
#include <Eigen/Dense>

using Eigen::VectorXd;
using Eigen::MatrixXd;

class Model{
public:
    // stores the state of the robot
    struct State{
        VectorXd Q;   // current position of the robot
        VectorXd Qd;  // current velocities of the robot
        VectorXd Qdd; // current accelerations of the robot
        VectorXd Tau; // current torque outputs of the robot
    };

    State m_s{VectorXd::Zero(num_joints), VectorXd::Zero(num_joints), VectorXd::Zero(num_joints), VectorXd::Zero(num_joints)}; // stores robot state

    /// Constructor
    Model();
    /// sets the zero conditions of the robot
    void zero();
    /// runs one iteration of the update rule, integrating forward in time
    void update(double dt);
    /// integrates the state of the robot according to the latest dt
    void integrate_state(VectorXd Qdd, double dt);
private:
    /// returns the vector of damping terms given the robot state
    VectorXd B();
    /// returns the vector of friction terms given the robot state
    VectorXd Fk();
};