#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <vector>
#include <iostream>
//#include <fstream>
//#include <sstream>

#include "StaticFunctions.h"

class Equipment
{
    public:
        Equipment();
        virtual ~Equipment();
        void initEquipment(int idEquip, int type);
        std::vector<std::string> readEquipmentFile(int idEquip, int type);
        void changeEquipment(int newID);
        void displayE();

    protected:
        int _type;
        std::string _equipmentName;
        int _bonusAtk;
        int _bonusDef;
        //int specialEffect;

    private:
};

#endif // EQUIPMENT_H
