#include <Model.hpp>
#include <thread>
#include <atomic>
#include <mutex>


#define DLL_EXPORT extern "C" __declspec(dllexport)

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
                // model.m_s.Tau = Kp.asDiagonal()*(Qref-model.m_s.Q)-Kd.asDiagonal()*model.m_s.Qd;
                model.m_s.Tau = VectorXd::Zero(3);
                model.update(0.001);
            }
            t_last = t;
            t = sim_loop.wait().as_seconds();
        }
    }
}

DLL_EXPORT void start(){
    model.zero();
    stop_ = false;
    sim_thread = std::thread(sim);
    // std::cout << "here";
}

DLL_EXPORT void stop(){
    {
        std::mutex lock;
        stop_ = true;
    }
    sim_thread.join();
}

DLL_EXPORT void get_Q(double* Q){
    std::mutex lock;
    for (size_t i = 0; i < num_joints; i++)
    {
        Q[i] = model.m_s.Q[i];
    } 
}

DLL_EXPORT void set_Tau(double* Tau){
    std::mutex lock;
    for (size_t i = 0; i < num_joints; i++)
    {
        model.m_s.Tau[i] = Tau[i];
    } 
}

DLL_EXPORT void set_Qref(double* Qref_){
    std::mutex lock;
    for (size_t i = 0; i < num_joints; i++)
    {
        Qref[i] = Qref_[i];
    } 
}