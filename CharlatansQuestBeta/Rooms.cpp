#include "Rooms.h"

Rooms::Rooms()
{
    //ctor
}

Rooms::~Rooms()
{
    //dtor
}

std::vector<std::string> Rooms::readRoomFile(int idRoom){
    std::ifstream inFile;
    inFile.open("Room_file.txt");

    if (!inFile) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);
    }else{
        std::string line;

        inFile.seekg(std::ios::beg);
        for(int i=0; i < idRoom - 1; ++i){
        //    inFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            inFile.ignore(1000,'\n');
        }
        std::getline(inFile, line);

        std::vector<std::string> readRoom = StaticFunctions::split(line, ':');
        inFile.close();
        return readRoom;
    }
}

void Rooms::initRoom(int idRoom){
    std::vector<std::string> roomInit = readRoomFile(idRoom);

    _roomName = roomInit[0];
    _roomType = std::stoi(roomInit[1]);
    _levelDanger = std::stoi(roomInit[2]);
    _ifRest = std::stoi(roomInit[3]);
    _nbrEnemy = std::stoi(roomInit[4]);
    _isThereVillageois = std::stoi(roomInit[5]);
    _idSearch = std::stoi(roomInit[6]);
    _ifScout = std::stoi(roomInit[7]);
    _nbrPaths = std::stoi(roomInit[8]);

}

void Rooms::enterRoom(Player &player){
    std::cout << "You enter " << _roomName << std::endl;
    if(_roomType == 0){
        std::cout << "It appears empty" << std::endl;
        //Salle vide
        choicePostRoom(player);
        enterRoom(player);
    }else if(_roomType == 1){
        //std::cout << "A shrine of the Gods" << std::endl;
        //shrine
        Shrine autel;
        autel.initShrine(player);
        choicePostRoom(player);
        enterRoom(player);
    }else if(_roomType == 2){
        std::cout << "A treasure room !" << std::endl;
        //coffre

        choicePostRoom(player);
        enterRoom(player);
    }else if(_roomType == 3){
        //ennemi !
        Combat c;
        std::cout << "Ready yourself, a fight has began !" << std::endl;
        if(_nbrEnemy == 1){
            Monster m;
            m.initMonster(rand()%5 + 1);
            c.fightControl(player, m);
        }else if(_nbrEnemy == 2){
            Monster m;
            m.initMonster(rand()%5 + 1);
            Monster m2;
            m.initMonster(rand()%5 + 1);
            c.fightControl2Enemy(player, m, m2);
        }else{
            Monster m;
            m.initMonster(rand()%5 + 1);
            Monster m2;
            m.initMonster(rand()%5 + 1);
            Monster m3;
            m3.initMonster(rand()%5 + 1);
            c.fightControl3Enemy(player, m, m2, m3);
        }

        choicePostRoom(player);
        enterRoom(player);
    }else{
        // Marchand
    }
}

void Rooms::choicePostRoom(Player &player){
    int choice;
    std::cout<< "You can 1. Rest (heal for " << _ifRest << "hp), 2. Search for loot or 3. Scout ahead" << std::endl;
    std::cin >> choice;

    if(choice == 3){
        //scouting => bonus à la detection de la salle suivante
        nextRoomChoice(player.getDetection()+3, _nbrPaths);
    }else if(choice == 1){
        // repos
        player.modifLifeActual(_ifRest);
        std::cout << "You rested you weary soul and gained " << _ifRest << " hp." << std::endl;
        if(_roomType == 0 && player.getStress()>0){
            // si la pièce est  vide, se reposer diminue le stress du joueur de 1.
            player.modifStress(-1);
            std::cout << "The emptiness of the room calms your nerves. Stress -1" << std::endl;
        }else if(_roomType == 1 && player.getStress()>0){
            // si la pièce est un autel, se reposer diminue le stress du joueur de 1.
            player.modifStress(-3);
            std::cout << "The gods have not forsaken you. Stress -3";
        }
        nextRoomChoice(player.getDetection(), _nbrPaths);
    }else if(choice == 2){
        //search
        std::cout << "LOOTING NOT INCLUDED" << std::endl;
        nextRoomChoice(player.getDetection(), _nbrPaths);
    }
}

void Rooms::nextRoomChoice(int scout, int nbrPath){
    int room1 = rand()%7 + 1;
    int room2 = rand()%7 + 1;
    int choice;

    switch(nbrPath){
        case 1:
            std::cout << "You can only see one door." << std::endl;
            std::cout << "Not much choice" << std::endl << "1. ";
            scoutRoom(scout, room1);
            std::cin >> choice;
            initRoom(room1);
            break;
        case 2:
            std::cout << "You see two doors" << std::endl;
            std::cout << "1. ";
            scoutRoom(scout, room1);
            std::cout << "2. ";
            scoutRoom(scout, room2);
            std::cin >> choice;
            if(choice == 1){
                initRoom(room1);
            }else{
                initRoom(room2);
            }
            break;
        case 3:
            int room3 = rand()%7 + 1;
            std::cout << "You see three doors" << std::endl;
            std::cout << "1. ";
                scoutRoom(scout, room1);
            //    std::cout << std::endl;
            std::cout << "2. ";
                scoutRoom(scout, room2);
            //    std::cout << std::endl;
            std::cout << "3. ";
                scoutRoom(scout, room3);
            std::cin >> choice;
            if(choice == 1){
                initRoom(room1);
            }else if(choice == 2){
                initRoom(room2);
            }else{
                initRoom(room3);
            }
            break;
    }
}

void Rooms::scoutRoom(int scout, int idNewRoom){
    std::vector<std::string> scoutedRoom = readRoomFile(idNewRoom);
   // int malusScoutRoom = stoi(scoutedRoom[7]);

   // déterminer les displays des infos des salles suivantes
   // dans l'ordre nom / niveau de danger / nbr ennemi // si villageois
    int canScout = (rand()%4 + 1) + stoi(scoutedRoom[7]); //malusScoutRoom;
    int canScout2 = (rand()%7 + 1) + stoi(scoutedRoom[7]); //malusScoutRoom;
    int canScout3 = (rand()%7 + 1) + stoi(scoutedRoom[7]); //malusScoutRoom;
    int canScout4 = (rand()%7 + 1) + stoi(scoutedRoom[7]); //malusScoutRoom;

    if(scout >= canScout){
        std::cout << scoutedRoom[0] << "| ";
    }else{
        std::cout <<"??? ";
    }
        if(scout >= canScout2){
        std::cout<< std::stoi(scoutedRoom[2]) << " de danger| ";
    }else{
        std::cout <<"??? ";
    }
        if(scout >= canScout3){
        std::cout << stoi(scoutedRoom[4]) << "ennemis| ";
    }else{
        std::cout <<"???? ";
    }
        if(scout >= canScout4){
            if(stoi(scoutedRoom[5]) == 0){
                std::cout << "Pas de villageois." << std::endl;
            }else{
                std::cout << "Il y a un villageois !" << std::endl;
            }
    }else{
        std::cout<< "???" << std::endl;
    }
}

void Rooms::checkForVillageois(){
    if(_isThereVillageois == 1){
        //COMMENT RENVOYER VERS LES BATIMENTS ?
        // STATIC ?
    }
}
