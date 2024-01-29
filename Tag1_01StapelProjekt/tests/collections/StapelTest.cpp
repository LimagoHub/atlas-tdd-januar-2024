//
// Created by JoachimWagner on 29.01.2024.
//

#include "StapelTest.h"

TEST_F(StapelTest, isEmpty__EmptyStack__returnsTrue) {
    // Arrange


    // Action
    auto result = objectUnderTest.isEmpty();

    // Assertion
    EXPECT_TRUE(result);

}
TEST_F(StapelTest, isEmpty__NotEmptyStack__returnsFalse) {
    // Arrange
    objectUnderTest.push(1);
    // Action
    // Assertion
    EXPECT_FALSE(objectUnderTest.isEmpty());
}

TEST_F(StapelTest, push__fillUpToLimit__noExceptionIsThrown){
    fillUpToLimitWithoutException();
}

TEST_F(StapelTest, push__Overflow__StapelExceptionIsThrown){
    fillUpToLimitWithoutException();
    EXPECT_THROW(objectUnderTest.push(1), StapelException);
}
TEST_F(StapelTest, push__Overflow__StapelExceptionIsThrown_variante){
    try {
        fillUpToLimitWithoutException();
        objectUnderTest.push(1);
        FAIL() << "Fehler: StapelException erwartet";
    }catch(const StapelException & ex) {
        EXPECT_STREQ("Overflow", ex.what());
    }
}

