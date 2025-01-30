#ifndef TASK5_RENDERCONFIG_BUILDER_H
#define TASK5_RENDERCONFIG_BUILDER_H

#include <algorithm>
#include "RenderConfig.h"

template<typename ComplexObject>
struct RenderConfigBuilder {
private:
    ComplexObject object;
    
public:
    RenderConfigBuilder() = default;

    // Basis Step-Klasse
    template<typename Next>
    struct Step {
        ComplexObject& obj;
        explicit Step(ComplexObject& o) : obj(o) {}
        
    protected:
        Next next() { return Next(obj); }
    };

    // Step 1: Bildgröße muss zuerst gesetzt werden
    template<typename Next>
    struct ImageSize : public Step<Next> {
        explicit ImageSize(ComplexObject& o) : Step<Next>(o) {}
        
        Next setSize(int width, int height) {
            // Validierung: Mindestgröße 1x1
            this->obj.width = std::max(1, width);
            this->obj.height = std::max(1, height);
            return this->next();
        }
    };

    // Step 2A: Direkter Farbraum
    template<typename Next>
    struct ColorSpace : public Step<Next> {
        explicit ColorSpace(ComplexObject& o) : Step<Next>(o) {}
        
        Next setColorSpace(const std::string& space) {
            // Nur valide Farbräume erlauben
            if(space == "RGB" || space == "CMYK") {
                this->obj.colorSpace = space;
            } else {
                this->obj.colorSpace = "RGB"; // Default
            }
            return this->next();
        }
    };

    // Step 2B: Farbraum über Profil
    template<typename Next>
    struct ColorProfile : public Step<Next> {
        explicit ColorProfile(ComplexObject& o) : Step<Next>(o) {}
        
        Next setColorProfile(const std::string& profile) {
            // Profile zu Farbraum konvertieren
            if(profile == "sRGB") {
                this->obj.colorSpace = "RGB";
            } else if(profile == "USWebCoated") {
                this->obj.colorSpace = "CMYK";
            } else {
                this->obj.colorSpace = "RGB"; // Default
            }
            return this->next();
        }
    };

    // Step 3A: Qualitätseinstellungen
    template<typename Next>
    struct Quality : public Step<Next> {
        explicit Quality(ComplexObject& o) : Step<Next>(o) {}
        
        Next setQuality(float q) {
            // Qualität auf 0.0-1.0 beschränken
            this->obj.quality = std::clamp(q, 0.0f, 1.0f);
            return this->next();
        }
    };

    // Step 3B: Antialiasing
    template<typename Next>
    struct Antialiasing : public Step<Next> {
        explicit Antialiasing(ComplexObject& o) : Step<Next>(o) {}
        
        Next enableAntialiasing(bool enable = true) {
            this->obj.useAntialiasing = enable;
            return this->next();
        }
    };

    // Step 4: Ausgabeformat
    template<typename Next>
    struct OutputFormat : public Step<Next> {
        explicit OutputFormat(ComplexObject& o) : Step<Next>(o) {}
        
        Next setOutputFormat(const std::string& format) {
            this->obj.outputFormat = format;
            // Filter basierend auf Format zurücksetzen
            this->obj.filters.clear();
            return this->next();
        }
    };

    // Step 5: Filter basierend auf Format
    template<typename Next>
    struct Filters : public Step<Next> {
        explicit Filters(ComplexObject& o) : Step<Next>(o) {}
        
        Next addFilter(const std::string& filter) {
            // Validierung der Filter basierend auf Format
            if(this->obj.outputFormat == "PNG") {
                if(filter == "sharpen" || filter == "denoise") {
                    this->obj.filters.push_back(filter);
                }
            } else if(this->obj.outputFormat == "JPEG") {
                if(filter == "compression") {
                    this->obj.filters.push_back(filter);
                }
            }
            return this->next();
        }
    };

    // Final Step
    template<typename Next>
    struct Create : public Step<Next> {
        explicit Create(ComplexObject& o) : Step<Next>(o) {}
        
        ComplexObject create() {
            return this->obj;
        }
    };

    // Xor für alternative Pfade
    template<typename ... Next>
    struct Xor : public Next ... {
        explicit Xor(ComplexObject& o) : Next(o)... {}
    };

    // Definition des vollständigen Initialisierungsbaums
    using RenderConfigTree = 
        ImageSize<
            Xor<
                ColorSpace<
                    Xor<
                        Quality<Antialiasing<OutputFormat<Filters<Create<RenderConfig>>>>>,
                        Antialiasing<Quality<OutputFormat<Filters<Create<RenderConfig>>>>>
                    >
                >,
                ColorProfile<
                    Xor<
                        Quality<Antialiasing<OutputFormat<Filters<Create<RenderConfig>>>>>,
                        Antialiasing<Quality<OutputFormat<Filters<Create<RenderConfig>>>>>
                    >
                >
            >
        >;
    RenderConfigTree build() {
        return RenderConfigTree(object);
    }
};

#endif // TASK5_RENDERCONFIG_BUILDER_H