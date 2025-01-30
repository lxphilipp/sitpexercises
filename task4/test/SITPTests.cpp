#ifndef TASK4_SITP_TESTS_H
#define TASK4_SITP_TESTS_H

#include <gtest/gtest.h>
#include "SITP.h"

class SITPTest : public ::testing::Test {
protected:
    SeqTreeBuilder<Rectangle> builder;
};

// Basis-Tests für einzelne Pfade

TEST_F(SITPTest, PathLowerWidthHeight) {
    Rectangle r = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400)
        .create();

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

TEST_F(SITPTest, PathLowerHeightWidth) {
    Rectangle r = builder.build()
        .lowerLeftCorner(10, 20)
        .height(400)
        .width(300)
        .create();

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

TEST_F(SITPTest, PathLowerUpper) {
    Rectangle r = builder.build()
        .lowerLeftCorner(10, 20)
        .upperRightCorner(310, 420)
        .create();

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

TEST_F(SITPTest, PathWidthLowerHeight) {
    Rectangle r = builder.build()
        .width(300)
        .lowerLeftCorner(10, 20)
        .height(400)
        .create();

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

TEST_F(SITPTest, PathWidthHeightLower) {
    Rectangle r = builder.build()
        .width(300)
        .height(400)
        .lowerLeftCorner(10, 20)
        .create();

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

TEST_F(SITPTest, PathHeightLowerWidth) {
    Rectangle r = builder.build()
        .height(400)
        .lowerLeftCorner(10, 20)
        .width(300)
        .create();

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

TEST_F(SITPTest, PathHeightWidthLower) {
    Rectangle r = builder.build()
        .height(400)
        .width(300)
        .lowerLeftCorner(10, 20)
        .create();

    EXPECT_FLOAT_EQ(r.minx, 10);
    EXPECT_FLOAT_EQ(r.miny, 20);
    EXPECT_FLOAT_EQ(r.maxx, 310);
    EXPECT_FLOAT_EQ(r.maxy, 420);
}

// Konsistenz-Tests

TEST_F(SITPTest, AllPathsProduceSameResult) {
    Rectangle r1 = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400)
        .create();

    Rectangle r2 = builder.build()
        .height(400)
        .width(300)
        .lowerLeftCorner(10, 20)
        .create();

    EXPECT_FLOAT_EQ(r1.minx, r2.minx);
    EXPECT_FLOAT_EQ(r1.miny, r2.miny);
    EXPECT_FLOAT_EQ(r1.maxx, r2.maxx);
    EXPECT_FLOAT_EQ(r1.maxy, r2.maxy);
}

#endif // TASK4_SITP_TESTS_H