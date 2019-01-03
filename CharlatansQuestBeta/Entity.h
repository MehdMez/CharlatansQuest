#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

class Entity
{
    public:
        Entity();
        virtual ~Entity();
        virtual bool isAlive();
        virtual void takeDamage(int dgt);
        virtual void dealDamage(Entity &cible, int degats, int nbrAtk);
        //void attaqueBase(Entity &cible);


        virtual std::string getName();

        virtual int getLifeMax();
        virtual void modifLifeMax(int lifeMaxModif);
        virtual int getLifeActual();
        virtual void modifLifeActual(int lifeModif);
        virtual int getManaMax();
        virtual void modifManaMax(int manaMaxModif);
        virtual int getManaActual();
        virtual void modifManaActual(int manaModif);
        virtual int getResilience();
        virtual void modifResilience(int resiModif);
        virtual int getAtk();
        virtual void modifAtk(int atkModif);
        virtual int getDef();
        virtual void modifDef(int defModif);
        virtual int getBonusAtk();
        virtual void modifBonusAtk(int bonusAtkModif);
        virtual int getBonusDef();
        virtual void modifBonusDef(int bonusDefModif);

        virtual int getStatus();
        virtual int getStatusCount();
        virtual void setStatus(int statusInflicted, int statusTime);
        virtual void clearStatus();

      //  void setName(std::string newName);

    protected:
        std::string _EntityName;
        int _lifeMax;
        int _lifeActual;
        int _manaMax;
        int _manaActual;
        int _resilience;
        int _atk;
        int _def;
        int _bonusAtk;
        int _bonusDef;
        int _nbrAtk;    //plus utilisé ?
        int _status;
        int _ctrStatus;
         //int _degatsStatus;

    private:


};

#endif // ENTITY_H
