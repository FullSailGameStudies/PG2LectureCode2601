#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	std::cout << "\nKnife: \n";
	Weapon::showMe();
	std::cout << "Is Serrated: " << mSerrated << "\n";
}