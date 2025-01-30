#include <iostream>
#include "SITP.h"

void printRectangle(const Rectangle& r) {
    std::cout << "Rectangle: (" << r.minx << "," << r.miny << ") to (" 
              << r.maxx << "," << r.maxy << ")\n";
}

int main() {
    SeqTreeBuilder<Rectangle> builder;
    
    std::cout << "Testing different initialization paths:\n\n";

    // Pfad 1: lowerLeftCorner -> width -> height
    std::cout << "Path 1: lowerLeftCorner -> width -> height\n";
    Rectangle r1 = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400)
        .create();
    printRectangle(r1);
    
    // Pfad 2: lowerLeftCorner -> height -> width
    std::cout << "\nPath 2: lowerLeftCorner -> height -> width\n";
    Rectangle r2 = builder.build()
        .lowerLeftCorner(10, 20)
        .height(400)
        .width(300)
        .create();
    printRectangle(r2);
    
    // Pfad 3: lowerLeftCorner -> upperRightCorner
    std::cout << "\nPath 3: lowerLeftCorner -> upperRightCorner\n";
    Rectangle r3 = builder.build()
        .lowerLeftCorner(10, 20)
        .upperRightCorner(310, 420)
        .create();
    printRectangle(r3);
    
    // Pfad 4: width -> lowerLeftCorner -> height
    std::cout << "\nPath 4: width -> lowerLeftCorner -> height\n";
    Rectangle r4 = builder.build()
        .width(300)
        .lowerLeftCorner(10, 20)
        .height(400)
        .create();
    printRectangle(r4);
    
    // Pfad 5: width -> height -> lowerLeftCorner
    std::cout << "\nPath 5: width -> height -> lowerLeftCorner\n";
    Rectangle r5 = builder.build()
        .width(300)
        .height(400)
        .lowerLeftCorner(10, 20)
        .create();
    printRectangle(r5);

    // Pfad 6: height -> lowerLeftCorner -> width
    std::cout << "\nPath 6: height -> lowerLeftCorner -> width\n";
    Rectangle r6 = builder.build()
        .height(400)
        .lowerLeftCorner(10, 20)
        .width(300)
        .create();
    printRectangle(r6);

    // Pfad 7: height -> width -> lowerLeftCorner
    std::cout << "\nPath 7: height -> width -> lowerLeftCorner\n";
    Rectangle r7 = builder.build()
        .height(400)
        .width(300)
        .lowerLeftCorner(10, 20)
        .create();
    printRectangle(r7);
    
    return 0;
}