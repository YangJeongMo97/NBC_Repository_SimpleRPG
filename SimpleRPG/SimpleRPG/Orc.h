#pragma once

#include "Monster.h"

#define ITEM_TABLE 2 // ��� ������ ����

class Orc : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Orc(int inLevel)
	{
		name = "��ũ";
		health = inLevel * (MIN_HP + rand() % LMT_HP);
		attack = inLevel * (MIN_ATK + rand() % LMT_ATK);
	}

	string GetName() override { return name; }
	int GetHealth() override { return health; }
	int GetAttack() override { return attack; }

	void TakeDamage(int inDamage, PlayerCharacter* inAttackPlayer) override
	{
		if (inAttackPlayer)
		{
			if (health - inDamage <= 0)
			{
				health = 0;
				inAttackPlayer->AddCurrentExp(EXP);

				// ����Ǵ� ��差
				int DropGoldAmount = MIN_GOLD + rand() % LMT_GOLD;
				inAttackPlayer->AddGold(DropGoldAmount);

				// ������ ��� Ȯ��
				bool isDropItem = RANDRANGE_1TO100 <= DROP_ITEM;
				if (isDropItem)
				{
					inAttackPlayer->AddInventory(DropItem());
				}
			}
			else health -= inDamage;
		}
	}

	void Attack(PlayerCharacter* inDamagedPlayer) override
	{
		if (inDamagedPlayer)
		{
			inDamagedPlayer->TakeDamage(attack);
		}
	}

	Item* DropItem() override
	{
		int idx = rand() % ITEM_TABLE;

		Item* DropItem;

		switch (idx)
		{
		case 0:
			DropItem = new HealthPotion();
			break;
		case 1:
			DropItem = new AttackBoost();
			break;
		default:
			DropItem = nullptr;
			break;
		}

		return DropItem;
	}
};