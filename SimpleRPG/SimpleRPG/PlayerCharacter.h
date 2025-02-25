#pragma once

#include "Item.h"
#include <iostream>
#include <string>
#include <vector>

#define HPINCREASE 20
#define ATKINCREASE 5

using namespace std;

class PlayerCharacter
{
private:
	PlayerCharacter(string inName)
	{
		name = inName; 
		level = 1;
		maxHealth = 200;
		currentHealth = maxHealth;
		attack = 20;
		maxExp = 100;
		currentExp = 0;
		remainExp = 0;
		gold = 0;
	}

	static PlayerCharacter* instance;

	string name;
	int level;
	int maxHealth;
	int currentHealth;
	int attack;
	int maxExp;
	int currentExp;
	int remainExp;
	int gold;
	vector<Item*> inventory;

public:
	static PlayerCharacter* GetInstance(string inName = "")
	{
		if (!instance)
		{
			instance = new PlayerCharacter(inName);
		}
		return instance;
	}

	// 데이터 Get & Set
	string GetName() { return name; }
	void SetName(string NewName) { name = NewName; }

	int GetLevel() { return level; }

	int GetMaxHealth() { return maxHealth; }
	void SetMaxHealth(int NewMaxHealth) { maxHealth = NewMaxHealth; }

	int GetCurrentHealth() { return currentHealth; }
	void SetCurrentHealth(int NewCurrentHealth) { currentHealth = NewCurrentHealth; }

	int GetAttack() { return attack; }
	void SetAttack(int NewAttack) { attack = NewAttack; }

	int GetMaxExp() { return maxExp; }
	void SetMaxExp(int NewMaxExp) { maxExp = NewMaxExp; }

	// Set 되지 않는 데이터. Add만 가능
	int GetCurrentExp() { return currentExp; }
	void AddCurrentExp(int ExpAmount)
	{ 
		if (currentExp + ExpAmount >= maxExp)
		{
			remainExp = currentExp + ExpAmount - maxExp;
			LevelUp();
		}
		else currentExp += ExpAmount;
	}

	int GetGold() { return gold; }
	void AddGold(int GoldAmount) { gold += GoldAmount; }

	// 인벤토리
	vector<Item*> GetInventory() { return inventory; }
	void AddInventory(Item* NewItem) 
	{
		if(NewItem) inventory.push_back(NewItem);
		cout << "******" << endl;
		cout << "*득템* [" << NewItem->GetName() << "]을 획득하셨습니다." << endl;
		cout << "******" << endl;
	}

	void UseItem(int idx)
	{
		Item* usedItem = inventory[idx - 1];
		usedItem->use(this);
		inventory.erase(inventory.begin() + idx - 1);
	}

	//데미지 및 사망처리
	void TakeDamage(int inDamage)
	{
		if (inDamage >= currentHealth) Death();
		else currentHealth -= inDamage;
	}

	void Death()
	{
		cout << "전투에서 패배하여 \"<<" << name << "\"가 사망하였습니다. 게임이 종료됩니다." << endl;
		exit(0);
	}

	// 레벨업
	void LevelUp()
	{
		if (level < 10)
		{
			++level;
			currentExp = remainExp;
			maxHealth += level * HPINCREASE;
			currentHealth = maxHealth;
			attack += level * ATKINCREASE;
		}
	}

	void DisplayInfo()
	{
		cout << "Info--------------------------------------------" << endl;
		cout << "캐릭터 이름 : " << name << endl;
		cout << "Lv : " << level << endl;
		cout << "ATK : " << attack << endl;
		cout << "HP : " << currentHealth << " / " << maxHealth << "(" << currentHealth / (double)maxHealth << "%)" << endl;
		cout << "EXP : " << currentExp << " / " << maxExp << "(" << currentExp / (double)maxExp << "%)" << endl;
		cout << "Gold : " << gold << endl;
		cout << "------------------------------------------------" << endl;
	}
};

PlayerCharacter* PlayerCharacter::instance = nullptr;