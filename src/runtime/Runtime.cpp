//
// Created by sean on 01/01/2021.
//

#include "Runtime.h"
#include "../common/Location.h"
//#define VM_DEBUG_DUMP


void VM::Execute(unsigned int S){

#ifdef VM_DEBUG_DUMP
    DumpInstructions();
#endif


    slice = S;
    if (state == RUNNING) {
        while (slice > 0) {
            slice--;

//            std::cout << instructionNames[getCurrentInstruction()] << std::endl;


#ifdef VM_DEBUG_DUMP
    DumpRegs();
    DumpStack();
    DumpData();
#endif

            switch (getCurrentInstruction()) {

                case INSTR::NOP: {
                    // Do Nothing
                    break;
                }

                case INSTR::HALT: {
                    state = VM::HALTED;
                    slice = 0;
                    break;
                }

                case INSTR::YIELD: {
                    state = VM::PAUSED;
                    break;
                }

                case INSTR::PUSH : {
                    incrProgramCounter();
                    stack.push_back(getCurrentLocation());
                    break;
                }

                case INSTR::POP : {
                    stack.pop_back();
                    break;
                }

                case INSTR::LOAD: {
                    Location addr = stack[stack.size()-1];
                    stack.pop_back();
                    stack.push_back(data[addr.address]);
                    break;
                }

                case INSTR::SAVE: {
                    Location addr = stack[stack.size()-1];
                    stack.pop_back();

                    Location val = stack[stack.size()-1];
                    stack.pop_back();

                    data[addr.value] = val;
                    break;
                }

                case INSTR::JMP: {
                    incrProgramCounter();
                    Location loc = getCurrentLocation();
                    instructionPointer = loc.address - 1;
                    break;
                }

                case INSTR::BRT: {
                    Location loc = stack[stack.size()-1];
                    stack.pop_back();

                    Location a = stack[stack.size()-1];
                    stack.pop_back();

                    if (a.value) {
                        instructionPointer = loc.address;
                    }
                    break;
                }

                case INSTR::BRF: {
                    Location loc = stack[stack.size()-1];
                    stack.pop_back();

                    Location a = stack[stack.size()-1];
                    stack.pop_back();

                    if (!(a.value) ) {
                        instructionPointer = loc.address;
                    }
                    break;
                }

                case INSTR::ADD : {
                    Location a = stack[stack.size()-1];
                    stack.pop_back();

                    Location b = stack[stack.size()-1];
                    stack.pop_back();

                    Location c(a.value + b.value);
                    stack.push_back(c);
                    break;
                }

                case INSTR::OUTPUT : {

                    Location a = stack[stack.size()-1];
                    stack.pop_back();

                    std::cout << "output value: " << a.value << " ";
//                    std::cout << "type: " << a.type << " ";
//                    std::cout << "instr: " << a.instruction << " ";
//                    std::cout << "addr: " << a.address
                    std::cout << std::endl;
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


