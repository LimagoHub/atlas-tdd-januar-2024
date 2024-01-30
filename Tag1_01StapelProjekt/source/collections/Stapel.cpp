//
// Created by JoachimWagner on 29.01.2024.
//

#include <iostream>
#include "Stapel.h"
#include "StapelException.h"

Stapel::Stapel() {

}

auto Stapel::isEmpty() -> bool const {
    return data.empty();
}

auto Stapel::isFull() -> bool const {
    return  data.size() >=10;
}

auto Stapel::push(int value) -> void {
    if(isFull()) throw StapelException("Overflow");
    data.emplace_back(value);
}

auto Stapel::pop() -> int {
    if(isEmpty()) throw StapelException("Underflow");
    auto retval = data.back();
    data.pop_back();
    return retval;
}
