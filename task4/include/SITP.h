#ifndef TASK4_SITP_H
#define TASK4_SITP_H

struct Rectangle {
    float minx{}, miny{}, maxx{}, maxy{};
};

template<typename ComplexObject>
struct SeqTreeBuilder {
private:
    ComplexObject object;
    
public:
    SeqTreeBuilder() = default;
    
    // TODO: Implementieren Sie die Step-Klasse als Basisklasse für alle Schritte
    template<typename Next>
    struct Step;

    // TODO: Implementieren Sie die XOR-Struktur für alternative Pfade
    template<typename ... Next>
    struct Xor;

    // TODO: Implementieren Sie alle notwendigen Schrittklassen:
    // - RLowerLeftCorner
    // - RUpperRightCorner  
    // - RWidth
    // - RHeight
    // - RCreate

    // TODO: Definieren Sie den vollständigen Initialisierungsbaum mit mehreren Pfaden
    // Dieser sollte alle möglichen sinnvollen Initialisierungsvarianten abdecken
    using SequentialInitializerTree = /* Ihre Implementation */;

    SequentialInitializerTree build() {
        return SequentialInitializerTree(object);
    }
};

#endif // TASK4_SITP_H