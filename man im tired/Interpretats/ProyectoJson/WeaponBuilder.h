#pragma once
#include <json/json.h>
#include "Weapon.h"
#include "Sword.h"
#include "Lance.h"
class WeaponBuilder
{
public :
	static Weapon* CreateWeaponFromJson(Json::Value json);
};

