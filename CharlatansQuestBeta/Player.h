#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "OffensifTechnique.h"
#include "Weapon.h"
#include "Armor.h"

#include <string>
#include <iostream>
#include <map>

class Player : public Entity
{
    public:
        Player();
        virtual ~Player();

        void classChoice();
        void switchArmor(int idArmor);
        void switchWeapon(int idWeapon);
        void displayArmorAndWeapon();
        void displayInventory();
        void displayStatus();
        void atkMenu(Entity &cible);
        void usePotion();
        void stressAtMax();

        int getGold();
        void modifGold(int gold);
        int getLifePotions();
        void modifLifePotion(int lifePotion);
        int getManaPotions();
        void modifManaPotion(int manaPotion);
        int getKeys();
        void modifKeys(int keys);
        int getAntidotes();
        void modifAntidote(int antidote);
        int getBlueprints();
        void modifBluePrints(int newBluePrints);
        int getStress();
        int getStressMax();
        void modifStress(int stressModif);
        int getDetection();
        void modifDetection(int detectmodif);

    protected:

    private:
        int _detection;
  //      int _bonusWeapon;
  //      int _bonusArmor;
        int _blueprints;
		int _stress;
		int _stressMax;
        std::map<std::string, int> _inventory;   //MPotions, LPotions, Keys, Antidote, Gold

		Weapon equipedWeapon;
        Armor equipedArmor;
        OffensifTechnique tech1;
        OffensifTechnique tech2;
        OffensifTechnique tech3;
        OffensifTechnique tech4;
};

#endif // PLAYER_H
