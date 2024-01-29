//
// Created by JoachimWagner on 29.01.2024.
//

#include <iostream>
#include "Stapel.h"
#include "StapelException.h"

Stapel::Stapel() {

}

auto Stapel::isEmpty() -> bool const {
    return index == 0;
}

auto Stapel::isFull() -> bool const {
    return index == 10;
}

auto Stapel::push(int value) -> void {
    if(isFull()) throw StapelException("Overflow");
    data[index ++] = value;
}

auto Stapel::pop() -> int {
    if(isEmpty()) throw StapelException("Underflow");
    return data[--index];
}
