//
// Created by JoachimWagner on 29.01.2024.
//

#pragma once


class Stapel {
    int data[10];
    int index{0};

public:
    Stapel();
    auto push(int value)->void;
    auto pop()->int;

    auto isEmpty()->bool const;
    auto isFull()->bool const;
};
