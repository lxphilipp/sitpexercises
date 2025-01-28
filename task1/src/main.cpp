#include <iostream>
#include "Builder.h"
#include "SITP.h"

int main() {
    // Beispiel für Builder Pattern
    Rectangle r1 = RectangleBuilder()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400)
        .build();

    // TODO: Implementieren Sie hier die SITP-Variante
    // SeqTreeBuilder<Rectangle> builder;
    // Rectangle r2 = builder.build()...

    return 0;
}
