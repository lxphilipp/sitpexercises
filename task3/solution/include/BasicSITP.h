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
    
    template<typename Next>
    struct Step {
        ComplexObject& obj;
        explicit Step(ComplexObject& o) : obj(o) {}

    protected:
        Next next() {
            return Next(obj);
        }
    };

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

    // Einfacher Initialisierungspfad
    using SimpleInitializerTree = RLowerLeftCorner<RWidth<RHeight<Rectangle>>>;

    SimpleInitializerTree build() {
        return SimpleInitializerTree(object);
    }
};

#endif // BASIC_SITP_H