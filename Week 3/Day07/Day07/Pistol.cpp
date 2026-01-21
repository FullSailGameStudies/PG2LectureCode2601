#include "Pistol.h"
#include <iostream>

void Pistol::Info()
{
	std::cout << numberOfRounds_ << "/" << capacity_ << "\n";
}
