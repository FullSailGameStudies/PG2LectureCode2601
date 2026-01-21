#pragma once
#include "Animal.h"
#include <string>
//Dog is the derived or child class
//Animal is the base or parent class
class Dog : public Animal
{
public:
	//child ctor MUST call a base ctor
	//add the call in the member initialization list
	Dog(bool hasV, std::string brd) :
		Animal(hasV),
		breed(brd)
	{

	}
private:
	std::string breed;
};

