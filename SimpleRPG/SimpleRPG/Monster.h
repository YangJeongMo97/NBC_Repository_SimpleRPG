#pragma once

#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "PlayerCharacter.h"
#include <string>
#include <algorithm>
#include <random>

#define MIN_ATK 5	// ���ݷ� ����
#define MIN_HP 20	// HP ����
#define LMT_ATK 5	// ���ݷ� ����
#define LMT_HP 10	// HP ����
#define EXP 50		// ����ġ ��
#define MIN_GOLD 10	// ��� ����
#define LMT_GOLD 10	// ��� ����
#define DROP_ITEM 30 // ������ ��� Ȯ��
#define RANDRANGE_1TO100 rand() % 100 + 1

using namespace std;

class Monster
{
public:
	virtual string GetName() = 0;
	virtual int GetHealth() = 0;
	virtual int GetAttack() = 0;

	virtual void TakeDamage(int inDamage, PlayerCharacter* inAttackPlayer) = 0;
	virtual void Attack(PlayerCharacter* inDamagedPlayer) = 0;
	virtual Item* DropItem() = 0;
};

