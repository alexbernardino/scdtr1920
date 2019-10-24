//
// Created by Alexandre Bernardino on 20/10/2019.
//

#include "pid.h"
#include <iostream>
using namespace std;

pid::pid(float p, float i, float d, float _T, float _a)
: kp{p}, ki{i}, kd{d}, T {_T < 0 ? 1 : _T}, a{_a},
ep{0}, yp{0}, ip{0}, dp{0}, derivative{true}
{
    //warning: should check args
    cout<<"pid ctor 2"<<endl;
    k1 = kp;
    k2=kp*ki*T/2;
    if (kd < 0.000001f)
        derivative = false;
    else {
        float den = kd+a*T;
        //warning: should check den
        k3=kd/den;
        k4=kp*kd*a/den;
    }
}


float pid::calc(float e)
{
    //warning: code not optimized
    float p = k1*e;
    float i = ip + k2*(e+ep);
    ip = i; ep = e;
    return p+i;
}

float pid::calc(float ref, float y)
{
    //warning: code not optimized
    float e = ref - y;
    float p = k1*e;
    float i = ip + k2*(e+ep);
    float d = 0;
    if(derivative)
        d = k3*dp - k4*(y-yp);
    yp = y; ip = i; dp = d; ep = e;
    return p+i+d;
}

void pid::print() {
    cout << " kp: " << kp;
    cout << " ki: " << ki;
    cout << " kd: " << kd;
    cout << " T: " << T;
    cout << " a: " << a << endl;
}

pid::~pid() {
    cout<<"pid dtor"<<endl;
}
