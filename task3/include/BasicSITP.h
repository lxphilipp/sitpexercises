#ifndef BASIC_SITP_H
#define BASIC_SITP_H

struct Rectangle {
    float minx{}, miny{}, maxx{}, maxy{};
};

template<typename ComplexObject>
struct SeqTreeBuilder {
private:
    ComplexObject object;
    
public:
    SeqTreeBuilder() = default;
    
    // TODO: Implementieren Sie die Step-Klasse
    template<typename Next>
    struct Step {
        ComplexObject& obj;
        explicit Step(ComplexObject& o) : obj(o) {}
        
        // TODO: Implementieren Sie die next()-Methode
        // Diese Methode soll das nächste Element in der 
        // Initialisierungskette zurückgeben
    };
    
    // TODO: Implementieren Sie die erste konkrete Schrittklasse
    template<typename Next>
    struct RLowerLeftCorner : public Step<Next> {
        explicit RLowerLeftCorner(ComplexObject& o) : Step<Next>(o) {}
        
        // TODO: Implementieren Sie die Methode lowerLeftCorner
        // Parameter: x, y vom Typ float
        // Rückgabe: Next-Objekt
    };

    // Definieren Sie einen einfachen Initialisierungspfad
    using SimpleInitializerTree = /* Ihre Implementation */;

    SimpleInitializerTree build() {
        return SimpleInitializerTree(object);
    }
};

#endif // BASIC_SITP_H