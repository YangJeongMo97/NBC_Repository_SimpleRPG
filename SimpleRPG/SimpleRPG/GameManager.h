#pragma once

#include "PlayerCharacter.h"
#include "Goblin.h"
#include "Orc.h"
#include "Slime.h"
#include "Troll.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

#define MONSTER 4

class GameManager
{
public:
	Monster* getnerateMonster(int inLevel)
	{
		Monster* NewMonster;
		int idx = rand() % MONSTER;

		switch (idx)
		{
		case 0:
			NewMonster = new Goblin(inLevel);
			break;
		case 1:
			NewMonster = new Orc(inLevel);
			break;
		case 2:
			NewMonster = new Slime(inLevel);
			break;
		case 3:
			NewMonster = new Troll(inLevel);
			break;
		default:
			NewMonster = nullptr;
			break;
		}
		
		return NewMonster;
	}

	void battle(PlayerCharacter* inPlayerCharacter, Monster* inMonster)
	{
		if (inPlayerCharacter && inMonster)
		{
			int pick;
		PICK:
			cout << endl;
			cout << "| 1. 공격 | 2. 아이템 사용 | 3. 상태 보기 |" << endl;
			cout << "행동을 선택하세요. : ";
			cin >> pick;

			switch (pick)
			{
			case 1:
				inMonster->TakeDamage(inPlayerCharacter->GetAttack(), inPlayerCharacter);
				if (inMonster->GetHealth() > 0)
				{
					cout << "[Player Turn] 공격에 성공했습니다! \"" << inPlayerCharacter->GetName() << "\" 체력 : " << inPlayerCharacter->GetCurrentHealth() 
						<< "/" << inPlayerCharacter->GetMaxHealth() << " | 몬스터 남은 체력 : " << inMonster->GetHealth() << endl;
				}
				else
				{
					cout << "[Player Turn] 사냥에 성공했습니다! 체력: " << inPlayerCharacter->GetCurrentHealth() << "/" << inPlayerCharacter->GetMaxHealth() << " | 경험치 : " << inPlayerCharacter->GetCurrentExp() << "/"
						<< inPlayerCharacter->GetMaxExp() << "(" << inPlayerCharacter->GetCurrentExp() / (double)inPlayerCharacter->GetMaxExp() << "%)" << endl;
				}
				break;
			case 2:
				// TODO : 리스트 출력 후 원하는 아이템 사용
				cout << "미구현 기능입니다." << endl;
				break;
			case 3:
				inPlayerCharacter->PrintInfo();
				goto PICK;
				break;
			default:
				cout << "잘못된 입력값입니다. 다시 입력해주세요." << endl;
				goto PICK;
			}

			if (inMonster->GetHealth() > 0)
			{
				inMonster->Attack(inPlayerCharacter);
				cout << "[" << inMonster->GetName() << " Turn] 공격 당했습니다! \"" << inPlayerCharacter->GetName() << "\" 체력 : " << inPlayerCharacter->GetCurrentHealth()
					<< " / " << inPlayerCharacter->GetMaxHealth() << " | 몬스터 남은 체력 : " << inMonster->GetHealth() << endl;
				goto PICK;
			}
			else
			{
				// TODO : 상점 이용 추가
			}

			displayInventory(inPlayerCharacter);
		}
	}

	void displayInventory(PlayerCharacter* inPlayerCharacter)
	{
		if (inPlayerCharacter)
		{
			cout << endl;
			cout << "Inventory---------------------------------------" << endl;
			vector<Item*> PlayerInventory = inPlayerCharacter->GetInventory();
			for (int i = 0; i < PlayerInventory.size(); i++)
			{
				cout << i + 1 << ". " << PlayerInventory[i]->GetName() << endl;
			}
			cout << "------------------------------------------------" << endl;
		}
	}
};

