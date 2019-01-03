#include "Armor.h"


Armor::Armor(){

}

Armor::Armor(std::string nameArmorBase, int bAtkArmorBase, int bDefArmorBase)
{
    //ctor
    _equipmentName = nameArmorBase;
    _bonusAtk = bAtkArmorBase;
    _bonusDef = bDefArmorBase;
    _type = 1;
}

Armor::~Armor()
{
    //dtor
}
