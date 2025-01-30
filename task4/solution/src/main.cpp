#include <iostream>
#include "SITP.h"

void printRectangle(const Rectangle& r) {
    std::cout << "Rectangle: (" << r.minx << "," << r.miny << ") to (" 
              << r.maxx << "," << r.maxy << ")\n";
}

int main() {
    SeqTreeBuilder<Rectangle> builder;
    
    // Pfad 1: lowerLeftCorner -> upperRightCorner
    std::cout << "Path 1: lowerLeftCorner -> upperRightCorner\n";
    Rectangle r1 = builder.build()
        .lowerLeftCorner(10, 20)
        .upperRightCorner(310, 420)
        .create();
    printRectangle(r1);
    
    // Pfad 2: lowerLeftCorner -> width -> height
    std::cout << "\nPath 2: lowerLeftCorner -> width -> height\n";
    Rectangle r2 = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400)
        .create();
    printRectangle(r2);
    
    // Pfad 3: width -> lowerLeftCorner -> height
    std::cout << "\nPath 3: width -> lowerLeftCorner -> height\n";
    Rectangle r3 = builder.build()
        .width(300)
        .lowerLeftCorner(10, 20)
        .height(400)
        .create();
    printRectangle(r3);
    
    return 0;
}