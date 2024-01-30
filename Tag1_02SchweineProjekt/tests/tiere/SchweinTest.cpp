//
// Created by JoachimWagner on 17.01.2024.
//

#include "SchweinTest.h"
const int MyInitialWeight = 10;
TEST_F(SchweinTest, ctor__default__correctInitialisation){
    std::string expectedValue = "Nobody";
    EXPECT_EQ(MyInitialWeight, objectUnderTest.getGewicht());
    EXPECT_THAT(objectUnderTest.getName(), Eq(expectedValue));
    EXPECT_EQ(objectUnderTest.getName(),expectedValue);
    EXPECT_EQ("Nobody", objectUnderTest.getName());
}

TEST_F(SchweinTest, ctor__overloaded_with_invalid_name__throwsInvalidArgument){
    try {
        const std::string invalidName = "Elsa";
        Schwein objectUnderTestLocal{invalidName};
        FAIL()<< "Upps";
    } catch (const std::invalid_argument &e) {
        EXPECT_STREQ("Name ist nicht erlaubt", e.what());
    }


}
TEST_F(SchweinTest, ctor__overloaded_with_valid_name__correctInitialisation){
    const std::string validName = "Piggy";
    Schwein objectUnderTestLocal{validName};
    EXPECT_EQ(10, objectUnderTestLocal.getGewicht());
    EXPECT_EQ(validName, objectUnderTestLocal.getName());
}
TEST_F(SchweinTest, setName__invalidName__throwsInvalidArgument){
    try {
        const std::string invalidName = "Elsa";
        objectUnderTest.setName(invalidName);
        FAIL()<< "Upps";
    } catch(const std::invalid_argument &ex){
        EXPECT_STREQ("Name ist nicht erlaubt", ex.what());
    }
}

TEST_F(SchweinTest, setName__validName__nameCorrectlySet){

        const std::string validName = "Piggy";
        EXPECT_NO_THROW(objectUnderTest.setName(validName));
        EXPECT_EQ("Piggy", objectUnderTest.getName());
}

TEST_F(SchweinTest, fuettern__happyDay__weightIncreasedByOne){

    const auto expectedResult = 11;
    objectUnderTest.fuettern();
    EXPECT_THAT( objectUnderTest.getGewicht(), Eq(expectedResult));
}
