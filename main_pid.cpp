//
// Created by Alexandre Bernardino on 20/10/2019.
//

#include "pid.h"
#include <iostream>
using namespace std;
#include <cstdio>  //getchar

int main()
{
    {   //entering scope 1
        pid c1{3}; //use one argument constructor
        c1.print();
        cout << "#pid: " << c1.object_count() << endl;
        { //entering scope 2
            pid c2{3, 5, 0, 0.01, 0};
            c2.print();
            cout << "#pid: " << pid::object_count() << endl;
        } //exiting scope 2
        cout << "#pid: " << pid::object_count() << endl;
    }   //exiting scope 1
    cout << "#pid: " << pid::object_count() << endl;
    getchar(); // pause
} // obj is destroyed here.
