//
// Created by sean on 01/01/2021.
//

#ifndef MORRIS_RUNTIME_H
#define MORRIS_RUNTIME_H

#include <vector>
#include <stack>
#include <iostream>

#include "../common/Instructions.h"
#include "../common/Location.h"

// ---------------------------------------------------------------------------

class VM {
public:
    VM(std::vector<Location> I, std::vector<Location> D) {
        instructions = I;
        data = D;

        state = PENDING;
        instructionPointer = 0LL;
        stackPointer = Location(0.0);
        stackFrame = Location(0.0);
    }

    ~VM(){
    }

    enum State {
        PENDING,
        RUNNING,
        PAUSED,
        HALTED,
        ERROR
    };

    void DumpInstructions() {
        for (auto V : this->instructions) {
            std::cout << V.instruction << std::endl;
        }
    }

    void DumpData() {
        if (this->data.size() != 0) {
            for (auto V : this->data) {
                std::cout << V.value << std::endl;
            }
        }
    }

    void Execute(unsigned int slice=10);

    void incrProgramCounter()                   { instructionPointer++; }

    Location getCurrentLocation()               { return instructions[instructionPointer]; }
    INSTR getCurrentInstruction()               { return getCurrentLocation().instruction; }
    unsigned long int getCurrentAddress()       { return getCurrentLocation().address; }
    double getCurrentValue()                    { return getCurrentLocation().value; }

    void InstructionsPush(Location V)           { instructions.emplace(instructions.end(), V); }
    void InstructionsPush(INSTR V)              { instructions.emplace(instructions.end(), Location(V)); }
    void InstructionsPush(unsigned long int V)  { instructions.emplace(instructions.end(), Location(V)); }
    void InstructionsPush(double V)             { instructions.push_back(V);}

    State state;
    unsigned int slice;

    unsigned long int instructionPointer;
    Location stackPointer;
    Location stackFrame;
    std::vector<Location> instructions;
    std::stack<Location> stack;
    std::vector<Location> data;
};

// ---------------------------------------------------------------------------

#endif //MORRIS_RUNTIME_H
