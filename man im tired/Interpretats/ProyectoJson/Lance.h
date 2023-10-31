#pragma once
#include "Weapon.h"
#include <string>
class Lance : public Weapon
{
public:
	std::string woodType = "";
	Lance(std::string woodType);
	static Lance* Decode(Json::Value json);
	Json::Value Encode() override;
};

