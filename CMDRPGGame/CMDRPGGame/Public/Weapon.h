//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;

class Weapon
{
private:
	string name;
	int attackPower;
public:
	Weapon(const string & = "", int = 0);
	Weapon& setName(const string&);
	Weapon& setAttackPower(int);
	string getName() const;
	int getAttackPower() const;
	virtual void viewDescription() const;
};

#endif