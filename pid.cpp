//
// Created by Alexandre Bernardino on 20/10/2019.
//

#include "pid.h"
#include <iostream>
using namespace std;

pid::pid(float p, float i,
               float d, float _T, float _a)  {
    //warning: should check args
    cout<<"pid ctor"<<endl;
    ep = yp = ip = dp = 0.0f;
    k1=kp=p; ki=i; kd=d; T=_T; a=_a;
    k2=kp*ki*T/2;
    if (kd < 0.000001f)
        derivative = false;
    else {
        derivative = true;
        float den = kd+a*T;
        //warning: should check den
        k3=kd/den;
        k4=kp*kd*a/den;
    }
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
