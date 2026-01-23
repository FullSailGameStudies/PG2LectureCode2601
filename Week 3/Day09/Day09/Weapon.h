#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	virtual void showMe();//pure virtual
	int calcDamage();

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

