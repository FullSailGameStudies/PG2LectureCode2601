#pragma once
#include <iostream>
#include <string>

/*

	COMPILE-TIME Polymorphism

	Method Overloading:
		- changing the number of parameters
		- changing the types of the parameters

*/
class Calculator
{
public:
	int add(int n1, int n2);
	int add(int n1, int n2, int n3);
	float add(float f1, float f2);
	double add(double d1, double d2);
};


/*

	COMPILE-TIME Polymorphism

	Operator Overloading

*/
class Account
{
private:
	double mBalance;

public:
};




/*

	RUNTIME Polymorphism

	method overriding

*/
class base
{
protected:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	virtual void DoIt() = 0;//pure virtual

	//1. mark it as virtual
	virtual void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }

	void DoIt() override
	{
		std::cout << "Did it\n";
	}

	//2. add a new method in the derived named the same as the base
	//   everything has to match: the return type, name, types and order of parameters
	void print() override
	{
		//how to override:
		//  full override: don't call the base version
		//  extension override: call the base version

		base::print();
		std::cout << "\tDerived base " << mStr << "\n";
	}
};
