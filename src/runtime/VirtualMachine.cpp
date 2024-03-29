//
// Created by sean on 01/01/2021.
//


#include "../engine/Agent.h"
#include "VirtualMachine.h"

//#define VM_DEBUG_DUMP

namespace Runtime {

    void VM::Execute() {

#ifdef VM_DEBUG_DUMP
        DumpInstructions();
        DumpStrings();
#endif

        slice = SLICE;
        if (state == RUNNING) {
            while (slice > 0) {
                slice--;

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
                        ownerAgent->Die();
                        break;
                    }

                    case INSTR::YIELD: {
//                        state = VM::PAUSED;
                        slice = 0;
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
                        Location loc = stack[stack.size() - 1];
                        stack.pop_back();

                        instructionPointer = loc.address;
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

//                        std::cout << "BRF a= " << a << " loc= " << loc << std::endl;

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

                        Location c((double)(b.value + a.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::SUB : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c((double)(b.value - a.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::MUL : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c((double)(b.value * a.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::DIV : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c((double)(b.value / a.value));
                        stack.push_back(c);
                        break;
                    }

                    case INSTR::MOD : {
                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

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

                    case INSTR::ASETPOS : {
//                        std::cout << "ASETPOS - 2 params, sets position of a sprite in the agen" << std::endl;

                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
                            ownerAgent->SetPosition(b.value, a.value);
                        }
                        break;
                    }

                    case INSTR::ASETVEL : {
//                        std::cout << "ASETVEL - 2 params, sets position of a sprite in the agent" << std::endl;

                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
                            ownerAgent->SetVelocity(b.value, a.value);
                        }
                        break;
                    }

                    case INSTR::ASETCOL : {
//                      std::cout << "ASETCOL - 2 params, sets position of a sprite in the agen" << std::endl;

                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location c = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
                            ownerAgent->SetColour(c.value, b.value, a.value);
                        }
                        break;
                    }

                    case INSTR::ASETSPRITE : {
//                      std::cout << "ASETSPRITE - 2 params, sets position of the quad to copy from the atlas" << std::endl;

                        Location x = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
                            ownerAgent->SetSprite(x.value);
                        }
                        break;
                    }

                    case INSTR::ASETTEXT : {
//                        std::cout << "ASETTEXT - settext " << std::endl;

                        Location strIndex = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
                            ownerAgent->SetText(stringTable[strIndex.address]);
                        }
                        break;
                    }

                    case INSTR::AGETINPUT : {
//                      std::cout << "AGETINPUT - 1 params, gets status of keyboard button or direction" << std::endl;

                        Location v = stack[stack.size() - 1];
                        stack.pop_back();

                        Location res;
                        if ( ownerAgent ) {
                            res.value = ownerAgent->GetInput(v.value);
                        }
                        else {
                            res.value = 0;
                        }
                        stack.push_back(res);
                        break;
                    }

                    case INSTR::AGETCOLLISION : {
//                        std::cout << "AGETCOLLISION - 1 params, gets collision status ";

                        Location v = stack[stack.size() - 1];
                        stack.pop_back();

                        Location res;
                        res.value = 0;
                        if ( ownerAgent ) {
                            if ( ownerAgent->CheckCollided(v.value) ) {
//                                std::cout << "TRUE this frame" << std::endl;
                                res.value = 1;
                            }
                            else
                            {
//                                std::cout << "FALSE this frame" << std::endl;
                            }
                        }

                        stack.push_back(res);
                        break;
                    }

                    case INSTR::ASETCOLLISION : {
//                      std::cout << "ASETCOLLISION - 1 params, sets layer for collision system" << std::endl;

                        Location v = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
                            ownerAgent->SetCollisionLayer(v.value);
                        }
                        break;
                    }

                    case INSTR::SPAWN : {
//                        std::cout << "SPAWN " << std::endl;

                        Location strIndex = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
                            int x = ownerAgent->GetSprite()->getPosition().x;
                            int y = ownerAgent->GetSprite()->getPosition().y;

                            ownerAgent->Spawn(stringTable[strIndex.address], x, y);
                        }
                        break;
                    }

                    case INSTR::SPAWNAT : {
//                        std::cout << "SPAWNAT " << std::endl;

                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location b = stack[stack.size() - 1];
                        stack.pop_back();

                        Location strIndex = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
                            ownerAgent->Spawn(stringTable[strIndex.address], b.value, a.value);
                        }
                        break;
                    }

                    case INSTR::ASETVAR : {
                        std::cout << "ASETVAR - set alien flags " << std::endl;

                        Location a = stack[stack.size() - 1];
                        stack.pop_back();

                        Location strIndex = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
//                            ownerAgent->SetAlienVar(stringTable[strIndex.address],  a.value);
                        }
                        break;
                    }

                    case INSTR::RECEIVE : {
//                        std::cout << "RECEIVE - 1 params, gets collision status ";

                        Location v = stack[stack.size() - 1];
                        stack.pop_back();

                        Location res;
                        res.value = 0;
                        if ( ownerAgent ) {
                            if ( ownerAgent->Receive(v.value) ) {
//                                std::cout << "TRUE this frame" << std::endl;
                                res.value = 1;
                            }
                            else
                            {
//                                std::cout << "FALSE this frame" << std::endl;
                            }
                        }

                        stack.push_back(res);
                        break;
                    }

                    case INSTR::TRANSMIT : {
//                      std::cout << "TRANSMIT - 1 params, sets layer for collision system" << std::endl;

                        Location v = stack[stack.size() - 1];
                        stack.pop_back();

                        if ( ownerAgent ) {
                            ownerAgent->Transmit(v.value);
                        }
                        break;
                    }

                }

                incrProgramCounter();
            }
        }
    }

}
