//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "ArmorSet.h"
#include <iostream>

ArmorSet::ArmorSet()
{
	sets.resize(4);
	removeWeapon();
}
ArmorSet::ArmorSet(const ArmorSet& armorSet)
{
	this->weapon = armorSet.weapon;
	this->sets = armorSet.sets;
}
//ArmorSet& ArmorSet::addArmor(Armor* armor)
//{
//	sets.push_back(armor);
//	return *this;
//}
ArmorSet& ArmorSet::addHelmet(const Helmet& helmet)
{
	sets[0] = const_cast<Helmet*>(&helmet);
	return *this;
}
ArmorSet& ArmorSet::addBodyArmor(const BodyArmor& body)
{
	sets[1] = const_cast<BodyArmor*>(&body);
	return *this;
}
ArmorSet& ArmorSet::addBoots(const Boots& boot)
{
	sets[2] = const_cast<Boots*>(&boot);
	return *this;
}
ArmorSet& ArmorSet::addRing(const Ring& ring)
{
	sets[3] = const_cast<Ring*>(&ring);
	return *this;
}
ArmorSet& ArmorSet::addWeapon(const Weapon& weapon)
{
	this->weapon = const_cast<Weapon*>(&weapon);
	return *this;
}
ArmorSet& ArmorSet::removeArmor(const Armor& armor)
{
	for (int i = 0; i < sets.size(); i++)
	{
		if (sets[i] != nullptr && armor == *sets[i])
		{
			sets[i] = nullptr;
		}
	}
	return *this;
}
ArmorSet& ArmorSet::removeWeapon()
{
	weapon = nullptr;
	return *this;
}
void ArmorSet::showArmorSet() const
{
	if (equal(sets.begin() + 1, sets.end(), sets.begin()) 
		&& weapon == nullptr)
	{
		cout << "You have an empty armor set" << endl;
	}
	else
	{
		cout << "Here is your armor set: \n" << endl;
		for (int i = 0; i < sets.size(); i++)
		{
			if (sets[i] != nullptr && sets[i]->getName() != "")
			{
				cout << "(" << i + 1 << ")" << endl;
				sets[i]->viewDescription();
				cout << endl;
			}
		}
		if (weapon != nullptr)
		{
			weapon->viewDescription();
		}
	}
}