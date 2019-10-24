//
// Created by Alexandre Bernardino on 20/10/2019.
//

#include "pid.h"
#include <iostream>
using namespace std;
#include <cstdio>  //getchar

int main()
{
    {
        // declare a local objects and initialize
        pid c1{3}; //use one argument constructor
        c1.print();
        pid c2{3, 5, 0, 0.01, 0}; //use five argument constructor
        c2.print();
    }
    getchar(); // pause
} // obj is destroyed here.
