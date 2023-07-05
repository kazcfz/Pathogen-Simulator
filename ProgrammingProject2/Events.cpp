#include <iostream>
#include "Events.h"
using namespace std;

// Constructor
Events::Events()
{
	eHeadline = "";
	eDescription = "";
	eYear = -1;
	eInfectivity = 0;
	eLethality = 0;
}

Events::Events(string Headline, string Description, int Year, int Infectivity, int Lethality)
{
	eHeadline = Headline;
	eDescription = Description;
	eYear = Year;
	eInfectivity = Infectivity;
	eLethality = Lethality;
}

// Getters
string Events::GetHeadline() { return eHeadline; }
string Events::GetDescription() { return eDescription; }
int Events::GetYear() { return eYear; }
int Events::GetInfectivity() { return eInfectivity; }
int Events::GetLethality() { return eLethality; }

// Setters
void Events::SetHeadline(string Headline) { eHeadline = Headline; return; }
void Events::SetYear(int Year) { eYear = Year; return; }
