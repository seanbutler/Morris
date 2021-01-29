//
// Created by sean on 04/01/2021.
//

// ----------------------------------------------------------------------

#ifndef MORRIS_LOCATION_H
#define MORRIS_LOCATION_H

// ----------------------------------------------------------------------

#include <vector>
#include <stack>
#include <iostream>
#include "Instructions.h"

// ----------------------------------------------------------------------

class Location {

public:
    enum Type {NONE, INS, ADDR, VAL, UINT, INT64};

    Location(INSTR V = INSTR::NOP) : type(INS), instruction(V)          {text = instructionNames[(int)instruction];}
    Location(unsigned long int V) : type(ADDR), address(V)              {text = "ADDR";}
    Location(double V) : type(VAL), value(V)                            {text = "VAL";}

    ~Location() {}

    Type type;
    INSTR instruction;
    unsigned long int address;
    double value;

    std::string text;
    std::string comment;

    friend std::ostream& operator<<(std::ostream& os, const Location & obj)
    {
        switch (obj.type)
        {
            case Location::Type::INS: {
                os << instructionNames[obj.instruction];
                break;
            }
            case Location::Type::ADDR: {
                os << obj.address;
                break;
            }
            case Location::Type::VAL: {
                os << obj.value;
                break;
            }
        }
        return os;
    }
};

// ----------------------------------------------------------------------

#endif //MORRIS_LOCATION_H
