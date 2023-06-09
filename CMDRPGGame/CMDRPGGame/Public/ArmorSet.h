//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef ARMORSET_H
#define ARMORSET_H
#include <vector>
#include "Armor.h"
#include "BodyArmor.h"
#include "Boots.h"
#include "Helmet.h"
#include "Ring.h"
#include "Weapon.h"
#include "Sword.h"
#include "Bow.h"
#include "Staff.h"


class ArmorSet
{
private:
	Weapon* weapon;
	vector<Armor*> sets;
public:
	ArmorSet();
	ArmorSet(const ArmorSet&);
	ArmorSet& addBodyArmor(const BodyArmor&);
	ArmorSet& addHelmet(const Helmet&);
	ArmorSet& addBoots(const Boots&);
	ArmorSet& addRing(const Ring&);
	//ArmorSet& addArmor(Armor*);
	ArmorSet& addWeapon(const Weapon&);
	ArmorSet& removeArmor(const Armor&);
	ArmorSet& removeWeapon();
	void showArmorSet() const;
};
#endif