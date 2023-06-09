//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef ARMOR_H
#define ARMOR_H
#include <string>
#include <vector>
using namespace std;

// I need to do this so the Armor class know these classes exist
class Helmet;
class BodyArmor;
class Ring;
class Boots;


class Armor
{
private:
	//vector<string> descriptions;
	string name;
	int armor;
	int health;
public:
	Armor(const string& = "", int = 0, int = 0);
	Armor& setName(const string&);
	Armor& setArmor(int);
	Armor& setHealth(int);
	//Armor& addDescription(const string&);
	//void getDescription() const;
	string getName() const;
	int getArmor() const;
	int getHealth() const;
	bool isEqualArmor(const Armor&) const;
	virtual void viewDescription() const;
	virtual bool operator==(const Armor&) const = 0;
	virtual bool operator==(const Helmet&) const = 0;
	virtual bool operator==(const BodyArmor&) const = 0;
	virtual bool operator==(const Ring&) const = 0;
	virtual bool operator==(const Boots&) const = 0;

};

#endif
