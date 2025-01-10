#pragma once

#include <string>

using namespace std;

class Item
{
public:
	virtual string GetName() = 0;
	virtual void use(class PlayerCharacter* inPlayerCharacter) = 0;
};

