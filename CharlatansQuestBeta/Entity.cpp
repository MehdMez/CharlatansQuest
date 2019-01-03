#include "Entity.h"

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}

void Entity::takeDamage(int dgt){
    int damageTaken = dgt-(_def+_bonusDef);
    if(damageTaken > 0){
        if(_lifeActual > damageTaken){
            _lifeActual -= damageTaken;
        }else if(_lifeActual > 0 && _lifeActual <= damageTaken){
            _resilience -= (damageTaken-_lifeActual);
            _lifeActual = 0;
        }else if(_lifeActual ==0){
            _resilience -= damageTaken;
        }
    }

    if(_lifeActual == 0 && _resilience <=0){
        // si jamais l'ennemi attaque plusieurs fois et que la cible meurt avant la dernière atk.
        std::cout << _EntityName << " died." << std::endl;
        _lifeActual = -1;
    }

}


void Entity::dealDamage(Entity &target, int degats, int nbrAtk){
    int damageDealt = degats+_bonusAtk;
    int defTarget = target.getDef()+target.getBonusDef();
    if(defTarget < 0){
        defTarget = 0;
    }
    for(int i = 0; i < nbrAtk; i++){
        std::cout << _EntityName << " attacks and deals " << damageDealt-defTarget << " (" << defTarget
                << " blocked) to ";
        if(!target.isAlive()){std::cout << "dead ";}
        std::cout << target.getName() << "." << std::endl;
        target.takeDamage(damageDealt);
    }
}

bool Entity::isAlive(){
    if(_lifeActual <=0 && _resilience <=0){
        std::cout << _EntityName << " is dead." << std::endl;
        return false;
    }else{
        return true;
    }
}

void Entity::clearStatus(){
    if(_ctrStatus == 0){
        _status = 0;
    }else{
        _ctrStatus--;
    }
}


std::string Entity::getName(){
    return _EntityName;
}

int Entity::getLifeMax(){
    return _lifeMax;
}

void Entity::modifLifeMax(int lifeMaxModif){
    _lifeMax += lifeMaxModif;
}

int Entity::getLifeActual(){
    return _lifeActual;
}

void Entity::modifLifeActual(int lifeModif){
    _lifeActual += lifeModif;
}

int Entity::getManaMax(){
    return _manaMax;
}

void Entity::modifManaMax(int manaMaxModif){
    _manaMax += manaMaxModif;
}

int Entity::getManaActual(){
    return _manaActual;
}

void Entity::modifManaActual(int manaModif){
    _manaActual += manaModif;
}

int Entity::getResilience(){
    return _resilience;
}

void Entity::modifResilience(int resiModif){
    _resilience += resiModif;
}

int Entity::getAtk(){
    return _atk;
}

void Entity::modifAtk(int atkModif){
    _atk += atkModif;
}

int Entity::getDef(){
    return _def;
}

void Entity::modifDef(int defModif){
    _def += defModif;
}

int Entity::getBonusAtk(){
    return _bonusAtk;
}

void Entity::modifBonusAtk(int bonusAtkModif){
    _bonusAtk += bonusAtkModif;
}

int Entity::getBonusDef(){
    return _bonusDef;
}

void Entity::modifBonusDef(int bonusDefModif){
    _bonusDef = bonusDefModif;
}

int Entity::getStatus(){
    return _status;
}

int Entity::getStatusCount(){
    return _ctrStatus;
}

void Entity::setStatus(int statusInflicted, int statusTime){
    _status = statusInflicted;
    _ctrStatus = statusTime;
}
