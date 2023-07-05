#pragma once
#include <iostream>
#include "VisitorBase.h"
#include "Pathogen.h"
using namespace std;

// Visit function for Devolving mutations
class VisitorDevolve : public VisitorBase
{
public:
	void Devolve(EvolveTree& aEvolveTree, string userinputdevolve, Pathogen& aPathogen);
	virtual void Visit(EvolveTree& aEvolveTree);
};
