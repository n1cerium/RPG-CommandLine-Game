//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Character.h"
#include "Inventory.h"
#include "ArmorSet.h"
#include "Warrior.h"
#include "Archer.h"
#include "Wizard.h"
#include "Hound.h"
#include "Golem.h"
#include "Fairy.h"
#include "Gargoyle.h"
#include <iostream>

template<typename MonsterType>
void quest(Monster*, Character*, vector<MonsterType>, Warrior&);

void questProgress(Monster*, Character*);

int main()
{
	int characterChoice;
	string characterName;
	Weapon* weapon;
	Monster* monster = nullptr;
	Character* character;
	vector<Fairy> fairy = { Fairy(),Fairy(),Fairy(),Fairy(),Fairy(),Fairy(),Fairy() };
	vector<Golem> golem = { Golem(),Golem(),Golem() };
	vector<Hound> hound = { Hound(), Hound(), Hound(), Hound(), Hound() };
	vector<Gargoyle> gargoyle = { Gargoyle(), Gargoyle() };
	Warrior warrior;
	Archer archer;
	Wizard wizard;
	Sword sword("Golden Sword", 300, 195, 180);
	Staff staff("Golden Staff", 210, 80, 350);
	Bow bow("Golden Bow", 450, 85, 90, 150);
	Helmet helmet("Golden Helmet", 150, 700, 175);
	BodyArmor body("Golden BodyArmor", 160, 1000, 275);
	Boots boots("Golden Boots", 140, 500, 300);
	Ring ring("Golden Ring", 90, 800, 750);
	Armor* rewards[4] = { &helmet, &body, &boots, &ring };

	cout << "Welcome to this visual RPG (not the ideal one)." << endl;
	cout << "In this game, you will have a short of Menu " << endl;
	cout << "which will guide you to control you character " << endl;
	cout << "who you has chosen." << endl << endl;
	
	warrior.showStat();
	archer.showStat();
	wizard.showStat();

	cout << "Character Selection. " << endl;
	cout << "------------------------" << endl;
	cout << "1) Warrior" << endl;
	cout << "2) Archer" << endl;
	cout << "3) Wizard" << endl;
	cout << "Please enter a number that corresponds the characters: ";
	cin >> characterChoice;
	while (characterChoice != 1 && characterChoice != 2 && characterChoice != 3)
	{
		cout << "Wrong Selection, Player. Try again: ";
		cin >> characterChoice;
	}
	cin.ignore();

	if (characterChoice == 1)
	{
		character = &warrior;
		weapon = &sword;
	}
	else if (characterChoice == 2)
	{
		character = &archer;
		weapon = &bow;
	}
	else
	{
		character = &wizard;
		weapon = &staff;
	}
	cout << "Please enter the name of this character: ";
	getline(cin, characterName);
	character->setName(characterName);
	cout << "Now, you entered the game." << endl;
	cout << endl;

	cout << "Welcome to your first Quest, Player." << endl;
	cout << "In this first quest you have to kill 3 golems " << endl;
	cout << "in order to move in the next quest." << endl;
	cout << "You will get these two rewards: " << endl << endl;

	rewards[0]->viewDescription();
	rewards[1]->viewDescription();

	cout << "Now, go on and slay those golems. :)" << endl;
	cout << "Just a reminder, Player. Your health will get restored everytime you slay a monster :)" << endl;
	cout << endl;
	
	quest(monster, character, golem, warrior);
	
	cout << "You have successfully slayed those golems."
		<< " Here is your rewards. \n";
	character->addToInventory(*rewards[0]);
	character->addToInventory(*rewards[1]);
	cout << "...\nYour rewards are in your inventory.\n";
	character->showInventory();
	cout << "Automatically putting these armors to your armor set :)\n" << endl;

	character->setHelmetAS(helmet);

	character->setBodyArmorAS(body);

	character->showArmorSet();

	cout << "\nNow let's move on to second quest.\n";
	cout << "In these second quest, you have to kill 5 hounds.\n";
	cout << "These will be your rewards: \n\n";

	rewards[2]->viewDescription();
	rewards[3]->viewDescription();

	cout << "\nNow, slay those hounds. " << endl << endl;

	quest(monster, character, hound, warrior);

	cout << "You have successfully slayed those hounds."
		<< " I will put the rewards to your inventory. " << endl;
	character->addToInventory(*rewards[2]);
	character->addToInventory(*rewards[3]);
	cout << "..." << endl;
	character->showInventory();
	cout << "Automatically, An AI putting these armors to your armor set :)\n" << endl;

	character->setBootsAS(boots);
	character->setRingAS(ring);

	character->showArmorSet();
	cout << endl;
	cout << "Let's move on to your third quest." << endl;
	cout << "For this quest, you have to slay 7 fairies.";
	cout << "You will get this reward\n " << endl;

	weapon->viewDescription();
	
	cout << "\nLet's go and slay those fairies. " << endl;

	quest(monster, character, fairy, warrior);

	cout << "Nice, you slayed those fairies " << endl;
	cout << "I will put this weapon to your inventory." << endl;
	
	character->addWeaponInv(*weapon);
	cout << "..." << endl;
	character->showInventory();

	cout << "I, now, putting this to your armor set :) \n" << endl;

	if (character->characterType() == "Warrior")
	{	
		Sword tempSword = warrior.getSword();
		character->removeWeaponAS(tempSword);
		warrior.setSword(sword);
		character->addWeaponInv(tempSword);
	}
	else if (character->characterType() == "Archer")
	{
		Bow tempBow = archer.getBow();
		character->removeWeaponAS(tempBow);
		archer.setBow(bow);
		character->addWeaponInv(tempBow);
	}
	else
	{
		Staff tempStaff = wizard.getStaff();
		character->removeWeaponAS(tempStaff);
		wizard.setStaff(staff);
		character->addWeaponInv(tempStaff);;
	}

	character->showArmorSet();
	cout << endl;
	cout << "Now, it comes your final quest." << endl;
	cout << "Please, slay 2 gargoyles and you win this basic and visual RPG." << endl;
	cout << "Now, you go slay those gargoyles.\n" << endl;

	quest(monster, character, gargoyle, warrior);

	cout << "You have successfully slayed those gargoyles." << endl;
	cout << "Thank you for using this simple RPG, and Congratulation for winning :)" << endl;
	cout << "Now, I have to remove all of your armors including weapon from your armor set and inventory. :)" << endl;
	cout << endl;

	character->removeHelmetAS();
	character->removeBodyArmorAS();
	character->removeBootsAS();
	character->removeRingAS();

	if (character->characterType() == "Warrior")
	{
		character->removeWeaponAS(sword);
	}
	else if (character->characterType() == "Archer")
	{
		character->removeWeaponAS(bow);
	}
	else
	{
		character->removeWeaponAS(staff);
	}
	character->showArmorSet();
	cout << endl;
	character->showInventory();

	character->removeToInventory(helmet);
	character->removeToInventory(body);
	character->removeToInventory(boots);
	character->removeToInventory(ring);
	character->removeWeaponInv();

	cout << endl;

	cout << endl;
	cout << "All items are successfully removed :)" << endl;
	character->showStat();
}
void questProgress(Monster* mons, Character* hero)
{
	int skillSelection;
	int attackChoice;
	do
	{
		hero->showStat();
		cout << endl;
		mons->showStat();
		cout << endl;
		cout << "Attacking option" << endl;
		cout << "------------------------" << endl;
		cout << "1) Normal attack" << endl;
		cout << "2) Use skill" << endl;
		cout << "Please make your choice: ";
		cin >> attackChoice;
		while (attackChoice != 1 && attackChoice != 2)
		{
			cout << "Invalid selection, Player. Please enter again: ";
			cin >> attackChoice;
		}
		cout << endl;
		if (attackChoice == 1)
		{
			hero->normalAttack();
		}
		else
		{
			hero->showSkillSet();
			cout << "Please enter the number that corresponds with the skill you want to use: ";
			cin >> skillSelection;
			while (skillSelection != 1 && skillSelection != 2 && skillSelection != 3 && skillSelection != 4)
			{
				cout << "No skill corresponds with that number. Try again: ";
				cin >> skillSelection;
			}
			hero->useSkill(skillSelection);
		}

		mons->normalAttack();

	} while (mons->getCurrentHealth() > 0 && hero->getCurrentHealth() > 0);

}
template<typename MonsterType>
void quest(Monster* mons, Character* hero, vector<MonsterType> monsters, Warrior& warr) 
//has to pass warrior by reference because I want this function to change the values of Warrior that
// is passed in this function
{
	for (int i = 0; i < monsters.size(); i++)
	{

		mons = &(monsters[i]);
		mons->setCharacter(*hero);
		hero->setMonster(*mons);

		questProgress(mons, hero);
		if (hero->getCurrentHealth() <= 0)
		{
			cout << "You died, but you got revived. " << endl;
			cout << "You have to killed that golem if it did not die." << endl << endl;
			i--;
		}
		if (hero->characterType() == "Warrior")
		{
			warr.setBarrier(300);
		}
		hero->setCurrentHealth(hero->getMaxHealth());
		cout << "You have killed " << i + 1 << " / " << monsters.size() << " monsters" << endl;
		cout << endl;
	}
}