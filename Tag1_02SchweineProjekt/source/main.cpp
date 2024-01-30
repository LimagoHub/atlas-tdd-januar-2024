#include <iostream>

#include "DependencyImpl.h"
#include "OtherDEpendecyImpl.h"
#include "MyServiceUsingDependency.h"
#include "MultipliziererImpl.h"
#include "MultipliziererOptimierer.h"

class A {
public:
    virtual void foo() {
        std::cout << "Foo" << std::endl;
    }
};
class B : public A{

public:
    virtual void foo() {
        std::cout << "Extends" << std::endl;
    }
};



int main() {

    MultipliziererImpl impl;
    MultipliziererOptimierer optimierer{impl};





}