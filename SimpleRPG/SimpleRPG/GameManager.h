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
			cout << "| 1. ���� | 2. ������ ��� | 3. ���� ���� |" << endl;
			cout << "�ൿ�� �����ϼ���. : ";
			cin >> pick;

			switch (pick)
			{
			case 1:
				inMonster->TakeDamage(inPlayerCharacter->GetAttack(), inPlayerCharacter);
				if (inMonster->GetHealth() > 0)
				{
					cout << "[Player Turn] ���ݿ� �����߽��ϴ�! \"" << inPlayerCharacter->GetName() << "\" ü�� : " << inPlayerCharacter->GetCurrentHealth() 
						<< "/" << inPlayerCharacter->GetMaxHealth() << " | ���� ���� ü�� : " << inMonster->GetHealth() << endl;
				}
				else
				{
					cout << "[Player Turn] ��ɿ� �����߽��ϴ�! ü��: " << inPlayerCharacter->GetCurrentHealth() << "/" << inPlayerCharacter->GetMaxHealth() << " | ����ġ : " << inPlayerCharacter->GetCurrentExp() << "/"
						<< inPlayerCharacter->GetMaxExp() << "(" << inPlayerCharacter->GetCurrentExp() / (double)inPlayerCharacter->GetMaxExp() << "%)" << endl;
				}
				break;
			case 2:
				// TODO : ����Ʈ ��� �� ���ϴ� ������ ���
				cout << "�̱��� ����Դϴ�." << endl;
				break;
			case 3:
				inPlayerCharacter->PrintInfo();
				goto PICK;
				break;
			default:
				cout << "�߸��� �Է°��Դϴ�. �ٽ� �Է����ּ���." << endl;
				goto PICK;
			}

			if (inMonster->GetHealth() > 0)
			{
				inMonster->Attack(inPlayerCharacter);
				cout << "[" << inMonster->GetName() << " Turn] ���� ���߽��ϴ�! \"" << inPlayerCharacter->GetName() << "\" ü�� : " << inPlayerCharacter->GetCurrentHealth()
					<< " / " << inPlayerCharacter->GetMaxHealth() << " | ���� ���� ü�� : " << inMonster->GetHealth() << endl;
				goto PICK;
			}
			else
			{
				// TODO : ���� �̿� �߰�
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
