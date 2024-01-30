//
// Created by JoachimWagner on 29.01.2024.
//

#pragma once


class Stapel {
    bool empty{true};
public:
    bool isEmpty() {
        return empty;
    }

    void push(int value) {
        empty = false;
    }
};
