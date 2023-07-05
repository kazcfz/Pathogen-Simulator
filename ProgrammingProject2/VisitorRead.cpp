#include <iostream>
#include "VisitorRead.h"
#include "Virus.h"
#include "Bacteria.h"
#include "Fungus.h"
using namespace std;

// (VisitorRead) Visit function for displaying pathogen stats
// Calls the Read() function accordingly
void VisitorRead::Visit(Pathogen& aPathogen) { aPathogen.Read(); }
void VisitorRead::Visit(Virus& aVirus) { aVirus.Read(); }
void VisitorRead::Visit(Bacteria& aBacteria) { aBacteria.Read(); }
void VisitorRead::Visit(Fungus& aFungus) { aFungus.Read(); }
