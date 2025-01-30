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
    
    template<typename Next>
    struct Step {
        ComplexObject& obj;
        explicit Step(ComplexObject& o) : obj(o) {}
        
    protected:
        Next next() { return Next(obj); }
    };

    // XOR für alternative Pfade
    template<typename ... Next>
    struct Xor : public Next ... {
        explicit Xor(ComplexObject& o) : Next(o)... {}
    };

    // Schrittklassen
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
    struct RUpperRightCorner : public Step<Next> {
        explicit RUpperRightCorner(ComplexObject& o) : Step<Next>(o) {}
        
        Next upperRightCorner(float x, float y) {
            this->obj.maxx = x;
            this->obj.maxy = y;
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

    template<typename Next>
    struct RCreate : public Step<Next> {
        explicit RCreate(ComplexObject& o) : Step<Next>(o) {}
        
        ComplexObject create() {
            return this->obj;
        }
    };

    // Definition des Initialisierungsbaums
    using SequentialInitializerTree =
        Xor<
            RLowerLeftCorner<
                Xor<
                    RUpperRightCorner<RCreate<Rectangle>>,
                    RWidth<RHeight<RCreate<Rectangle>>>,
                    RHeight<RWidth<RCreate<Rectangle>>>
                >
            >,
            RWidth<
                Xor<
                    RLowerLeftCorner<RHeight<RCreate<Rectangle>>>,
                    RHeight<RLowerLeftCorner<RCreate<Rectangle>>>
                >
            >,
            RHeight<
                Xor<
                    RLowerLeftCorner<RWidth<RCreate<Rectangle>>>,
                    RWidth<RLowerLeftCorner<RCreate<Rectangle>>>
                >
            >
        >;

    SequentialInitializerTree build() {
        return SequentialInitializerTree(object);
    }
};

#endif // TASK4_SITP_H