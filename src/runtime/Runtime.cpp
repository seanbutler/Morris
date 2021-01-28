//
// Created by sean on 01/01/2021.
//

#include "Runtime.h"
#include "../common/Location.h"

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
                    Location addr = stack.top();
                    stack.pop();
                    stack.push(data[addr.address]);
                    break;
                }

                case INSTR::SAVE: {

                    Location loc = stack.top();
                    stack.pop();

                    Location val = stack.top();
                    stack.pop();

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

