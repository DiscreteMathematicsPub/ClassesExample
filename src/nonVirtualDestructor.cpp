/*
 * nonVirtualDestructor.cpp
 *
 *  Created on: 5 maig 2017
 *      Author: josep
 */

#include <iostream>
using namespace std;

// Example taken from http://www.studytonight.com/cpp/virtual-destructors.php

class BaseNoVirtual
{
 public:
 ~BaseNoVirtual() {cout << "Base Destructor\t" << endl; }
};

class DerivedNoVirtual:public BaseNoVirtual
{
 public:
 ~DerivedNoVirtual() { cout<< "Derived Destructor" << endl; }
};


