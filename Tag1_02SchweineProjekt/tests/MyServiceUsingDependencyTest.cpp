//
// Created by JoachimWagner on 29.01.2024.
//

#include "MyServiceUsingDependencyTest.h"

TEST_F(MyServiceUsingDependencyTest, f_demo) {

    // Arrange
    // Recordmode

    EXPECT_CALL(dependencyMock, foo("HALLO")).Times(1);

    // Replay
    objectUnderTest.f("Hallo");

}

TEST_F(MyServiceUsingDependencyTest, g_demo) {

    // Arrange
    // Recordmode

    /*
    EXPECT_CALL(dependencyMock, bar())
        .WillOnce(Return(4711))
        .WillOnce(Return(815));
    */
    EXPECT_CALL(dependencyMock, bar()).Times(AtMost(2)).WillRepeatedly(Return(3));

    //EXPECT_CALL(dependencyMock, bar())
    //        .WillOnce(Throw(std::exception{"Upps"}));

    // Replay
    EXPECT_THAT(objectUnderTest.g(), Eq(9));


}

TEST_F(MyServiceUsingDependencyTest, demo_3) {

    // Recordmode
    EXPECT_CALL(dependencyMock, foobar("Hallo Welt")).WillOnce(Return(5));


    EXPECT_THAT(objectUnderTest.h("Hallo"), Eq(15));

}
