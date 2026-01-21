#pragma once
#include <string>
class Pistol
{
	//access modifiers: controls who can see the parts
	//public: ALL code can see it
	//private (default): ONLY* this class can see it
	//protected: this class and all descendent classes can see it

public:
	//constructors (ctor)
	//	used to initialize the object when you create it
	//	initialize the fields
	//  purpose is to have an object that is ready to be used
	//		when you create it
	//	IF you do not create a ctor, the compiler will give you a default ctor
	//  IF you create a ctor, the compiler's ctor is not created
	//	RULES:
	//	  1) MUST be named the same as the class
	//    2) CANNOT have a return type

	//default ctor: has no parameters
	//Pistol()
	//{
	//	numberOfRounds_ = 0;
	//	capacity_ = 10;
	//}
	//preferred way: use the member initialization list
	Pistol(int numRounds, int cap) : 
		//list the fields
		numberOfRounds_(numRounds),
		capacity_(cap)
	{
		numberOfPistolsCreated++;
		//use the parameter to initialize the fields
		//numberOfRounds_ = numRounds;
		//capacity_ = cap;
	}
	

	//getters/setters (gatekeepers - control access to fields outside of the class)
	//   usually public
	//getters (accessors)
	//	return type matches the type of the field
	//	they are usually const (they should not change the field)
	//  they usually just return the field
	//  they can be DEFINED w/ the DECLARATION in the header
	int GetNumberOfRounds() const
	{
		return numberOfRounds_;
	}
	int Capacity() const { return capacity_; }

	//setters (mutators) - the purpose is to change the field
	//  return type is usually void
	//	usually 1 parameter that matches the type of the field
	//	cannot be const
	//  they can be DEFINED w/ the DECLARATION in the header
	void SetNumberOfRounds(int numRounds)
	{
		//usually has some validation logic
		if (numRounds >= 0 && numRounds <= capacity_)
		{
			numberOfRounds_ = numRounds;
		}
	}
	void Capacity(int cap)
	{
		if (cap > 0 && cap <= 140)
			capacity_ = cap;
	}

	void Info();//declaration
	static void Report();

private:
	//FIELDS (member variables or data members)
	//they should be private most of the time
	//naming conventions:
	//  camelCasingNamingConvention
	//  add some characters to indicate it's a field
	//	  m_iNumberOfRounds, m_numberOfRounds, mNumberOfRounds, _numberOfRounds, numberOfRounds_
	int numberOfRounds_;
	int capacity_;

	//all objects share the static data of the class
	static int numberOfPistolsCreated;
protected:
};


