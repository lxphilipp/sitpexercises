#include <gtest/gtest.h>
#include "../include/BasicSITP.h"

class BasicSITPTest : public ::testing::Test {
protected:
    SeqTreeBuilder<Rectangle> builder;
};

TEST_F(BasicSITPTest, CorrectInitialization) {
    Rectangle r = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400);

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

TEST_F(BasicSITPTest, CorrectDimensions) {
    Rectangle r = builder.build()
        .lowerLeftCorner(0, 0)
        .width(100)
        .height(50);

    EXPECT_FLOAT_EQ(r.maxx - r.minx, 100);
    EXPECT_FLOAT_EQ(r.maxy - r.miny, 50);
}