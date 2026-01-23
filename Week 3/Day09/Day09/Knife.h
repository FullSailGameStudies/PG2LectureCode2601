#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:
	Knife(int range, int damage, bool mSerrated) :
		Weapon(range,damage),//call the base ctor
		mSerrated(mSerrated)
	{
	}

	bool Serrated() const { return mSerrated; }
	void Serrated(bool serrated) {
		mSerrated = serrated;
	}

	void showMe() override;

private:
	bool mSerrated;

};

