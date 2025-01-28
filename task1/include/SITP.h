#ifndef SITP_H
#define SITP_H

#include "Rectangle.h"

template<typename ComplexObject>
class SeqTreeBuilder {
private:
    ComplexObject object;

public:
    SeqTreeBuilder() = default;

    template<typename Next>
    struct Step {
        ComplexObject& obj;
        explicit Step(ComplexObject& o) : obj(o) {}
        
    protected:
        Next next() { return Next(obj); }
    };

    // TODO: Implementieren Sie die konkreten Schrittklassen
    // für upperRightCorner, lowerLeftCorner, width, height
    
    // TODO: Implementieren Sie die XOR-Klasse für alternative Pfade
    
    // TODO: Definieren Sie die Initialisierungspfade
};

#endif // SITP_H
