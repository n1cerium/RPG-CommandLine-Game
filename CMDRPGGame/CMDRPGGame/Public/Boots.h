//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef BOOTS_H
#define BOOTS_H
#include "Armor.h"

class Boots : public Armor
{
private:
	int movementSpeed;
public:
	Boots(const string & = "", int = 0, int = 0, int = 0);
	Boots& setMovementSpeed(int);
	int getMovementSpeed() const;
	virtual void viewDescription() const override;
	virtual bool operator==(const Armor&) const override;
	virtual bool operator==(const Helmet&) const override;
	virtual bool operator==(const BodyArmor&) const override;
	virtual bool operator==(const Ring&) const override;
	virtual bool operator==(const Boots&) const override;
};

#endif 
