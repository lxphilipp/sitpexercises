#ifndef TASK4_SITP_TESTS_H
#define TASK4_SITP_TESTS_H

#include <gtest/gtest.h>
#include "SITP.h"

class SITPTest : public ::testing::Test {
protected:
    SeqTreeBuilder<Rectangle> builder;
};

// Test für lowerLeftCorner -> upperRightCorner
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

// Test für lowerLeftCorner -> width -> height
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

// Test für width -> lowerLeftCorner -> height
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

// Test für Äquivalenz verschiedener Pfade
TEST_F(SITPTest, PathEquivalence) {
    Rectangle r1 = builder.build()
        .lowerLeftCorner(10, 20)
        .upperRightCorner(310, 420)
        .create();
        
    Rectangle r2 = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400)
        .create();
        
    EXPECT_FLOAT_EQ(r1.minx, r2.minx);
    EXPECT_FLOAT_EQ(r1.miny, r2.miny);
    EXPECT_FLOAT_EQ(r1.maxx, r2.maxx);
    EXPECT_FLOAT_EQ(r1.maxy, r2.maxy);
}

#endif // TASK4_SITP_TESTS_H#ifndef TASK4_SITP_TESTS_H
#define TASK4_SITP_TESTS_H

#include <gtest/gtest.h>
#include "SITP.h"

class SITPTest : public ::testing::Test {
protected:
    SeqTreeBuilder<Rectangle> builder;
};

// Test für lowerLeftCorner -> upperRightCorner
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

// Test für lowerLeftCorner -> width -> height
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

// Test für width -> lowerLeftCorner -> height
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

// Test für Äquivalenz verschiedener Pfade
TEST_F(SITPTest, PathEquivalence) {
    Rectangle r1 = builder.build()
        .lowerLeftCorner(10, 20)
        .upperRightCorner(310, 420)
        .create();

    Rectangle r2 = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400)
        .create();

    EXPECT_FLOAT_EQ(r1.minx, r2.minx);
    EXPECT_FLOAT_EQ(r1.miny, r2.miny);
    EXPECT_FLOAT_EQ(r1.maxx, r2.maxx);
    EXPECT_FLOAT_EQ(r1.maxy, r2.maxy);
}

#endif // TASK4_SITP_TESTS_H