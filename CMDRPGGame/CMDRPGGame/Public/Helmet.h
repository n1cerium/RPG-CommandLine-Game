//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef HELMET_H
#define HELMET_H
#include <string>
#include "Armor.h"
using namespace std;

class Helmet : public Armor
{
private:
	int magicResist;
public:
	Helmet(const string & = "", int = 0, int = 0, int = 0);
	Helmet& setMagicResist(int);
	int getMagicResist() const;
	virtual void viewDescription() const override;
	virtual bool operator==(const Armor&) const override;
	virtual bool operator==(const Helmet&) const override;
	virtual bool operator==(const BodyArmor&) const override;
	virtual bool operator==(const Ring&) const override;
	virtual bool operator==(const Boots&) const override;
};

#endif