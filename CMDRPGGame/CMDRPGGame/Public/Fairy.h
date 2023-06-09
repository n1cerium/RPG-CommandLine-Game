//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef FAIRY_H
#define FAIRY_H
#include "Monster.h"
//#include "Character.h"

class Fairy : public Monster
{
private:
	int magicDamage;
	int range;
public:
	Fairy();
	Fairy& setMagicDamage(int);
	int getMagicDamage() const;
	Fairy& setRange(int);
	int getRange() const;
	virtual void normalAttack() override;
	virtual void showStat() const override;

};

#endif