//
// Created by JoachimWagner on 17.01.2024.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../../source/tiere/Schwein.h"
using namespace testing;
class SchweinTest :public Test{
protected:
    Schwein objectUnderTest;
};
