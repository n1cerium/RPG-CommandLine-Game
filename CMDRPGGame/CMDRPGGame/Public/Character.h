//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Monster.h"
#include "Inventory.h"
#include "SkillSet.h"
#include "ArmorSet.h"

class Character
{
private:
	BodyArmor body;
	Helmet helmet;
	Boots boots;
	Ring ring;
	string name;
	int currentHealth;
	int maxHealth;
	int currentMana;
	int maxMana;
	int armor;
	int attackPower;
	int magicResist;
	int movementSpeed;
	Inventory inventory;
	ArmorSet armorSet;
	SkillSet skillSet;
	Monster* monster;
	Weapon* weaponType;
	void addArmorAS(const Armor&); // have this function just to reduce repeat code 
	void removeArmorAS(const Armor&); // same with this
public:
	Character();
	Character& setMonster(const Monster&);
	Character& setName(const string&);
	Character& setCurrentHealth(int);
	Character& setMaxHealth(int);
	Character& setCurrentMana(int);
	Character& setMaxMana(int);
	Character& setArmor(int);
	Character& setAttackPower(int);
	Character& setMagicResist(int);
	Character& setMovementSpeed(int);
	Character& setSkillSet(const Skill&);
	string getName() const;
	int getCurrentHealth() const;
	int getMaxHealth() const;
	int getCurrentMana() const;
	int getMaxMana() const;
	int getArmor() const;
	int getAttackPower() const;
	int getMagicResist() const;
	int getMovementSpeed() const;
	void showSkillSet() const;
	void showArmorSet() const;
	void showInventory() const;
	void useSkill(int);
	Skill getSkill(int) const;
	Monster* getMonster() const;
	Character& addWeaponInv(const Weapon&);
	Character& removeWeaponInv();
    Character& addWeaponAS(const Weapon&);
	Character& addToInventory(const Armor&);
	Character& setBodyArmorAS(const BodyArmor&);
	Character& setHelmetAS(const Helmet&); //AS == armor set
	Character& setBootsAS(const Boots&);
	Character& setRingAS(const Ring&);
	Character& removeBodyArmorAS();
	Character& removeHelmetAS();
	Character& removeBootsAS();
	Character& removeRingAS();
	Character& removeToInventory(const Armor&);
	virtual void takeAttackDamage(int);
	virtual void takeMagicalDamage(int);
	virtual void normalAttack();
	virtual void removeWeaponAS(const Weapon&);
	virtual void addWeaponStats();
	virtual void setSkills() = 0;
	virtual void showStat() const;
	virtual string characterType() const = 0;
	
};

#endif 