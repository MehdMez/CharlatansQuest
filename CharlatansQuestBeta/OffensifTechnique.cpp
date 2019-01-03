#include "OffensifTechnique.h"

/*
        void UseOffTechnique(Entity &player, Entity &cible);
        std::string getAtkName();
        float getAtkStrenght();
        int getAtkNbr();
        int getManaCost();
        void modifTech(std::string newName, int newManaCost, float newAttDeg, int newAttNbr, int newStatusInflicted, int newStatusCtr);
*/

OffensifTechnique::OffensifTechnique(std::string techName, int manaCost, float attDmg, int attNbr, int statusInflicted, int statusCtr)
{
    //ctor
    _atkName = techName;
    _manaCost = manaCost;
    _atkStrenght = attDmg;
    _atkNbr = attNbr;
    _statusInflicted = statusInflicted;
    _counterStatusInflicted = statusCtr;
}

OffensifTechnique::~OffensifTechnique()
{
    //dtor
}

void OffensifTechnique::UseOffTechnique(Entity &activeEntity, Entity &target){
    activeEntity.dealDamage(target, activeEntity.getAtk()*_atkStrenght, _atkNbr);
    target.setStatus(_statusInflicted,_counterStatusInflicted);
    if(_atkName == "Eureka !"){
            //test, voir si ça marche, cible meurt
            target.modifLifeActual(0);
        }else if(_atkName == "Empale"){
            // se blesse en attaquant
            activeEntity.modifLifeActual(-2);
            std::cout << "The Fakir wounds itself with Empale for 2." << std::endl;
        }else if(_atkName == "Rain of whip"){
            activeEntity.setStatus(2,2);
            std::cout << "The Fakir bleeds." << std::endl;
            // se fait saigner aussi
        }else if(_atkName == "Revel"){
            // gagne bonus d'atk en fct de vie perdu
            std::cout << "Pain is life. Pain is strength. The Fakir gains an amount of bonusAtk equal to "
                << (activeEntity.getLifeMax()-activeEntity.getLifeActual())/5 << std::endl;
            activeEntity.modifBonusAtk((activeEntity.getLifeMax()-activeEntity.getLifeActual())/5);
        }else if(_atkName == "Shadow Daggers"){
            while(activeEntity.getManaActual()>0){
                std::cout << activeEntity.getName() << " throws a dagger made of shadow. " << target.getName()
                    << " takes " << activeEntity.getAtk() << " damages (not reduced by " << target.getName() << "'s def)." << std::endl;
                if(target.getLifeActual() >=2){
                    target.modifLifeActual(activeEntity.getAtk());
                }else{
                    target.modifLifeActual(0);
                    target.modifResilience(activeEntity.getAtk());
                }
                activeEntity.modifManaActual(-2);
            }
            if(activeEntity.getManaActual() < 0){
                activeEntity.modifManaActual(0);
            }
        }
}

void OffensifTechnique::modifTech(std::string newName, int newManaCost, float newAttDmg, int newAttNbr, int newStatusInflicted, int newStatusCtr){
    _atkName = newName;
    _manaCost = newManaCost;
    _atkStrenght = newAttDmg;
    _atkNbr = newAttNbr;
    _statusInflicted = newStatusInflicted;
    _counterStatusInflicted = newStatusCtr;
}


std::string OffensifTechnique::getAtkName(){
    return _atkName;
}

float OffensifTechnique::getAtkStrenght(){
    return _atkStrenght;
}

int OffensifTechnique::getAtkNbr(){
    return _atkNbr;
}

int OffensifTechnique::getManaCost(){
    return _manaCost;
}
