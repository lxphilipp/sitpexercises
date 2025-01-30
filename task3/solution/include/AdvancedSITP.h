#ifndef ADVANCED_SITP_H
#define ADVANCED_SITP_H

#include "BasicSITP.h"

template<typename ComplexObject>
struct AdvancedSeqTreeBuilder {
private:
    ComplexObject object;
    
public:
    AdvancedSeqTreeBuilder() = default;

    // Step-Klasse von BasicSITP
    template<typename Next>
    struct Step {
        ComplexObject& obj;
        explicit Step(ComplexObject& o) : obj(o) {}

    protected:
        Next next() {
            return Next(obj);
        }
    };

    // XOR-Struktur
    template<typename ... Next>
    struct Xor : public Next ... {
        explicit Xor(ComplexObject& o) : Next(o)... {}
    };

    // Konkrete Schrittklassen wie in BasicSITP
    template<typename Next>
    struct RLowerLeftCorner : public Step<Next> {
        explicit RLowerLeftCorner(ComplexObject& o) : Step<Next>(o) {}

        Next lowerLeftCorner(float x, float y) {
             this->obj.minx = x;
            this->obj.miny = y;
            return this->next();
        }
    };

    template<typename Next>
    struct RWidth : public Step<Next> {
        explicit RWidth(ComplexObject& o) : Step<Next>(o) {}

        Next width(float w) {
            this->obj.maxx = this->obj.minx + w;
            return this->next();
        }
    };

    template<typename Next>
    struct RHeight : public Step<Next> {
        explicit RHeight(ComplexObject& o) : Step<Next>(o) {}

        Next height(float h) {
            this->obj.maxy = this->obj.miny + h;
            return this->next();
        }
    };

    // Erweiterter Initialisierungspfad mit Alternativen
    using AdvancedInitializerTree =
    RLowerLeftCorner<                    // Muss immer zuerst kommen
        Xor<
            RWidth<RHeight<Rectangle>>,   // Dann entweder Breite->Höhe
            RHeight<RWidth<Rectangle>>    // oder Höhe->Breite
        >
    >;

    AdvancedInitializerTree build() {
        return AdvancedInitializerTree(object);
    }
};

#endif // ADVANCED_SITP_H