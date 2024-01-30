//
// Created by JoachimWagner on 29.01.2024.
//

#pragma once
#include "Multiplizierer.h"

class MultipliziererOptimierer :public Multiplizierer{

    Multiplizierer &multiplizierer;

public:
    explicit MultipliziererOptimierer(Multiplizierer &multiplizierer) : multiplizierer(multiplizierer) {}

    unsigned long mult(unsigned int a, unsigned int b) override {
        if(a < b)
          return multiplizierer.mult(a,b);
        else
          return multiplizierer.mult(b,a);
    }
};
