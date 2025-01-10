#pragma once

#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "PlayerCharacter.h"
#include <string>
#include <algorithm>
#include <random>

#define MIN_ATK 5	// 공격력 하한
#define MIN_HP 20	// HP 하한
#define LMT_ATK 5	// 공격력 상한
#define LMT_HP 10	// HP 상한
#define EXP 50		// 경험치 량
#define MIN_GOLD 10	// 골드 하한
#define LMT_GOLD 10	// 골드 상한
#define DROP_ITEM 30 // 아이템 드롭 확률
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

