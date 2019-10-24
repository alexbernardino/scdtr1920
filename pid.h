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
    explicit pid(float kp, float ki = 0,
              float kd = 0, float T = 1, float a = 10);
    ~pid();
    void print();
    float calc(float error);
    float calc(float ref, float y);
};

#endif  //PID_H
