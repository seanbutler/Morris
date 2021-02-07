//
// Created by sean on 01/01/2021.
//

#include <math.h>

#include "VirtualMachine.h"
#include "../common/Location.h"
//#define VM_DEBUG_DUMP

namespace Runtime {

    void VM::Execute(unsigned int S) {

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
                        Location addr = stack[stack.size() - 1];
                        stack.pop_back();
                        stack.push_back(data[addr.address]);
                        break;
                    }

                    case INSTR::SAVE: {
                        Location addr = stack[stack.size() - 1];
                        stack.pop_back();

                        Location val = stack[stack.size() - 1];
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
                        Location loc = stack[stack.size() - 1];
                        stack.pop_back();

                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        if (a.value) {
                            instructionPointer = loc.address;
                        }
                        break;
                    }

                    case INSTR::BRF: {
                        Location loc = stack[stack.size() - 1];
                        stack.pop_back();

                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        if (!(a.value)) {
                            instructionPointer = loc.address;
                        }
                        break;
                    }

                    case INSTR::ADD : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c(b.value + a.value);
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::SUB : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c(b.value - a.value);
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::MUL : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c(b.value * a.value);
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::DIV : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c(b.value / a.value);
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::MOD : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        std::cout << a << " " << b << std::endl;

                        Location c((double)((int)b.value % (int)a.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::EQU : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c((double)(a.value == b.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::NE : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c((double)(a.value != b.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::GT : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c((double)(b.value > a.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::GTE : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c((double)(b.value >= a.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::LT : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c((double)(b.value < a.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::LTE : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c((double)(b.value <= a.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::OUTPUT : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        std::cout << "output value: " << a.value << " ";
//                        std::cout << "type: " << a.type << " ";
//                        std::cout << "instr: " << a.instruction << " ";
//                        std::cout << "addr: " << a.address << " ";
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

}
