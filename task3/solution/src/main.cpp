#include <iostream>
#include "../include/BasicSITP.h"
#include "../include/AdvancedSITP.h"

void testBasicSITP() {
    SeqTreeBuilder<Rectangle> builder;

    // Test der Basis-Implementation
    Rectangle r = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400);

    std::cout << "Basic SITP Rectangle:\n"
              << "Position: (" << r.minx << "," << r.miny << ")\n"
              << "Size: " << (r.maxx - r.minx) << " x " << (r.maxy - r.miny) << "\n\n";
}

void testAdvancedSITP() {
    AdvancedSeqTreeBuilder<Rectangle> builder;

    // Test der ersten Reihenfolge: Position -> Breite -> Höhe
    Rectangle r1 = builder.build()
        .lowerLeftCorner(10, 20)
        .width(300)
        .height(400);

    // Test der alternativen Reihenfolge: Position -> Höhe -> Breite
    Rectangle r2 = builder.build()
        .lowerLeftCorner(10, 20)
        .height(400)
        .width(300);

    std::cout << "Advanced SITP Rectangles:\n"
              << "First order:\n"
              << "Position: (" << r1.minx << "," << r1.miny << ")\n"
              << "Size: " << (r1.maxx - r1.minx) << " x " << (r1.maxy - r1.miny) << "\n\n"
              << "Alternative order:\n"
              << "Position: (" << r2.minx << "," << r2.miny << ")\n"
              << "Size: " << (r2.maxx - r2.minx) << " x " << (r2.maxy - r2.miny) << "\n";
}

int main() {
    std::cout << "Testing Basic SITP:\n";
    testBasicSITP();

    std::cout << "Testing Advanced SITP:\n";
    testAdvancedSITP();

    return 0;
}