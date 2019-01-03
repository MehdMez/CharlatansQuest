#ifndef ROOMS_H
#define ROOMS_H

#include <string>
#include <iostream>
#include <fstream>

/* Sleep non fonctionnel
#include <stdlib.h>
#include <unistd.h>
*/

#include "StaticFunctions.h"
#include "Player.h"
#include "Combat.h"
#include "Monster.h"
#include "Shrine.h"

class Rooms
{
    public:
        Rooms();
        ~Rooms();

        std::vector<std::string> readRoomFile(int idRoom);
        void initRoom(int idRoom);
        void enterRoom(Player &player);
        void choicePostRoom(Player &player);
        void nextRoomChoice(int scout, int nbrPath);
        void scoutRoom(int scout, int idNewRoom);
        void checkForVillageois();

    /* à supprimer
    void choiceAfterRoom(Player &player);
    void intro();
    void choiceNextRoom(Player &player);
    void freeCitizen();
    void displayRoom();
    void changeRoom(int  id);
    int bonusChoice(int  idBonus);
    void unlockChest();
    void setRoom(std::string  file);*/

    private:
        // int _idRoom;
        std::string _roomName;
        int _roomType;
        int _levelDanger;
        int _ifRest; // vie rendu quand rest dans cette pièc
        int _nbrEnemy;
        int _isThereVillageois; // et oui, VILLAGEOIS ! Int pour donner lequel est retrouvé
        int _idSearch;
        int _ifScout;
        int _nbrPaths;
};




#endif // ROOMS_H
