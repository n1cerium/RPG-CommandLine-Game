//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef INVENTORY_H
#define INVENTORY_H
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
using namespace std;

class Inventory
{
private:
	vector<Armor*> itemList;
	const Weapon* weapon;
public:
	Inventory();
	Inventory(const Inventory&);
	Inventory& addItem(const Armor&); 
	Weapon* getWeapon() const;
	Inventory& addWeapon(const Weapon&);
	Inventory& removeItem(const Armor&);
	Inventory& removeWeapon(); 
	void showInventory() const;


};

#endif 
