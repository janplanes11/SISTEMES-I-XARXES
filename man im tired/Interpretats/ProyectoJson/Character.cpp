#include "Character.h"

Json::Value Character::Encode()
{
    Json::Value json;

    json["life"] = life;
    json["coin"] = coin;
    json["name"] = name;

    Json::Value weaponsArray = Json::Value(Json::arrayValue);

    for (Weapon* weapon : *weapons) {
        weaponsArray.append(weapon->Encode());
    }
    json["weapons"] = weaponsArray;
    return json;
}

Character* Character::Decode(Json::Value json)
{
    Character* c = new Character();
    c->life = json["life"].asInt();
    c->coin = json["coin"].asInt();
    c->name = json["name"].asString();
    Json::Value weaponsArray = json["weapons"];
    for (Json::Value weaponsJson : weaponsArray) {
        Weapon* weapon = Weapon::Decode(weaponsJson);
        c->weapons->push_back(weapon);
    }
    return c;
}
