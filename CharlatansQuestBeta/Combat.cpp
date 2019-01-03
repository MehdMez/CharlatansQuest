#include "Combat.h"

Combat::Combat()
{
    //ctor
}

Combat::~Combat()
{
    //dtor
}

// modifié les arguments, prends un seul perso à chaque fois.
void Combat::displayHP(Entity &entity){
    if(entity.isAlive() && entity.getResilience()>0){
        std::cout << entity.getName() << " has " << entity.getLifeActual() << "/" << entity.getLifeMax()
            << "HP and " << entity.getResilience() << " resilience." << std::endl;
    }else if(entity.isAlive() && entity.getResilience() <= 0){
        std::cout << entity.getName() << " has " << entity.getLifeActual() << "/" << entity.getLifeMax()
            << "HP." << std::endl;
    }else{
        std::cout << entity.getName() << " is dead." << std::endl;
    }
}

/*
    Je tente en créant l'ennemi dans la méthode même.
        Puisqu'on en a besoin que dedans et pas en dehors pour les salles sans ennemi.
    Je testerai ainsi pour pouvoir faire des combats avec plusieurs ennemis.
        Ou le joueur pourrait choisir quel ennemi attaquer.
*/
void Combat::fightControl(Player &player, Monster &monster){

    if(monster.getInitiative() == 1){
        std::cout << monster.getName() << " has first strike !" << std::endl;
        monster.monsterATKmenu(player);
        StaticEvents::stressPlusOneAtRandom(player);
    }

    while(player.isAlive() && monster.isAlive()){
        displayHP(player);
        displayHP(monster);

        player.atkMenu(monster);

        if(monster.getStatus() != 1 && monster.isAlive()){
            monster.monsterATKmenu(player);
            StaticEvents::stressPlusOneAtRandom(player);
        }else if(monster.getStatus()==1 && monster.isAlive()){
            std::cout << monster.getName() << " is stunned and cannot attack." << std::endl;
        }
        player.clearStatus();
        player.stressAtMax();
        player.stressAtMax();
        monster.clearStatus();
        std::cout<<"All ennemies are dead"<<std::endl;
        std::cout << std::endl << std::endl;
    }
}

void Combat::fightControl2Enemy(Player &player, Monster &monster, Monster &monster2){
    int target;

    if(monster.getInitiative() == 1){
        std::cout << monster.getName() << " has first strike !" << std::endl;
        monster.monsterATKmenu(player);
        StaticEvents::stressPlusOneAtRandom(player);
    }
    if(monster2.getInitiative() == 1){
        std::cout << monster2.getName() << " has first strike !" << std::endl;
        monster2.monsterATKmenu(player);
        StaticEvents::stressPlusOneAtRandom(player);
    }

    while(player.isAlive() && monster.isAlive() || player.isAlive() && monster2.isAlive()){
        displayHP(player);
        displayHP(monster);
        displayHP(monster2);
        if(monster.isAlive() && monster2.isAlive()){
            std::cout << "Qui attaquer ? 1. " << monster.getName() << " ou 2. " << monster2.getName() << " ?" << std::endl;
            std::cin >> target;
            if(target == 1){
                player.atkMenu(monster);
            }else{
                player.atkMenu(monster2);
            }

            std::cout << std::endl;
            if(monster.getStatus() != 1 && monster.isAlive()){
                monster.monsterATKmenu(player);
                StaticEvents::stressPlusOneAtRandom(player);
            }else if(monster.getStatus() == 1 && monster.isAlive()){
                std::cout << monster.getName() << " is stunned and cannot attack." << std::endl;
            }
            if(monster2.getStatus() != 1 && monster2.isAlive()){
                monster2.monsterATKmenu(player);
                StaticEvents::stressPlusOneAtRandom(player);
            }else if(monster2.getStatus() == 1 && monster2.isAlive()){
                std::cout << monster2.getName() << " is stunned and cannot attack." << std::endl;
            }
            player.clearStatus();
            player.stressAtMax();
            monster.clearStatus();
            monster2.clearStatus();
            std::cout << std::endl << std::endl;
        }else if(monster.isAlive() && !monster2.isAlive()){
            fightControl(player, monster);
        }else if(!monster.isAlive() && monster2.isAlive()){
            fightControl(player, monster2);
        }
    }
}

void Combat::fightControl3Enemy(Player &player, Monster &monster, Monster &monster2, Monster &monster3){
    int target;
    if(monster.getInitiative() == 1){
        std::cout << monster.getName() << " has first strike !" << std::endl;
        monster.monsterATKmenu(player);
        StaticEvents::stressPlusOneAtRandom(player);
    }
    if(monster2.getInitiative() == 1){
        std::cout << monster2.getName() << " has first strike !" << std::endl;
        monster2.monsterATKmenu(player);
        StaticEvents::stressPlusOneAtRandom(player);
    }
    if(monster3.getInitiative() == 1){
        std::cout << monster3.getName() << " has first strike !" << std::endl;
        monster3.monsterATKmenu(player);
        StaticEvents::stressPlusOneAtRandom(player);
    }

    while((player.isAlive() && monster.isAlive()) || (player.isAlive() && monster2.isAlive())
          || (player.isAlive() && monster3.isAlive())){
        displayHP(player);
        displayHP(monster);
        displayHP(monster2);
        displayHP(monster3);
        if(monster.isAlive() && monster2.isAlive() && monster3.isAlive()){
            std::cout << "Qui attaquer ? 1. " << monster.getName() << " ou 2. " << monster2.getName()
                    << " ou 3. " << monster3.getName() << " ?" << std::endl;
            std::cin >> target;
            if(target == 1){
                player.atkMenu(monster);
            }else if(target == 2){
                player.atkMenu(monster2);
            }else{
                player.atkMenu(monster3);
            }

            std::cout << std::endl;
            if(monster.getStatus() != 1 && monster.isAlive()){
                monster.monsterATKmenu(player);
                StaticEvents::stressPlusOneAtRandom(player);
            }else if(monster.getStatus() == 1 && monster.isAlive()){
                std::cout << monster.getName() << " is stunned and cannot attack." << std::endl;
            }

            if(monster2.getStatus() != 1 && monster2.isAlive()){
                monster2.monsterATKmenu(player);
                StaticEvents::stressPlusOneAtRandom(player);
            }else if(monster2.getStatus() == 1 && monster2.isAlive()){
                std::cout << monster2.getName() << " is stunned and cannot attack." << std::endl;
            }

            if(monster3.getStatus() != 1 && monster3.isAlive()){
                monster3.monsterATKmenu(player);
                StaticEvents::stressPlusOneAtRandom(player);
            }else if(monster3.getStatus() == 1 && monster3.isAlive()){
                std::cout << monster3.getName() << " is stunned and cannot attack." << std::endl;
            }
            player.clearStatus();
            player.stressAtMax();
            monster.clearStatus();
            monster2.clearStatus();
            monster3.clearStatus();
       // player.displayStatus();
            std::cout << std::endl << std::endl;
        }else if(monster.isAlive() && monster2.isAlive() && !monster3.isAlive()){
            fightControl2Enemy(player, monster, monster2);
        }else if(monster.isAlive() && !monster2.isAlive() && monster3.isAlive()){
            fightControl2Enemy(player, monster, monster3);
        }else if(!monster.isAlive() && monster2.isAlive() && monster3.isAlive()){
            fightControl2Enemy(player, monster2, monster3);
        }
    }
}

