//
// Created by JoachimWagner on 29.01.2024.
//

#pragma once
#include "MockDependency.h"
#include "../source/MyServiceUsingDependency.h"

using namespace testing;
class MyServiceUsingDependencyTest :public Test{

protected:
    MockDependency dependencyMock;
    MyServiceUsingDependency objectUnderTest{dependencyMock};

};
