#ifndef ADVANCED_SITP_H
#define ADVANCED_SITP_H

#include "BasicSITP.h"

template<typename ComplexObject>
struct AdvancedSeqTreeBuilder {
private:
    ComplexObject object;
    
public:
    AdvancedSeqTreeBuilder() = default;

    // Basis Step-Klasse von vorheriger Aufgabe übernehmen
    template<typename Next>
    struct Step;  // TODO: Implementation aus BasicSITP übernehmen

    // TODO: Implementieren Sie die XOR-Struktur
    template<typename ... Next>
    struct Xor : public Next ... {
        // TODO: Implementieren Sie den Konstruktor
        // Der Konstruktor soll die Referenz auf das komplexe Objekt
        // an alle Basisklassen weiterleiten
    };

    // TODO: Erweitern Sie den Initialisierungspfad um eine Alternative
    // Definition zweier alternativer Initialisierungspfade
    using AdvancedInitializerTree = /* Ihre Implementation mit Xor<...> */;

    AdvancedInitializerTree build() {
        return AdvancedInitializerTree(object);
    }
};

#endif // ADVANCED_SITP_H