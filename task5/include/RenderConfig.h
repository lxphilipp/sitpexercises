#ifndef TASK5_RENDERCONFIG_H
#define TASK5_RENDERCONFIG_H

#include <string>
#include <vector>

struct RenderConfig {
    // Bildgröße
    int width{};
    int height{};
    
    // Farbraum (RGB, CMYK)
    std::string colorSpace{};
    
    // Qualitätseinstellungen
    float quality{};
    
    // Ausgabeformat
    std::string outputFormat{};
    
    // Kantenglättung
    bool useAntialiasing{};
    
    // Nachbearbeitungsfilter
    std::vector<std::string> filters{};
};

#endif // TASK5_RENDERCONFIG_H