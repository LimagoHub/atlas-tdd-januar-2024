//
// Created by JoachimWagner on 29.01.2024.
//

#pragma once
#include "Dependency.h"

class OtherDEpendecyImpl: public Dependency{
public:
    OtherDEpendecyImpl() {}

    void foo(std::string message) const override {

    }

    int bar() const override {
        return 0;
    }

    int foobar(std::string message) const override {
        return 0;
    }
};
