#ifndef TASK5_RENDERCONFIG_TESTS_H
#define TASK5_RENDERCONFIG_TESTS_H

#include <gtest/gtest.h>
#include "RenderConfig.h"
#include "RenderConfigBuilder.h"

class RenderConfigTest : public ::testing::Test {
protected:
    RenderConfigBuilder<RenderConfig> builder;
};

// Test Pfad 1: setSize -> setColorSpace -> setQuality -> enableAntialiasing -> setOutputFormat -> addFilter -> create
TEST_F(RenderConfigTest, PathColorSpaceQualityAntialiasing) {
    auto config = builder.build()
        .setSize(1920, 1080)
        .setColorSpace("RGB")
        .setQuality(0.9f)
        .enableAntialiasing()
        .setOutputFormat("PNG")
        .addFilter("sharpen")
        .create();

    EXPECT_EQ(config.width, 1920);
    EXPECT_EQ(config.height, 1080);
    EXPECT_EQ(config.colorSpace, "RGB");
    EXPECT_FLOAT_EQ(config.quality, 0.9f);
    EXPECT_TRUE(config.useAntialiasing);
    EXPECT_EQ(config.outputFormat, "PNG");
    EXPECT_EQ(config.filters.size(), 1);
    EXPECT_EQ(config.filters[0], "sharpen");
}

// Test Pfad 2: setSize -> setColorSpace -> enableAntialiasing -> setQuality -> setOutputFormat -> addFilter -> create
TEST_F(RenderConfigTest, PathColorSpaceAntialiasingQuality) {
    auto config = builder.build()
        .setSize(1920, 1080)
        .setColorSpace("RGB")
        .enableAntialiasing()
        .setQuality(0.9f)
        .setOutputFormat("PNG")
        .addFilter("sharpen")
        .create();

    EXPECT_EQ(config.width, 1920);
    EXPECT_EQ(config.height, 1080);
    EXPECT_EQ(config.colorSpace, "RGB");
    EXPECT_FLOAT_EQ(config.quality, 0.9f);
    EXPECT_TRUE(config.useAntialiasing);
    EXPECT_EQ(config.outputFormat, "PNG");
    EXPECT_EQ(config.filters.size(), 1);
    EXPECT_EQ(config.filters[0], "sharpen");
}

// Test Pfad 3: setSize -> setColorProfile -> setQuality -> enableAntialiasing -> setOutputFormat -> addFilter -> create
TEST_F(RenderConfigTest, PathColorProfileQualityAntialiasing) {
    auto config = builder.build()
        .setSize(1920, 1080)
        .setColorProfile("USWebCoated")
        .setQuality(0.9f)
        .enableAntialiasing()
        .setOutputFormat("JPEG")
        .addFilter("compression")
        .create();

    EXPECT_EQ(config.width, 1920);
    EXPECT_EQ(config.height, 1080);
    EXPECT_EQ(config.colorSpace, "CMYK");
    EXPECT_FLOAT_EQ(config.quality, 0.9f);
    EXPECT_TRUE(config.useAntialiasing);
    EXPECT_EQ(config.outputFormat, "JPEG");
    EXPECT_EQ(config.filters.size(), 1);
    EXPECT_EQ(config.filters[0], "compression");
}

// Test Pfad 4: setSize -> setColorProfile -> enableAntialiasing -> setQuality -> setOutputFormat -> addFilter -> create
TEST_F(RenderConfigTest, PathColorProfileAntialiasingQuality) {
    auto config = builder.build()
        .setSize(1920, 1080)
        .setColorProfile("sRGB")
        .enableAntialiasing()
        .setQuality(0.9f)
        .setOutputFormat("PNG")
        .addFilter("denoise")
        .create();

    EXPECT_EQ(config.width, 1920);
    EXPECT_EQ(config.height, 1080);
    EXPECT_EQ(config.colorSpace, "RGB");
    EXPECT_FLOAT_EQ(config.quality, 0.9f);
    EXPECT_TRUE(config.useAntialiasing);
    EXPECT_EQ(config.outputFormat, "PNG");
    EXPECT_EQ(config.filters.size(), 1);
    EXPECT_EQ(config.filters[0], "denoise");
}

// Validierungstests für einzelne Komponenten
TEST_F(RenderConfigTest, SizeValidation) {
    auto config = builder.build()
        .setSize(0, -10)  // Ungültige Größe
        .setColorSpace("RGB")
        .setQuality(0.9f)
        .enableAntialiasing()
        .setOutputFormat("PNG")
        .addFilter("sharpen")
        .create();

    EXPECT_EQ(config.width, 1);
    EXPECT_EQ(config.height, 1);
}

TEST_F(RenderConfigTest, QualityValidation) {
    auto config = builder.build()
        .setSize(100, 100)
        .setColorSpace("RGB")
        .setQuality(1.5f)  // Ungültiger Wert
        .enableAntialiasing()
        .setOutputFormat("PNG")
        .addFilter("sharpen")
        .create();

    EXPECT_FLOAT_EQ(config.quality, 1.0f);
}

TEST_F(RenderConfigTest, InvalidColorSpaceDefaulting) {
    auto config = builder.build()
        .setSize(100, 100)
        .setColorSpace("InvalidSpace")  // Ungültiger Farbraum
        .setQuality(0.9f)
        .enableAntialiasing()
        .setOutputFormat("PNG")
        .addFilter("sharpen")
        .create();

    EXPECT_EQ(config.colorSpace, "RGB");  // Default zu RGB
}

#endif // TASK