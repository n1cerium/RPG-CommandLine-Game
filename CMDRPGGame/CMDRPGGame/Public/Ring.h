//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef RING_H
#define RING_H
#include <string>
#include "Armor.h"
using namespace std;

class Ring : public Armor
{
private:
	int mana;
public:
	Ring(const string& = "", int = 0, int = 0, int = 0);
	Ring& setMana(int);
	int getMana() const;
	virtual void viewDescription() const override;
	virtual bool operator==(const Armor&) const override;
	virtual bool operator==(const Helmet&) const override;
	virtual bool operator==(const BodyArmor&) const override;
	virtual bool operator==(const Ring&) const override;
	virtual bool operator==(const Boots&) const override;
};

#endif