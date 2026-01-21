#include "Pistol.h"
#include <iostream>

int Pistol::numberOfPistolsCreated = 0;

//non-static methods:
//	there is a hidden parameter called 'this'
//	'this' is a pointer to the object that the method was called on
//	can access non-static AND static members
void Pistol::Info()
{
	std::cout << numberOfRounds_ << "/" << capacity_ << "\n";
}
//static methods:
//	do NOT have a 'this' parameter
//	can NOT access non-static members
void Pistol::Report()
{
	//std::cout << GetNumberOfRounds() << "/" << capacity_ << "\n";
	std::cout << "Number of pistols created: " << numberOfPistolsCreated << "\n";
}
