//
// Created by sean on 01/01/2021.
//

#include "Runtime.h"
#include "Location.h"


char* instructionNames[] = {
        "NOP",
        "HALT",
        "YIELD",
        "PUSH",
        "POP",

        "SAVE",
        "LOAD",

        "JMP",
        "BRT",
        "BRF",

        "ADD",
        "SUB",
        "MUL",
        "DIV",
        "MOD",

        "EQU",
        "NE",
        "GT",
        "GTE",
        "LT",
        "LTE",

        "AND",
        "OR",
        "NOT",
        "XOR",
        "NAND",

        "INPUT",
        "OUTPUT",

        "TOK_ERROR"
};


void VM::Execute(unsigned int S){
    slice = S;
    if (state == RUNNING) {
        while (slice > 0) {
            slice--;

//            std::cout << instructionNames[getCurrentInstruction()] << std::endl;

            switch (getCurrentInstruction()) {

                case INSTR::NOP :
                    // Do Nothing
                    break;

                case INSTR::HALT:
                    state = VM::HALTED;
                    slice = 0;
                    break;

                case INSTR::YIELD:
                    state = VM::PAUSED;
                    break;

                case INSTR::PUSH : {
                    incrProgramCounter();
                    stack.push(getCurrentLocation());
                    break;
                }

                case INSTR::POP : {
                    stack.pop();
                    break;
                }

                case INSTR::LOAD: {
                    incrProgramCounter();
                    Location addr = getCurrentLocation();
                    stack.push(data[addr.address]);
                    break;
                }

                case INSTR::SAVE: {
                    Location val = stack.top();
                    stack.pop();
                    incrProgramCounter();
                    Location loc = getCurrentLocation();
                    data[loc.address] = val;
                    break;
                }

                case INSTR::JMP: {
                    incrProgramCounter();
                    Location loc = getCurrentLocation();
                    instructionPointer = loc.address - 1;
                    break;
                }

                case INSTR::BRT: {
                    Location a = stack.top();
                    this->stack.pop();

                    incrProgramCounter();
                    Location loc = getCurrentLocation();

                    if (a.value != 0) {
                        instructionPointer = loc.address - 1;
                    }
                    break;
                }

                case INSTR::BRF: {
                    Location a = stack.top();
                    stack.pop();

                    incrProgramCounter();
                    Location loc = getCurrentLocation();

                    if (a.value == 0) {
                        instructionPointer = loc.address - 1;
                    }
                    break;
                }

                case INSTR::ADD : {
                    Location a = stack.top();
                    stack.pop();

                    Location b = stack.top();
                    stack.pop();

                    Location c;
                    c.type = Location::VAL;
                    c.value = a.value + b.value;
                    stack.push(c);
                    break;
                }

                case INSTR::OUTPUT : {
                    std::cout << "output value... " << stack.top().value << std::endl;
                    stack.pop();
                    break;
                }

                case INSTR::INPUT : {
                    std::cout << "INPUT - not implemented" << std::endl;
                    break;
                }

            }



            incrProgramCounter();
        }
    }
}


