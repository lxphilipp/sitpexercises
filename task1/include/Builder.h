#ifndef BUILDER_H
#define BUILDER_H

#include "Rectangle.h"

class RectangleBuilder {
private:
    Rectangle rect;

public:
    RectangleBuilder() = default;

    RectangleBuilder& upperRightCorner(float x, float y) {
        rect.maxx = x;
        rect.maxy = y;
        return *this;
    }

    RectangleBuilder& lowerLeftCorner(float x, float y) {
        rect.minx = x;
        rect.miny = y;
        return *this;
    }

    RectangleBuilder& width(float w) {
        rect.maxx = rect.minx + w;
        return *this;
    }

    RectangleBuilder& height(float h) {
        rect.maxy = rect.miny + h;
        return *this;
    }

    Rectangle build() {
        return rect;
    }
};

#endif // BUILDER_H
