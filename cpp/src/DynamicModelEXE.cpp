#include <Model.hpp>
#include <thread>
#include <atomic>
#include <mutex>

using namespace mahi::util;

Model model;
std::atomic_bool stop_;
double t;
double t_last;
VectorXd Qref = VectorXd::Zero(num_joints);
VectorXd Kp   = VectorXd::Constant(num_joints,0.05);
VectorXd Kd   = VectorXd::Constant(num_joints,0.003);
std::thread sim_thread;

void sim(){
    Timer sim_loop(1_ms);
    {
        while(!stop_){
            {
                std::mutex lock;
                model.m_s.Tau = Kp.asDiagonal()*(Qref-model.m_s.Q)-Kd.asDiagonal()*model.m_s.Qd;
                model.update(0.001);
            }
            t_last = t;
            t = sim_loop.wait().as_seconds();
        }
    }
}

void start(){
    model.zero();
    stop_ = false;
    sim_thread = std::thread(sim);
}

void stop(){
    {
        std::mutex lock;
        stop_ = true;
    }
    sim_thread.join();
}

void get_Q(double* Q){
    std::mutex lock;
    for (size_t i = 0; i < num_joints; i++)
    {
        Q[i] = model.m_s.Q[i];
    } 
}

void set_Tau(double* Tau){
    std::mutex lock;
    for (size_t i = 0; i < num_joints; i++)
    {
        model.m_s.Tau[i] = Tau[i];
    } 
}

void set_Qref(double* Qref_){
    std::mutex lock;
    for (size_t i = 0; i < num_joints; i++)
    {
        Qref[i] = Qref_[i];
    } 
}

int main(){
    double q[3] = {0,0,0};
    
    start();

    while(true){
        get_Q(q);
        std::cout << q[0] << ", " << q[1] << ", " << q[2] << std::endl;
    };
    stop();
    return 0;
}