#pragma once

#include "Item.h"

class AttackBoost : public Item
{
private:
	string name;
	int attackIncrease;

public:
	AttackBoost() 
	{
		name = "공격력 스크롤"; 
		attackIncrease = 10;
	}

	string GetName() override { return name; }

	void use(PlayerCharacter* inPlayerCharacter) override
	{
		if (inPlayerCharacter)
		{
			int currentAttack = inPlayerCharacter->GetAttack();
			inPlayerCharacter->SetAttack(currentAttack + attackIncrease);
		}
	}
};

