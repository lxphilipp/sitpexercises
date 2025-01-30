#include <gtest/gtest.h>
#include "../include/AdvancedSITP.h"

class AdvancedSITPTest : public ::testing::Test {
protected:
    AdvancedSeqTreeBuilder<Rectangle> builder;
};

TEST_F(AdvancedSITPTest, WidthHeightOrder) {
    Rectangle r = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400);

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

TEST_F(AdvancedSITPTest, HeightWidthOrder) {
    Rectangle r = builder.build()
        .lowerLeftCorner(10, 20)
        .height(400)
        .width(300);

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

TEST_F(AdvancedSITPTest, OrderEquivalence) {
    Rectangle r1 = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400);

    Rectangle r2 = builder.build()
        .lowerLeftCorner(10, 20)
        .height(400)
        .width(300);

    EXPECT_FLOAT_EQ(r1.minx, r2.minx);
    EXPECT_FLOAT_EQ(r1.miny, r2.miny);
    EXPECT_FLOAT_EQ(r1.maxx, r2.maxx);
    EXPECT_FLOAT_EQ(r1.maxy, r2.maxy);
}