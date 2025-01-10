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
		name = "ȸ�� ����";
		healthRestore = 50;
	}

	string GetName() override { return name; }

	void use(PlayerCharacter* inPlayerCharacter) override 
	{
		if (inPlayerCharacter)
		{
			int currentHP = inPlayerCharacter->GetCurrentHealth();
			int maxHP = inPlayerCharacter->GetMaxHealth();
			int healAmount;
			if (currentHP + healthRestore >= maxHP)
			{
				healAmount = maxHP - currentHP;
				inPlayerCharacter->SetCurrentHealth(maxHP);
			}
			else
			{
				inPlayerCharacter->SetCurrentHealth(currentHP + healthRestore);
				healAmount = healthRestore;
			}
			
			cout << "[" << healAmount << "]��ŭ�� ü���� ȸ���Ͽ����ϴ�!" << endl;
		}
	}
};

