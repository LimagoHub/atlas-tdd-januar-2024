//
// Created by JoachimWagner on 29.01.2024.
//

#pragma once


#include <algorithm>
#include "Multiplizierer.h"

class MultipliziererImpl : public Multiplizierer {

public:
    unsigned long mult(unsigned int a, unsigned int b) override{
        unsigned long retval = 0;


        for (unsigned int i = 0; i < a; ++i) {
            retval += b;
        }
        return retval;
    }

};
