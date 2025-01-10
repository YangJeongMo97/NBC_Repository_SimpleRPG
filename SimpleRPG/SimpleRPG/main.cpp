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
	cout << "캐릭터 생성-------------------------------------" << endl;
	cout << "닉네임 입력(16자 이내) : ";
	getline(cin, UserName);

	UserName_copy = UserName;

	if (LETTER_COUNT(UserName) > 16)
	{
		cout << "!!!닉네임 최대 길이를 넘어섰습니다. 캐릭터 생성이 불가능합니다.!!!" << endl;
		goto CREATE;
	}

	UserName_copy.erase(remove(UserName_copy.begin(), UserName_copy.end(), ' '), UserName_copy.end());
	
	if (UserName_copy.length() <= 0)
	{
		cout << "!!!닉네임이 공백으로 이루어져 있습니다. 캐릭터 생성이 불가능합니다.!!!" << endl;
		goto CREATE;
	}

	PC = PlayerCharacter::GetInstance(UserName);

	while (PC->GetLevel() < 10)
	{
		Monster* RoundMonster = GM->getnerateMonster(PC->GetLevel());

		cout << endl;
		cout << "\"" << RoundMonster->GetName() << "\"이(가) 스폰되었습니다!" << endl;

		GM->battle(PC, RoundMonster);

		delete RoundMonster;
	}

	cout << "최대 레벨 도달" << endl;

	delete PC;
	delete GM;

	return 0;
}