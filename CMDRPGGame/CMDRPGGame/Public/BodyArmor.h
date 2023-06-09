//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef BODYARMOR_H
#define BODYARMOR_H
#include "Armor.h"


class BodyArmor : public Armor
{
private:
	int magicResist;
public:
	BodyArmor(const string & = "", int = 0, int = 0, int = 0);
	BodyArmor& setMagicResist(int);
	int getMagicResist() const;
	virtual void viewDescription() const override;
	virtual bool operator==(const Armor&) const override;
	virtual bool operator==(const Helmet&) const override;
	virtual bool operator==(const BodyArmor&) const override;
	virtual bool operator==(const Ring&) const override;
	virtual bool operator==(const Boots&) const override;
};

#endif
