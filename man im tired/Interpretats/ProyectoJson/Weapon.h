#pragma once
#include "dist/json/json.h"
class Weapon
{
public: 
	enum weaponType {
		UNKNOWN = 0, SWORD = 1, Lance = 2
	};
	int damage = 0;
	int range = 0;
	weaponType type = UNKNOWN;
	Json::Value Encode();
	static Weapon* Decode(Json::Value json);
};

