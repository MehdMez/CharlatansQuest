#include "Weapon.h"

Weapon::Weapon(){

}

Weapon::Weapon(std::string nameWeaponBase, int bAtkWeaponBase, int bDefWeaponBase)
{
    //ctor
    _equipmentName = nameWeaponBase;
    _bonusAtk = bAtkWeaponBase;
    _bonusDef = bDefWeaponBase;
    _type = 1;
}

Weapon::~Weapon()
{
    //dtor
}
