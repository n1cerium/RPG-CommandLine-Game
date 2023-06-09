//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef SKILLSET_H
#define SKILLSET_H
#include <vector>
#include "Skill.h"
using namespace std;

class SkillSet
{
private:
	vector<Skill> skills;
public:
	SkillSet& addToSkillSet(const Skill&);
	Skill getSkill(int) const;
	void showSkillSet() const;
};

#endif
