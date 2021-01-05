//
// Created by sean on 04/01/2021.
//

#ifndef MORRIS_LOCATION_H
#define MORRIS_LOCATION_H

#include <vector>
#include <stack>
#include <iostream>
#include "Instructions.h"

class Location {

public:
    enum Type {NONE, INS, ADDR, VAL};

    Location() : instruction(NOP), address(0l), value(0.0) {}
    Location(INSTR V) : type(INS), instruction(V) {}
    Location(unsigned long int V) : type(ADDR), address(V) {}
    Location(double V) : type(VAL), value(V) {}

    ~Location() {}

    Type type;
    INSTR instruction;
    unsigned long int address;
    double value;
};

#endif //MORRIS_LOCATION_H
