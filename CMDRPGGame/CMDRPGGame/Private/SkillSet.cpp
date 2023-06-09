//Gevin Sarmiento
//CS/IS 137
//Final Project

#include <iostream>
#include "SkillSet.h"

SkillSet& SkillSet::addToSkillSet(const Skill& skill)
{
	skills.push_back(skill);
	return *this;
}
Skill SkillSet::getSkill(int skillPos) const
{
	return skills[skillPos];
}
void SkillSet::showSkillSet() const
{
	cout << "Here are your skills with their corresponding information: " << endl;
	for (int i = 0; i < skills.size(); i++)
	{
		cout << "(" << i+1 << ")" << endl;
		cout << "Name: " << skills[i].getName() << endl;
		cout << "Costs " << skills[i].getManaCost() << " mana" << endl;
		cout << "Deals " << skills[i].getDamage() << " damage." << endl;
		cout << "Deals " << skills[i].getMagicDamage() << " magicDamage." << endl;
		cout << "Heals you with " << skills[i].getHealth() << " health." << endl;
		cout << "Restore your mana with " << skills[i].getMana() << endl; 
		cout << "Increase your armor with " << skills[i].getArmor() << '.' << endl;
		cout << endl;
	}
}