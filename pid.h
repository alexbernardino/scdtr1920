//
// Created by Alexandre Bernardino on 20/10/2019.
//

#ifndef PID_H
#define PID_H
#include <iostream>
using namespace std;
class pid  {
    bool derivative;
    float kp, ki, kd, T, a;
    float k1, k2, k3, k4;
    float ep, yp, ip, dp;
public:
    pid() = delete;
    explicit pid(float p)
    : kp{p}, k1{p}, ki{0}, kd{0}, k2{0}, k3{0}, k4{0},
      T{0}, a{0}, ep{0}, yp{0}, ip{0}, dp{0},
      derivative{false}
    {
        //warning: should check args
        cout<<"pid ctor 2"<<endl;
    }
    pid(float kp, float ki,
              float kd, float T, float a);
    ~pid();
    void print();
    float calc(float error);
    float calc(float ref, float y);
};

#endif  //PID_H
