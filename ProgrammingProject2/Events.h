#pragma once
#include <iostream>
using namespace std;

class Events
{
public:
	// Constructor
	Events();
	Events(string Headline, string Description, int Year, int Infectivity, int Lethality);

	// Getters
	string GetHeadline();
	string GetDescription();
	int GetYear();
	int GetInfectivity();
	int GetLethality();

	// Setters
	void SetHeadline(string Headline);
	void SetYear(int Year);

private:
	string eHeadline;
	string eDescription;
	int eYear;
	int eInfectivity;
	int eLethality;
};
