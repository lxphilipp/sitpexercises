#include <iostream>
#include "RenderConfig.h"
#include "RenderConfigBuilder.h"

void printConfig(const RenderConfig& config) {
    std::cout << "Render Configuration:\n"
              << "Size: " << config.width << "x" << config.height << "\n"
              << "Color Space: " << config.colorSpace << "\n"
              << "Quality: " << config.quality << "\n"
              << "Output Format: " << config.outputFormat << "\n"
              << "Antialiasing: " << (config.useAntialiasing ? "On" : "Off") << "\n"
              << "Filters: ";
    for(const auto& filter : config.filters) {
        std::cout << filter << " ";
    }
    std::cout << "\n\n";
}

int main() {
    RenderConfigBuilder<RenderConfig> builder;
    
    // PNG mit RGB Farbraum
    RenderConfig config1 = builder.build()
        .setSize(1920, 1080)
        .setColorSpace("RGB")
        .setQuality(0.9f)
        .enableAntialiasing()
        .setOutputFormat("PNG")
        .addFilter("sharpen")
        .create();
    std::cout << "Configuration 1 (PNG/RGB):\n";
    printConfig(config1);

    // JPEG mit CMYK Farbraum über Profil
    RenderConfig config2 = builder.build()
        .setSize(800, 600)
        .setColorProfile("USWebCoated")
        .enableAntialiasing()
        .setQuality(0.8f)
        .setOutputFormat("JPEG")
        .addFilter("compression")
        .create();
    std::cout << "Configuration 2 (JPEG/CMYK):\n";
    printConfig(config2);

    // Test ungültiger Werte
    /*RenderConfig config3 = builder.build()
        .setSize(0, 0)
        .setColorSpace("InvalidSpace")
        .setQuality(1.5f)
        .setOutputFormat("PNG")
        .addFilter("invalid")
        .create();
    std::cout << "Configuration 3 (Invalid Values):\n";
    printConfig(config3);
    */
    return 0;
}