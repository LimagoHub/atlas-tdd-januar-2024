//
// Created by JoachimWagner on 17.01.2024.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../source/Dependency.h"

class MockDependency : public Dependency {
public:
    MOCK_METHOD(void, foo, (std::string message), (const, override));
    MOCK_METHOD(int, bar, (), (const, override));
    MOCK_METHOD(int, foobar, (std::string message), (const, override));
};