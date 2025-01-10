#pragma once

#include "PlayerCharacter.h"
#include "Goblin.h"
#include "Orc.h"
#include "Slime.h"
#include "Troll.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <conio.h>

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
			string input;

			cout << "진행을 원하시면 엔터(Enter)를 눌러주세요";
		PICK:
			cin.ignore();
			cout << endl;
			cout << "| 1. 공격 | 2. 아이템 사용 | 3. 상태 보기 | 4. 몬스터 정보 보기 |" << endl;
			cout << "행동을 선택하세요. : ";
			cin >> pick;

			switch (pick)
			{
				// 공격 로직
			case 1:
				inMonster->TakeDamage(inPlayerCharacter->GetAttack(), inPlayerCharacter);
				// 몬스터 생존
				if (inMonster->GetHealth() > 0)
				{
					cout << "[Player Turn] 공격에 성공했습니다! \"" << inPlayerCharacter->GetName() << "\" 체력 : " << inPlayerCharacter->GetCurrentHealth() 
						<< "/" << inPlayerCharacter->GetMaxHealth() << " | 몬스터 남은 체력 : " << inMonster->GetHealth() << endl;
				}
				// 사냥 성공
				else
				{
					cout << "[Player Turn] 사냥에 성공했습니다! 체력: " << inPlayerCharacter->GetCurrentHealth() << "/" << inPlayerCharacter->GetMaxHealth() << " | 경험치 : " << inPlayerCharacter->GetCurrentExp() << "/"
						<< inPlayerCharacter->GetMaxExp() << "(" << inPlayerCharacter->GetCurrentExp() / (double)inPlayerCharacter->GetMaxExp() << "%)" << endl;
				}
				break;
				
				// 아이템 사용
			case 2:
			USE_ITEM:
				displayInventory(inPlayerCharacter);

				// 뒤로가기 || 아이템 번호 입력
				cout << "뒤로 가기(Z) | 사용할 아이템의 번호 : ";
				cin >> input;

				if (input == "z" || input == "Z")
				{
					goto PICK;
				}
				else if (all_of(input.begin(), input.end(), ::isdigit))
				{
					pick = stoi(input);
				}

				if (pick > inPlayerCharacter->GetInventory().size() || pick < 1)
				{
					cout << "잘못된 입력값입니다. 다시 입력해주세요." << endl;
					goto USE_ITEM;
				}

				inPlayerCharacter->UseItem(pick);

				break;

				// 플레이어 정보 출력
			case 3:
				inPlayerCharacter->DisplayInfo();
				goto PICK;
				break;

				// 현재 스폰된 몬스터 정보 출력
			case 4:
				inMonster->DisplayInfo();
				goto PICK;
				break;

			default:
				cout << "잘못된 입력값입니다. 다시 입력해주세요." << endl;
				goto PICK;
			}

			// 몬스터가 살아 있는 경우 몬스터의 차례로 넘어감
			if (inMonster->GetHealth() > 0)
			{
				inMonster->AttackPlayer(inPlayerCharacter);
				cout << "[" << inMonster->GetName() << " Turn] 공격 당했습니다! \"" << inPlayerCharacter->GetName() << "\" 체력 : " << inPlayerCharacter->GetCurrentHealth()
					<< " / " << inPlayerCharacter->GetMaxHealth() << " | 몬스터 남은 체력 : " << inMonster->GetHealth() << endl;
				goto PICK;
			}
			else
			{
				// TODO : 상점 이용 추가
			}
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

