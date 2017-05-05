/*
 * VirtualDestructor.cpp
 *
 *  Created on: 5 maig 2017
 *      Author: josep
 */


#include <iostream>
using namespace std;

// Example taken from http://www.studytonight.com/cpp/virtual-destructors.php

class Base
{
 public:
 virtual ~Base() {cout << "Base Destructor\t" << endl; }
};

class Derived:public Base
{
 public:
 ~Derived() { cout<< "Derived Destructor" << endl; }
};



