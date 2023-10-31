#include "Sword.h"

Sword::Sword(std::string newcolor)
{
	damage = 2;
	range = 1;
	this->color = newcolor;
}

Sword* Sword::Decode(Json::Value json) {
	std::string color = json["color"].asString();
	Sword* sword = new Sword(color);
	return sword;
}
Json::Value Sword::Encode() {
	Json::Value json = Weapon::Encode();
	json["color"] = color;
	return json;
}
