#include <iostream>
#include "VisitorDevolve.h"
using namespace std;

// (VisitorDevolve) Visit function for Devolving a mutation
void VisitorDevolve::Devolve(EvolveTree& aEvolveTree, string userinputdevolve, Pathogen& aPathogen)
{
	// Searches the Tree for a matching name
	if (!aEvolveTree.EmptyEvolution()) {	//checks if tree part is empty
		if (userinputdevolve == aEvolveTree.GetEvolveNode().GetName()) {	//checks if name matches
			if (aEvolveTree.GetEvolveNode().GetBought()) {	//checks if the mutation is already bought

				// Updates player's EXP, InfectivityLvl, LethalityLvl (from devolved mutations)
				aPathogen.SetExpPoint(aPathogen.GetExpPoint() + aEvolveTree.GetEvolveNode().GetCost());
				aPathogen.SetInfectivityLevel(aPathogen.GetInfectivityLevel() - aEvolveTree.GetEvolveNode().GetInfectivity());
				aPathogen.SetLethalityLevel(aPathogen.GetLethalityLevel() - aEvolveTree.GetEvolveNode().GetLethality());

				if (!aEvolveTree.LHS().EmptyEvolution())	//checks if left node is empty
					if (aEvolveTree.LHS().GetEvolveNode().GetBought())	//checks if it's bought
						VisitorDevolve::Devolve(aEvolveTree.LHS(), aEvolveTree.LHS().GetEvolveNode().GetName(), aPathogen);	//repeats the function with left node

				if (!aEvolveTree.RHS().EmptyEvolution())	//checks if right node is empty
					if (aEvolveTree.RHS().GetEvolveNode().GetBought())	//checks if it's bought
						VisitorDevolve::Devolve(aEvolveTree.RHS(), aEvolveTree.RHS().GetEvolveNode().GetName(), aPathogen);	//repeats the function with right node

				// Finally sets the node's Bought to false (devolved)
				aEvolveTree.GetEvolveNode().SetBought(false);
				cout << aPathogen.GetName() << " has successfully devolved " << userinputdevolve << endl;
			}
			// If mutation is not even bought
			else {
				cout << aPathogen.GetName() << " does not have " << aEvolveTree.GetEvolveNode().GetName() << endl;
			}
		}
		// If the name doesn't match
		else {
			// Pass Left node
			if (!aEvolveTree.LHS().EmptyEvolution())
				VisitorDevolve::Devolve(aEvolveTree.LHS(), userinputdevolve, aPathogen);
			// Pass Right node
			if (!aEvolveTree.RHS().EmptyEvolution())
				VisitorDevolve::Devolve(aEvolveTree.RHS(), userinputdevolve, aPathogen);
		}
	}
}

// (VisitorDevolve) Visit function for Devolving mutations
void VisitorDevolve::Visit(EvolveTree& aEvolveTree)
{
	// Gets user input on what to devolve
	string userinputdevolve;
	cout << "Enter devolution: ";
	cin >> userinputdevolve;
	cout << endl;

	// Calls function that handles the actual devolving process
	VisitorDevolve::Devolve(aEvolveTree, userinputdevolve, aEvolveTree.GetPathogen());
}
