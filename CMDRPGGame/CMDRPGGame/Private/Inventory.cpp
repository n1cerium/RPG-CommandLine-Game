//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
	removeWeapon();
}
Inventory::Inventory(const Inventory& inventory)
{
	this->itemList = inventory.itemList;
	this->weapon = inventory.weapon;
}
Inventory& Inventory::addItem(const Armor& armor)
{
	if (itemList.size() == 4)
	{
		itemList.clear();
	}
	itemList.push_back( const_cast<Armor*>(&armor) );
	return *this;
}
Inventory& Inventory::addWeapon(const Weapon& weapon)
{
	this->weapon = &weapon;
	return *this;
}
Inventory& Inventory::removeItem(const Armor& armor)
{
	for (int i = 0; i < itemList.size(); i++)
	{
		if (itemList[i] != nullptr && *itemList[i] == armor)
		{
			itemList[i] = nullptr;
		}
	}
	return *this;
}
Inventory& Inventory::removeWeapon()
{
	weapon = nullptr;
	return *this;
}
Weapon* Inventory::getWeapon() const
{
	return const_cast<Weapon*>(weapon);
}

void Inventory::showInventory() const
{
	if (equal(itemList.begin() + 1, itemList.end(), itemList.begin()) 
		&& weapon == nullptr) // the equal function basically check if all of the elements
		// of the vector are equal
	{
		cout << "You have an empty inventory" << endl;
	}
	else
	{
		cout << "Here is the item list in your inventory: \n" << endl;
		for (int i = 0; i < itemList.size(); i++)
		{
			if (itemList[i] != nullptr && itemList[i]->getName() != "")
			{
				cout << "(" << i + 1 << ")" << endl;
				itemList[i]->viewDescription();
				cout << endl;	
			}
		}
		if (weapon != nullptr)
		{
			weapon->viewDescription() ;
		}
	}
}
