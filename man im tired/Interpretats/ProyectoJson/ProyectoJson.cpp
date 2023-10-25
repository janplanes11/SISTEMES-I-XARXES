
#include <iostream>
#include <json/json.h>
#include "Character.h"
#include <fstream>

void CreateBaseCharacter();
void ReadBaseCharacter();

int main()
{
    std::cout << "Hello World!\n";
    CreateBaseCharacter();
    ReadBaseCharacter();
}


void CreateBaseCharacter() 
{
    Character* character = new Character();
    character->life = 5;
    character->coin = 5;
    character->name = "TurboSexo";
    Sword* sword = new Sword("Plateada");
    Lance* lance0 = new Lance("Mahogany");
    Lance* lance1 = new Lance("Pino");
    character->weapons->push_back(sword);
    character->weapons->push_back(lance0);
    character->weapons->push_back(lance1);
    Json::Value json;
    /*json["life"] = character->life;
    json["coin"] = character->coin;
    json["name"] = character->name;*/
    json["Character"] = character->Encode();

    std::ofstream jsonWritFile =  std::ofstream("Character.json", std::ofstream::binary);

    if (!jsonWritFile.fail()) {
        jsonWritFile << json;
        jsonWritFile.close();
    }


}

void ReadBaseCharacter()
{
    Character c;
    c.name = "name";
    
    Character* character = new Character();

    std::ifstream jsonReadFile = std::ifstream("Character.json", std::ifstream::binary);
    if (!jsonReadFile.fail()) {
        Json::Value json;
        jsonReadFile >> json;
        jsonReadFile.close();

        Character* character = Character::Decode(json["Character"]);
    }
}


