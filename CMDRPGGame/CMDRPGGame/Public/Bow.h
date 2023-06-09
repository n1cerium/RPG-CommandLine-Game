//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef BOW_H
#define BOW_H
#include "Weapon.h"
using namespace std;

class Bow : public Weapon
{
private:
	int range;
	int criticalChance;
	int criticalDamage;
public:
	Bow(const string & = "Bronze Bow", int = 65, int = 105, int = 10, int = 15);
	Bow& setRange(int);
	Bow& setCriticalChance(int);
	Bow& setCriticalDamage(int);
	int getRange() const;
	int getCriticalChance() const;
	int getCriticalDamage() const;
	virtual void viewDescription() const override;
};

#endif 