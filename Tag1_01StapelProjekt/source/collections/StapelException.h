//
// Created by JoachimWagner on 05.06.2023.
//

#pragma once


#include <exception>

class StapelException: public std::exception {
public:
    StapelException() {}

    explicit StapelException(const char *const message) : exception(message) {}
};
