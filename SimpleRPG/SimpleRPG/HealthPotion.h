#pragma once

#include "Item.h"

class HealthPotion : public Item
{
private:
	string name;
	int healthRestore;

public:
	HealthPotion() 
	{
		name = "회복 포션";
		healthRestore = 50;
	}

	string GetName() override { return name; }

	void use(PlayerCharacter* inPlayerCharacter) override 
	{
		if (inPlayerCharacter)
		{
			int currentHP = inPlayerCharacter->GetCurrentHealth();
			int maxHP = inPlayerCharacter->GetMaxHealth();
			if (currentHP + healthRestore >= maxHP) inPlayerCharacter->SetCurrentHealth(maxHP);
			else inPlayerCharacter->SetCurrentHealth(currentHP + healthRestore);
		}
	}
};

