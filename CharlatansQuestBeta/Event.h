#ifndef EVENT_H
#define EVENT_H

#include "Player.h"
#include "Loot.h"
#include "Combat.h"

#include <string>
#include <iostream>


class Event
{
    public:
        Event();
        virtual ~Event();

        void initEvent(int idEvent);
        void describe(Player &player);
        void execute(Player &player);

    protected:

    private:
        int _gold;
        int _damage;
        int _presence;
        int _loot;
        std::string _name;
        std::string _display;
        std::string _event;
};

#endif // EVENT_H
