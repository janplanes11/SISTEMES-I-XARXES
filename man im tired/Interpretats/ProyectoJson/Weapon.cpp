#include "Weapon.h"
#include "Lance.h"
#include "Sword.h"
Json::Value Weapon::Encode()
{
	Json::Value json = Json::Value();
	json["damage"] = damage;

    return Json::Value();
}

Weapon* Weapon::Decode(Json::Value json)
{
    weaponType type = (weaponType)json["type"].asInt();
	Weapon* weapon = nullptr;
	switch (type)
	{
	case Weapon::UNKNOWN:
		return nullptr;
		break;
	case Weapon::SWORD:
		weapon =  Sword::Decode(json);
		break;
	case Weapon::Lance:
		weapon = Lance::Decode(json);
		break;
	default:
		return nullptr;
		break;
	}
	weapon->type = type;
	weapon-> damage = json["damage"].asInt();
	weapon-> range = json["range"].asInt();
	
	return weapon;
}
