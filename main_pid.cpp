//
// Created by Alexandre Bernardino on 20/10/2019.
//

#include "pid.h"
#include <iostream>
using namespace std;
#include <cstdio>  //getchar

int main()
{
    // declare a local object
    pid c;
    // invoke object methods
    c.init(3,5,0,0.01,0);
    c.print();
    cout << c.calc(5,4) << endl;
    cout << c.calc(5,5) << endl;
    getchar(); // pause
} // obj is destroyed here.