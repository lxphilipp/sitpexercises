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
    
    // TODO: Testen Sie verschiedene Initialisierungspfade
    
    // Beispiel:
    RenderConfig config = builder.build()
        .setSize(1920, 1080)
        .setColorSpace("RGB")
        .setQuality(0.9f)
        .enableAntialiasing()
        .setOutputFormat("PNG")
        .addFilter("sharpen")
        .create();
        
    printConfig(config);
    
    return 0;
}