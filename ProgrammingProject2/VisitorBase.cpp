#include <iostream>
#include "VisitorBase.h"
#include "Virus.h"
#include "Bacteria.h"
#include "Fungus.h"
using namespace std;

// Visitor interface
void VisitorBase::Visit(Pathogen& aPathogen) {}
void VisitorBase::Visit(Virus& aVirus) {}
void VisitorBase::Visit(Bacteria& aBacteria) {}
void VisitorBase::Visit(Fungus& aFungus) {}

void VisitorBase::Visit(EvolveTree& aEvolveTree) {}
