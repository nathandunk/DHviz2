#include <Model.hpp>
#include <M.hpp>
#include <V.hpp>
#include <G.hpp>

// using namespace mahi::util;
using Eigen::VectorXd;
using Eigen::MatrixXd;

Model::Model(){
    zero();
}

void Model::update(double dt){
    
    MatrixXd a = get_M(m_s.Q);
    VectorXd b = m_s.Tau - get_V(m_s.Q, m_s.Qd) - get_G(m_s.Q) - B() - Fk();
    VectorXd Qdd = a.householderQr().solve(b);

    integrate_state(Qdd,dt);
}

void Model::integrate_state(VectorXd Qdd, double dt){
    
    VectorXd Qd  = m_s.Qd + dt * 0.5 * (m_s.Qdd + Qdd);
    VectorXd Q   = m_s.Q  + dt * 0.5 * (m_s.Qd  + Qd);
    m_s.Qdd = Qdd; m_s.Qd = Qd; m_s.Q = Q;
}

VectorXd Model::B(){
    VectorXd B = VectorXd::Zero(num_joints);

    constexpr double B_coeff = 0.0001;
    
    for (size_t i = 0; i < num_joints; i++){
        B[i] = B_coeff * m_s.Qd[i];
    }

    return B;
}

VectorXd Model::Fk(){
    VectorXd Fk = VectorXd::Zero(num_joints);

    constexpr double Fk_coeff = 0.001;

    for (size_t i = 0; i < num_joints; i++){
        Fk[i] = Fk_coeff*std::tanh(m_s.Qd[i]*10);
    }

    return Fk;
}

void Model::zero(){
    m_s.Q   = VectorXd::Zero(num_joints);
    m_s.Qd  = VectorXd::Zero(num_joints);
    m_s.Qdd = VectorXd::Zero(num_joints);
    m_s.Tau = VectorXd::Zero(num_joints);
}