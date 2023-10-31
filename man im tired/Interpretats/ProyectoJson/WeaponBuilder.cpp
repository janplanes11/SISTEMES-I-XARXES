#include "WeaponBuilder.h"


 Weapon* WeaponBuilder::CreateWeaponFromJson(Json::Value json)
{
	Weapon::weaponType type = (Weapon::weaponType)json["type"].asInt();

	Weapon* weapon = nullptr;
	switch (type)
	{
	case Weapon::UNKNOWN:
		return nullptr;
		break;
	case Weapon::SWORD:
		weapon = Sword::Decode(json);
		break;
	case Weapon::Lance:
		weapon = Lance::Decode(json);
		break;
	default:
		return nullptr;
		break;
	}
	weapon->type = type;
	weapon->damage = json["damage"].asInt();
	weapon->range = json["range"].asInt();

	return weapon;
}
