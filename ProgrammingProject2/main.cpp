#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <queue>
#include <stack>
#include <iomanip>
#include <sstream>
#include "Pathogen.h"
#include "Virus.h"
#include "Bacteria.h"
#include "Fungus.h"
#include "EvolveTree.h"
#include "ModeList.h"
#include "ModeNode.h"
#include "Events.h"
#include "VisitorBase.h"
#include "VisitorEXPIncrement.h"
#include "VisitorRead.h"
#include "VisitorDevolve.h"
#include "StrategyContext.h"
#include "StrategySortAsc.h"
#include "StrategySortDesc.h"
using namespace std;

// Displays all the recorded logs from Stack
void ViewLogs(stack<string> logResults)
{
	// Set Strategy handler
	StrategyContext* aContext = nullptr;

	int loop = 1;
	while (loop == 1) {
		system("cls");
		cout << endl << "[a] Ascending   [d] Descending   [b] Go Back" << endl << endl;
		cout << "Enter option: ";
		string userinput;
		cin >> userinput;
		cout << endl << endl;

		// If player selects Ascending order
		if (userinput == "a") {
			// (Strategy) Use Ascending sort
			aContext = new StrategyContext(new StrategySortAsc());
			aContext->SortStrategy(logResults);	//pass the stack for sorting
			system("pause");
		}
		// If player selects Descending order
		else if (userinput == "d") {
			// (Strategy) Use Descending sort
			aContext = new StrategyContext(new StrategySortDesc());
			aContext->SortStrategy(logResults);	//pass the stack for sorting
			system("pause");
		}
		// If player selects Back
		else if (userinput == "b") {
			loop = 0;
		}
	}
}

// Evolution screen to evolve and devolve
void Evolution(Pathogen& aPathogen, EvolveTree& Cough)
{
	// Set up visitor handler
	VisitorBase* aVisitor = nullptr;

	system("cls");
	int loop = 1;
	while (loop == 1)
	{
		// (Visitor) Displays the pathogen stats
		aVisitor = new VisitorRead();
		aPathogen.VisitorAccept(*aVisitor);
		delete aVisitor;

		cout << endl << "========== Evolution ==========" << endl;

		// Displays currently accessible mutations
		Cough.ReadAll(Cough);

		// Get user selection
		cout << endl << "[e] Evolve   [d] Devolve   [b] Go back" << endl << endl;
		string userinput;
		cout << "Enter option: ";
		cin >> userinput;

		// If player selects "Evolve"
		if (userinput == "e") {
			// Get user selection
			string userinputevolve;
			cout << "Enter evolution: ";
			cin >> userinputevolve;

			// Purchase the mutation (checks to see if it's available)
			Cough.BuyEvolve(Cough, userinputevolve);
			system("cls");
		}
		// If player selects "Devolve"
		else if (userinput == "d") {
			// (Visitor) Devolve a mutation
			aVisitor = new VisitorDevolve();
			Cough.VisitorAccept(*aVisitor);
			delete aVisitor;
			cout << endl << endl;
			system("pause");
			system("cls");
		}
		// If player selects "Back"
		else if (userinput == "b") {
			loop = 0;
		}
		else
			system("cls");
	}
}

// Updates events' years
void EventUpdater(queue<Events>& eventQueue, int currentYear)
{
	// Get the front-most event
	Events anEvent = eventQueue.front();
	// If the year set is before this year
	if (anEvent.GetYear() < currentYear) {
		// Set the event's year to the current year
		eventQueue.front().SetYear(currentYear);
	}
}

// Main play function of the simulation
void Play(Pathogen& aPathogen, ModeNode& aMode)
{
	// Save pathogen's original base stats
	int oriInfectLVL = aPathogen.GetInfectivityLevel();
	int oriLethalLVL = aPathogen.GetLethalityLevel();

	// Visitor
	VisitorBase* aVisitor = nullptr;

	// Stack preparation
	string currentLog;
	stack<string> logResults;
	int logging = 1;

	// Queue preparation
	Events temporaryEvent;
	queue<Events> eventQueue;
	// Create Events objects
	Events band = Events("Band Event", "Many people will be attending!", 2021, 2, 0);
	Events sports = Events("Sports Event", "Many people will be spectating the game!", 2021, 2, 0);
	Events poolparty = Events("Huge Pool Party", "Many people will be together!", 2021, 2, 0);
	Events pokemongo = Events("Pokemon Go gathering", "Some people will be gathering!", 2021, 1, 0);
	// Push Events objects to Queue
	eventQueue.push(band);
	eventQueue.push(sports);
	eventQueue.push(poolparty);
	eventQueue.push(pokemongo);

	// Tree preparation
	// Set up EvolveNodes
	EvolveNode CoughN = EvolveNode("Cough", "Symptom", 1, 0, 1, false);
	EvolveNode PneumoniaN = EvolveNode("Pneumonia", "Symptom", 2, 0, 1, false);
	EvolveNode PulmonaryFibrosisN = EvolveNode("PulmonaryFibrosis", "Symptom", 2, 1, 1, false);
	EvolveNode SneezeN = EvolveNode("Sneeze", "Symptom", 2, 0, 1, false);
	EvolveNode ComaN = EvolveNode("Coma", "Symptom", 0, 2, 1, false);
	EvolveNode FeverN = EvolveNode("Fever", "Symptom", 2, 1, 1, false);
	EvolveNode OrganFailureN = EvolveNode("OrganFailure", "Symptom", 0, 2, 1, false);

	// Set up tree nodes with EvolveNodes
	EvolveTree Cough = EvolveTree(CoughN);
	EvolveTree Pneumonia = EvolveTree(PneumoniaN);
	EvolveTree PulmonaryFibrosis = EvolveTree(PulmonaryFibrosisN);
	EvolveTree Sneeze = EvolveTree(SneezeN);
	EvolveTree Coma = EvolveTree(ComaN);
	EvolveTree Fever = EvolveTree(FeverN);
	EvolveTree OrganFailure = EvolveTree(OrganFailureN);

	// Connect nodes together
	Cough.ConnectLHS(Pneumonia);
	Cough.LHS().ConnectLHS(OrganFailure);
	Cough.LHS().ConnectRHS(PulmonaryFibrosis);
	Cough.ConnectRHS(Sneeze);
	Cough.RHS().ConnectLHS(Coma);
	Cough.RHS().ConnectRHS(Fever);

	// Set pathogen to tree
	Cough.SetPathogen(aPathogen);

	// Get current time
	time_t aTime = time(0);
	struct tm timeStruct;
	localtime_s(&timeStruct, &aTime);
	timeStruct.tm_mday = 1;	//keep day at 1 (prevent skipping months like Feb)

	// Initiate world population, people counters
	long long Total = 7753999999;
	long long Healthy = Total;
	long long Infected = 1;
	long long Dead = 0;

	int loop = 1;
	while (loop == 1)
	{
		long long currentTotal = Healthy + Infected + Dead;

		// Save log results
		stringstream healthyPercent;
		healthyPercent << fixed << setprecision(0) << round((float(Healthy) / float(currentTotal)) * 100);
		string healthyPercentSTR = healthyPercent.str();
		stringstream infectPercent;
		infectPercent << fixed << setprecision(0) << round((float(Infected) / float(currentTotal)) * 100);
		string infectPercentSTR = infectPercent.str();
		stringstream deadPercent;
		deadPercent << fixed << setprecision(0) << round((float(Dead) / float(currentTotal)) * 100);
		string deadPercentSTR = deadPercent.str();

		// If logging is activated
		if (logging == 1) {
			// Let string store Date, numbers of Healthy, Infected, Dead people
			currentLog = "Date: " + to_string(timeStruct.tm_mon + 1) + "/" + to_string(timeStruct.tm_year + 1900) + "\nHealthy: " + to_string(Healthy) + " (" + healthyPercentSTR + "%)\nInfected: " + to_string(Infected) + " (" + infectPercentSTR + "%)\nDead: " + to_string(Dead) + " (" + deadPercentSTR + "%)\n\n";
		}

		// Checks if the pathogen wins or loses
		if (Dead >= Total) {	//if pathogen elimiated all humans
			// Record the last log
			if (logging == 1)
				logResults.push(currentLog);
			system("cls");
			cout << aPathogen.GetName() << " has ended all humans." << endl << endl;
			logging = 0;	//deactivate logging
			system("pause");
		}
		else if (Infected <= 0) {	//if pathogen has killed faster than it can infect
			// Record the last log
			if (logging == 1)
				logResults.push(currentLog);
			system("cls");
			cout << aPathogen.GetName() << " has eliminated all the infected. But left healthy survivors." << endl << endl;
			logging = 0;	//deactivate logging
			system("pause");
		}

		system("cls");

		// Ensures the event queued in front is set for this year
		EventUpdater(eventQueue, timeStruct.tm_year + 1900);
		srand(time(NULL));	//regenerate rng seed

		// Perform various Events
		Events currentEvent;
		// Checks if random number between 1 and 6, hits 3
		if ((rand() % 6 + 1) == 3) {
			// Event that is queued in front becomes the current event
			currentEvent = eventQueue.front();

			// Checks if the year of the event is set for this year
			if (currentEvent.GetYear() == timeStruct.tm_year + 1900) {
				temporaryEvent = currentEvent;	//sets the event for another handler

				cout << currentEvent.GetHeadline() << " " << currentEvent.GetYear() << endl << currentEvent.GetDescription() << endl << endl; // prints event information
				aPathogen.SetInfectivityLevel(aPathogen.GetInfectivityLevel() + currentEvent.GetInfectivity()); // add infectivity
				aPathogen.SetLethalityLevel(aPathogen.GetLethalityLevel() + currentEvent.GetLethality()); // add lethality

				// After event has tooken place, set it for next year
				currentEvent.SetYear((timeStruct.tm_year + 1900) + 1);
				// Pops the front-most event (this one)
				eventQueue.pop();
				// Push the updated event back into the Queue
				eventQueue.push(currentEvent);
			}
		}

		cout << endl << "[e] Evolution   [n] Next Month   [log] View logs   [r] Restart   [q] Quit" << endl << endl;
		
		cout << "Date: " << timeStruct.tm_mon+1 << "/" << timeStruct.tm_year+1900 << endl;
		cout << "Healthy: " << Healthy << " (" << round((float(Healthy)/float(currentTotal))*100) << "%)" << endl;
		cout << "Infected: " << Infected << " (" << round((float(Infected) / float(currentTotal)) * 100) << "%)" << endl;
		cout << "Dead: " << Dead << " (" << round((float(Dead)/float(currentTotal))*100) << "%)" << endl;

		// User options
		cout << endl << "Enter option: ";
		string userinput;
		cin >> userinput;

		// If player selects "Evolution"
		if (userinput == "e")
		{
			Evolution(aPathogen, Cough);
		}
		// If player selects "next month"
		else if (userinput == "n")
		{
			// Record current log
			if (logging == 1)
				logResults.push(currentLog);

			// (Visitor) EXP Increment by 1
			aVisitor = new VisitorEXPIncrement();
			aPathogen.VisitorAccept(*aVisitor);
			delete aVisitor;

			// Add 1 month
			timeStruct.tm_mon += 1;
			mktime(&timeStruct);

			// Updates infected people
			if (Healthy > 0) {
				// Formula for this month's infection
				long long currentInfect = aPathogen.GetInfectivityLevel() * llround(Infected / aMode.GetInfect()) + 1;
				// Prevent the number of infected this month to be more than the Healthy
				if (currentInfect < Healthy) {
					Infected += currentInfect;
				}
				else {
					Infected += Healthy;
				}
				// Updates healthy people
				Healthy = currentTotal - Infected - Dead;
			}

			// Updates dead people
			if (aPathogen.GetLethalityLevel() > 0) {
				// Formula for this month's death
				long long currentDeath = aPathogen.GetLethalityLevel() * llround(aMode.GetLethal()) + llround(Infected/(aMode.GetLethal())*1.4);
				// Prevent the number of death this month to be more than the Infected
				if (Infected > 0 && currentDeath > 0) {
					if (currentDeath < Infected) {
						Dead += currentDeath;
					}
					else {
						Dead += Infected;
					}
					// Updates infected people
					Infected = currentTotal - Healthy - Dead;
				}
			}

			// Events
			if (temporaryEvent.GetHeadline() != "") {
				aPathogen.SetInfectivityLevel(aPathogen.GetInfectivityLevel() - temporaryEvent.GetInfectivity());
				aPathogen.SetLethalityLevel(aPathogen.GetLethalityLevel() - temporaryEvent.GetLethality());
				temporaryEvent.SetHeadline("");
			}
		}
		// If player selects "view log"
		else if (userinput == "log")
		{
			system("cls");
			ViewLogs(logResults);	//pass the stack to ViewLogs function
		}
		// If player restarts the simulation
		else if (userinput == "r")
		{
			// Resets all of the pathogen's attributes
			aPathogen.SetExpPoint(0);
			aPathogen.SetInfectivityLevel(oriInfectLVL);
			aPathogen.SetLethalityLevel(oriLethalLVL);
			// Restarts
			Play(aPathogen, aMode);
			loop = 0;	//ends the current session
		}
		else if (userinput == "q")
		{
			cout << "Are you sure? (y/n): ";
			string areyousure;
			cin >> areyousure;
			if (areyousure == "y") {
				system("cls");
				loop = 0;
			}
		}
	}
}

// Setup game mode and Pathogen before starting simulation
void PlaySetup()
{
	// Setup and attach the pre-set game modes
	ModeList modelist;
	modelist.Attach("Hard", 3, 3);
	modelist.Attach("Medium", 2.5, 2.5);
	modelist.Attach("Easy" , 1.95, 1.95);

	// Runtime loop for PlaySetup()
	int loop = 1;
	while (loop == 1)
	{
		system("cls");
		cout << endl;
		// Array for listing the selectable pathogen type
		int pathogen_arraysize = 3;
		string pathogen[3] = { "Virus", "Bacteria", "Fungus" };

		// For loop prints all elements from array by index
		for (int i = 0; i < pathogen_arraysize; i++)
			cout << "[" << i << "]" << pathogen[i] << " ";

		// Get player's pathogen selection
		cout << endl << endl << "Select your pathogen: ";
		int pathogen_select;
		cin >> pathogen_select;
		
		// Checks if selection is within the array range
		if (pathogen_select > -1 && pathogen_select < pathogen_arraysize) {
			string pathogenelement = pathogen[pathogen_select];

			// Set game mode
			ModeNode* mode = nullptr;

			// Loops runtime for mode selection
			int modeloop = 1;
			while (modeloop == 1) {
				// Prints all SLL nodes from Head to Tail
				system("cls");
				modelist.Display();

				// Gets player's mode selection
				cout << endl << endl << "Enter a mode: ";
				string userinput;
				cin >> userinput;

				// Receives the node that matches the name input
				mode = modelist.GetMode(userinput);

				// If the mode returned is an existing node/mode...
				if (!mode->Empty()) {
					modeloop = 0;	//stop the mode loop
				}
				else {
					// Notifies player of invalid input and loops again
					cout << endl << "Enter valid mode." << endl;
					system("pause");
				}
			}

			// Let players name their Pathogen
			cout << endl << endl << endl << "Name your " << pathogen[pathogen_select] << ": ";
			string pathogenname;
			cin >> pathogenname;
			
			// Sets Pathogen to the derived object of player's input according to array's elements
			Pathogen* aPathogen = nullptr;
			if (pathogenelement == "Virus")
				aPathogen = new Virus(pathogenname);
			else if (pathogenelement == "Bacteria")
				aPathogen = new Bacteria(pathogenname);
			else if (pathogenelement == "Fungus")
				aPathogen = new Fungus(pathogenname);
			// Error prevention, sets to the generic Pathogen
			else
				aPathogen = new Pathogen();

			system("cls");
			cout << endl << pathogenelement << ": " << aPathogen->GetName() << " is deployed. Let's begin!" << endl;
			system("pause");
			// Starts the simulation with selected Pathogen and Game mode
			Play(*aPathogen, *mode);
			loop = 0;

			// Destruct pathogen and modelist
			delete aPathogen;
			modelist.DetachAll();
		}
		else {
			cout << endl << "Please enter a valid Pathogen option." << endl << endl;
			system("pause");
		}
	}
}

// The main function
int main()
{
	int loop = 1;
	while (loop == 1)
	{
		cout << endl << "Welcome to Pathogen Simulator!" << endl << endl;
		cout << endl << "[p] Play \t [q] Quit" << endl << endl;

		cout << "Enter option: ";
		string userinput;
		cin >> userinput;
		if (userinput == "p")
			PlaySetup();
		else if (userinput == "q")
			loop = 0;
		else {
			cout << endl << "Please enter a valid option." << endl << endl;
			system("pause");
			system("cls");
		}
	}

	if (loop == 0) {
		system("cls");
		cout << endl << "Goodbye." << endl << endl;
	}
}
