#pragma once

#include "GameManager.h"
#include <ctime>

#define LETTER_COUNT(s) countLetters(s, s.length())

int countLetters(string pLetters, int len)
{
	int strlen_ = 0;
	int i = 0;

	for (i = 0; i < len; i++)
	{
		strlen_++;
		if (pLetters[i] & 0x80)
			i++;
	}

	return strlen_;
}

int main()
{
	srand((unsigned int)time(NULL));

	GameManager* GM = new GameManager();
	PlayerCharacter* PC;

	string UserName, UserName_copy;

CREATE:
	cout << "ĳ���� ����-------------------------------------" << endl;
	cout << "�г��� �Է�(16�� �̳�) : ";
	getline(cin, UserName);

	UserName_copy = UserName;

	if (LETTER_COUNT(UserName) > 16)
	{
		cout << "!!!�г��� �ִ� ���̸� �Ѿ���ϴ�. ĳ���� ������ �Ұ����մϴ�.!!!" << endl;
		goto CREATE;
	}

	UserName_copy.erase(remove(UserName_copy.begin(), UserName_copy.end(), ' '), UserName_copy.end());
	
	if (UserName_copy.length() <= 0)
	{
		cout << "!!!�г����� �������� �̷���� �ֽ��ϴ�. ĳ���� ������ �Ұ����մϴ�.!!!" << endl;
		goto CREATE;
	}

	PC = PlayerCharacter::GetInstance(UserName);

	while (PC->GetLevel() < 10)
	{
		Monster* RoundMonster = GM->getnerateMonster(PC->GetLevel());

		cout << endl;
		cout << "\"" << RoundMonster->GetName() << "\"��(��) �����Ǿ����ϴ�!" << endl;

		GM->battle(PC, RoundMonster);

		delete RoundMonster;
	}

	cout << "�ִ� ���� ����" << endl;

	delete PC;
	delete GM;

	return 0;
}