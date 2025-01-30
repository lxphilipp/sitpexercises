#ifndef SITP_H
#define SITP_H

#include "Rectangle.h"

#include <iostream>

//Builder for the Sequential Initializer Tree
template<typename ComplexObject>
struct SeqTreeBuilder {
private:
    ComplexObject object;
public:
    SeqTreeBuilder() = default;

    // Template of the Xor-Node
    // using multiple inheritance
    template<typename ... Next>
    struct Xor : public Next ...{
        explicit Xor(ComplexObject& o) : Next(o)...{}
    };

    // Template of the step node
    template<typename Next>
    struct Step {
        ComplexObject& obj;
        explicit Step(ComplexObject& o) : obj(o){};
    protected:
        Next next(){ return Next(obj); }
    };

    template<typename Next>
    struct RLowerLeftCorner : public Step<Next> {
        explicit RLowerLeftCorner(ComplexObject& o) : Step<Next>(o){};
        Next lowerLeftCorner(float x, float y) {
            this->obj.minx = x;
            this->obj.miny = y;
            return this->next();
        }
    };

    template<typename Next>
    struct RUpperRightCorner : public Step<Next> {
        explicit RUpperRightCorner(ComplexObject& o) : Step<Next>(o){};
        Next upperRightCorner(float x, float y) {
            this->obj.maxx = x;
            this->obj.maxy = y;
            return this->next();
        }
    };

    template<typename Next>
    struct RWidth : public Step<Next> {
        explicit RWidth(ComplexObject& o) : Step<Next>(o){};
        Next width(float w) {
            this->obj.maxx = this->obj.minx + w;
            return this->next();
        }
    };

    template<typename Next>
    struct RHeight : public Step<Next> {
        explicit RHeight(ComplexObject& o) : Step<Next>(o){};
        Next height(float h) {
            this->obj.maxy = this->obj.miny + h;
            return this->next();
        }
    };

    // optional: create node, whose only purpose is to
    // give feedback to the user,
    // that the initialization is finished
    template<typename Next>
    struct RCreate : public Step<Next> {
        explicit RCreate(ComplexObject& o) : Step<Next>(o){};
        Next create() {
            return this->next();
        }
    };
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

#endif // SITP_H