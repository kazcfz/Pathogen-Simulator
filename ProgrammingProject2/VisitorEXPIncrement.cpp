#include <iostream>
#include "VisitorEXPIncrement.h"
#include "Virus.h"
#include "Bacteria.h"
#include "Fungus.h"
using namespace std;

// (VisitorEXPIncrement) Visit function for increasing pathogen EXP by 1
void VisitorEXPIncrement::Visit(Pathogen& aPathogen) { aPathogen.SetExpPoint(aPathogen.GetExpPoint() + 1); }
void VisitorEXPIncrement::Visit(Virus& aVirus) { aVirus.SetExpPoint(aVirus.GetExpPoint() + 1); }
void VisitorEXPIncrement::Visit(Bacteria& aBacteria) { aBacteria.SetExpPoint(aBacteria.GetExpPoint() + 1); }
void VisitorEXPIncrement::Visit(Fungus& aFungus) { aFungus.SetExpPoint(aFungus.GetExpPoint() + 1); }
