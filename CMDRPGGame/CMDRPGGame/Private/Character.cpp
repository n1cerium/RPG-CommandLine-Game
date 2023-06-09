//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Character.h"
#include <iostream>

Character::Character()
{
	setName("").setCurrentHealth(0).setMaxHealth(0);
	setCurrentMana(0).setMaxMana(0).setArmor(0);
	setAttackPower(0).setMagicResist(0).setMovementSpeed(0);
	setBodyArmorAS(body).setHelmetAS(helmet).setBootsAS(boots);
	setRingAS(ring);
	weaponType = nullptr;

}

Character& Character::setName(const string& name)
{
	this->name = name;
	return *this;
}
Character& Character::setCurrentHealth(int currentHealth)
{
	if (currentHealth > 0)
	{
		//if the maxhealth happens to be less than the current health, then the 
		// current health would be the max health
		this->currentHealth = currentHealth <= getMaxHealth() ? currentHealth : getMaxHealth();
	}
	else
	{
		this->currentHealth = 0;
	}
	return *this;
}
Character& Character::setMaxHealth(int maxHealth)
{
	if (maxHealth > 0)
	{
		this->maxHealth = maxHealth >= getCurrentHealth() ? maxHealth : getCurrentHealth();
	}
	else
	{
		this->maxHealth = 0;
	}
	return *this;
}
Character& Character::setCurrentMana(int currentMana)
{
	if (currentMana > 0)
	{
		this->currentMana = currentMana <= getMaxMana() ? currentMana : getMaxMana();
	}
	else
	{
		this->currentMana = 0;
	}
	return *this;
}
Character& Character::setMaxMana(int maxMana)
{
	if (maxMana > 0)
	{
		this->maxMana = maxMana >= getCurrentMana() ? maxMana : getCurrentMana();
	}
	else
	{
		this->maxMana = 0;
	}
	return *this;
}
Character& Character::setArmor(int armor)
{
	this->armor = armor > 0 ? armor : 0;
	return *this;
}
Character& Character::setAttackPower(int attackPower)
{
	this->attackPower = attackPower > 0 ? attackPower : 0;
	return *this;
}
Character& Character::setMagicResist(int magicResist)
{
	this->magicResist = magicResist > 0 ? magicResist : 0;
	return *this;
}
Character& Character::setMovementSpeed(int movementSpeed)
{
	this->movementSpeed = movementSpeed > 0 ? movementSpeed : 0;
	return *this;
}
Character& Character::setSkillSet(const Skill& skill)
{
	skillSet.addToSkillSet(skill);
	return *this;
}
string Character::getName() const
{
	return name;
}
int Character::getCurrentHealth() const
{
	return currentHealth;
}
int Character::getMaxHealth() const
{
	return maxHealth;
}
int Character::getCurrentMana() const
{
	return currentMana;
}
int Character::getMaxMana() const
{
	return maxMana;
}
int Character::getArmor() const
{
	return armor;
}
int Character::getAttackPower() const
{
	return attackPower;
}
Monster* Character::getMonster() const
{
	return monster;
}
int Character::getMagicResist() const
{
	return magicResist;
}
int Character::getMovementSpeed() const
{
	return movementSpeed;
}
void Character::showSkillSet() const
{
	skillSet.showSkillSet();
}
void Character::showInventory() const
{
	inventory.showInventory();
}
Character& Character::addToInventory(const Armor& armor)
{
	inventory.addItem(armor);
	return *this;
}
void Character::addArmorAS(const Armor& armor)
{
	int tempArmor = this->armor + armor.getArmor();
	int tempCurrHealth = this->currentHealth + armor.getHealth();
	int tempMaxHealth = this->maxHealth + armor.getHealth();

	setArmor(tempArmor);
	setMaxHealth(tempMaxHealth);
	setCurrentHealth(tempCurrHealth);

	removeToInventory(armor);
	
}
Skill Character::getSkill(int skillPos) const
{
	return skillSet.getSkill(skillPos);
}
Character& Character::setBodyArmorAS(const BodyArmor& body)
{
	int tempMagicResist = this->magicResist + body.getMagicResist();
	addArmorAS(body);
	setMagicResist(tempMagicResist);

	this->body = body;
	armorSet.addBodyArmor(body);
	return *this;
}
Character& Character::setHelmetAS(const Helmet& helmet)
{
	int tempMagicResist = this->magicResist + helmet.getMagicResist();
	addArmorAS(helmet);
	setMagicResist(tempMagicResist);

	this->helmet = helmet;
	armorSet.addHelmet(helmet);
	return *this;
}
Character& Character::setBootsAS(const Boots& boot)
{
	int tempMovementSpeed = this->movementSpeed + boot.getMovementSpeed();
	addArmorAS(boot);
	setMovementSpeed(tempMovementSpeed);

	this->boots = boot;
	armorSet.addBoots(boot);
	return *this;
}
Character& Character::setRingAS(const Ring& ring)
{
	int tempCurrMana = this->currentMana + ring.getMana();
	int tempMaxMana = this->maxMana + ring.getMana();
	addArmorAS(ring);
	setCurrentMana(tempCurrMana);
	setMaxMana(tempMaxMana);

	this->ring = ring;
	armorSet.addRing(ring);
	return *this;
}
Character& Character::addWeaponAS(const Weapon& weapon)
{
	weaponType = const_cast<Weapon*>(&weapon);
	addWeaponStats();
	armorSet.addWeapon(weapon);
	removeWeaponInv();
	return *this;
}
void Character::addWeaponStats()
{
	int tempAtkPower = this->attackPower + weaponType->getAttackPower();
	setAttackPower(tempAtkPower);
}
void Character::removeArmorAS(const Armor& armor)
{
	int tempArmor = this->armor - armor.getArmor();
	int tempMaxHealth = this->maxHealth - armor.getHealth();
	addToInventory(armor);
	if (tempMaxHealth < this->currentHealth)
	{
		setCurrentHealth(tempMaxHealth);
	}
	setArmor(tempArmor);
	setMaxHealth(tempMaxHealth);
	armorSet.removeArmor(armor);
}
Character& Character::removeBodyArmorAS()
{
	int tempMagicResist = this->magicResist - body.getMagicResist();
	setMagicResist(tempMagicResist);
	removeArmorAS(body);

	return *this;
}
Character& Character::removeHelmetAS()
{
	int tempMagicResist = this->magicResist - helmet.getMagicResist();
	setMagicResist(tempMagicResist);
	removeArmorAS(helmet);

	return *this;
}
Character& Character::setMonster(const Monster& monster)
{
	this->monster = const_cast<Monster*>(&monster);
	return *this;
}
Character& Character::removeBootsAS()
{
	int tempMvmtSpeed = this->movementSpeed - boots.getMovementSpeed();
	setMovementSpeed(tempMvmtSpeed);
	removeArmorAS(boots);

	return *this;
}
Character& Character::removeRingAS()
{
	int tempMaxMana = this->maxMana - ring.getMana();
	setMaxMana(tempMaxMana);
	if (tempMaxMana < this->currentMana)
	{
		setCurrentHealth(tempMaxMana);
	}
	removeArmorAS(ring);

	return *this;
}
void Character::removeWeaponAS(const Weapon& weapon) 
{
	int tempAtkPower = this->attackPower - weapon.getAttackPower();
	setAttackPower(tempAtkPower);

	armorSet.removeWeapon();
	addWeaponInv(weapon);
}
void Character::useSkill(int skillPos)
{
	Skill skill = getSkill(skillPos-1);
	int tempManaCost = getCurrentMana() - skill.getManaCost();
	int tempManaRestor = getCurrentMana() + skill.getMana();
 	int tempCurrentHealth = getCurrentHealth() + skill.getHealth();
	int tempArmor = getArmor() + skill.getArmor();

	monster->takeAttackDamage(skill.getDamage());
	monster->takeMagicalDamage(skill.getMagicDamage());
	setCurrentHealth(tempCurrentHealth);
	setArmor(tempArmor);
	setCurrentMana(tempManaCost);
	if (skill.getMana() != 0)
	{
		setCurrentMana(tempManaRestor);
	}
}
Character& Character::removeToInventory(const Armor& armor)
{
	if (armor == body)
	{
		body = BodyArmor();
	}
	else if (armor == helmet)
	{
		helmet = Helmet();
	}
	else if (armor == boots)
	{
		boots = Boots();
	}
	else
	{
		ring = Ring();
	}
	inventory.removeItem(armor);
	return *this;
}
Character& Character::addWeaponInv(const Weapon& weapon)
{
	inventory.addWeapon(weapon);
	return *this;
}
Character& Character::removeWeaponInv()
{
	inventory.removeWeapon();
	weaponType = nullptr;
	return *this;
}
void Character::takeAttackDamage(int damage)
{
	int tempDamage = damage > 0 ? getArmor() % damage : 0; // assuming this is how a monster and
	                            //character take damage when they have an armor
	int tempCurrentHealth = getCurrentHealth() - tempDamage;

	setCurrentHealth(tempCurrentHealth);
}
void Character::takeMagicalDamage(int magicDamage)
{
	int tempMagicDamage = magicDamage > 0 ? magicResist % magicDamage : 0;
	int tempCurrentHealth = getCurrentHealth() - tempMagicDamage;

	setCurrentHealth(tempCurrentHealth);
}
void Character::normalAttack()
{
	monster->takeAttackDamage(this->attackPower);
}
void Character::showStat() const
{
	cout << "Here is the character stats: " << endl;
	cout << "Character Name: " << getName() << endl;
	cout << "Health: " << getCurrentHealth() << " / " << getMaxHealth() << endl;
	cout << "Mana: " << getCurrentMana() << " / " << getMaxMana() << endl;
	cout << "Armor: " << getArmor() << endl;
	cout << "Magic Resist: " << getMagicResist() << endl;
	cout << "Movement Speed: " << getMovementSpeed() << endl;
	cout << "Attack Power: " << getAttackPower() << endl;
}
void Character::showArmorSet() const
{
	armorSet.showArmorSet();
}