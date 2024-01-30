//
// Created by JoachimWagner on 29.01.2024.
//

#include "StapelTest.h"

TEST_F(StapelTest, isEmptyBla) {
    EXPECT_TRUE(objectUnderTest.isEmpty());
}

TEST_F(StapelTest, isEmptyBlupp) {
    objectUnderTest.push(1);
    EXPECT_FALSE(objectUnderTest.isEmpty());
}

