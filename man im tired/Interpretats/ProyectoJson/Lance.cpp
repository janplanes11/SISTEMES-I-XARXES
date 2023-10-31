#include "Lance.h"

Lance::Lance(std::string type)
{
	damage = 1;
	range = 2;
	this->woodType = type;

}
Lance* Lance::Decode(Json::Value json) {
	std::string wood = json["woodType"].asString();
	Lance* lance = new Lance(wood);
	return lance;
}
Json::Value Lance::Encode()  {
	Json::Value json = Weapon::Encode();
	json["woodType"] = woodType;
	return json;
}