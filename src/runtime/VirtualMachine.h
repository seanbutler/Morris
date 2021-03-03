//
// Created by sean on 01/01/2021.
//

#ifndef MORRIS_VIRTUALMACHINE_H
#define MORRIS_VIRTUALMACHINE_H

#include <vector>
#include <stack>
#include <iostream>

//#include "../Simulation/Agent.h"

#include "../common/Instructions.h"
#include "../common/Location.h"

// ---------------------------------------------------------------------------
class Agent;

namespace Runtime {

    class VM {

    public:
        VM(std::pair<std::vector<Location>, std::vector<std::string>> P, unsigned int D = 16)
        :   owner(nullptr)
        ,   instructions(P.first)
        ,   stringTable(P.second)
        {
            data = std::vector<Location>();
            for (int n = 0; n < D; n++) {
                data.push_back(Location(0.0));
            }
            state = RUNNING;
            instructionPointer = 0LL;
            //        stackPointer = Location(0.0);
            //        stackFrame = Location(0.0);
            owner = 0l;
        }

        ~VM() {
        }

        enum State {
            PENDING,
            RUNNING,
            PAUSED,
            HALTED,
            ERROR
        };

        void DumpRegs() {
            std::cout << "REGS ";
            std::cout << "state " << state << " ";
            std::cout << "slice " << slice << " ";
            std::cout << "IP " << instructionPointer << " ";
            //        std::cout << "SP " << stackPointer << " ";
            //        std::cout << "FP " << stackFrame << " ";
            std::cout << std::endl;
        }

        void DumpInstructions() {
            std::cout << "INSTR [ ";

            for (auto V : this->instructions) {
                std::cout << V << " ";
            }
            std::cout << "]" << std::endl;
        }

        void DumpStrings() {
            std::cout << "STRINGS [ ";

            for (auto V : this->stringTable) {
                std::cout << V << " ";
            }
            std::cout << "]" << std::endl;
        }

        void DumpStack() {

            std::cout << "STACK " << this->stack.size() << " [ ";
//            for (auto V : this->stack) {
//                std::cout << V << " ";
//            }
            std::cout << "]" << std::endl;
        }

        void DumpData() {

            std::cout << "VM.data ";
            if (this->data.size() != 0) {
                for (auto V : this->data) {
                    std::cout << V.value << " ";
                }
                std::cout << std::endl;
            }
        }

        void SetOwner(Agent* O) {owner = O;}

        void Execute(unsigned int slice = 10);

        void incrProgramCounter() { instructionPointer++; }
        Location getCurrentLocation() { return instructions[instructionPointer]; }
        INSTR getCurrentInstruction() { return getCurrentLocation().instruction; }
        unsigned long int getCurrentAddress() { return getCurrentLocation().address; }
        double getCurrentValue() { return getCurrentLocation().value; }
        void InstructionsPush(Location V) { instructions.emplace(instructions.end(), V); }
        void InstructionsPush(INSTR V) { instructions.emplace(instructions.end(), Location(V)); }
        void InstructionsPush(unsigned long int V) { instructions.emplace(instructions.end(), Location(V)); }
        void InstructionsPush(double V) { instructions.push_back(V); }

        State state;
        unsigned int slice;

        unsigned long int instructionPointer;
        std::vector<Location> instructions;
        std::vector<Location> stack;
        std::vector<Location> data;
        std::vector<std::string> stringTable;

        Agent* owner;              // NO! some kind of flexible interface or sublcassing

    };

};

// ---------------------------------------------------------------------------

#endif //MORRIS_VIRTUALMACHINE_H
