#ifndef TASK5_RENDERCONFIG_BUILDER_H
#define TASK5_RENDERCONFIG_BUILDER_H

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

    // TODO: Implementieren Sie die Schrittklassen entsprechend der Anforderungen:
    // 1. ImageSize muss zuerst gesetzt werden
    // 2. ColorSpace oder ColorProfile als Alternative
    // 3. Quality und Antialiasing in beliebiger Reihenfolge
    // 4. OutputFormat bestimmt verfügbare Filter
    
    // TODO: Definieren Sie den Initialisierungsbaum entsprechend der Abhängigkeiten
    using RenderConfigTree = /* Ihre Implementation */;

    RenderConfigTree build() {
        return RenderConfigTree(object);
    }
};

#endif // TASK5_RENDERCONFIG_BUILDER_H