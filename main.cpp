/*

 ## TODO

 - [x] tokenizer generates error message when bad token
 - [x] if code generation
 - [x] while  code generation

 - [ ] basic integration with the graphics system
 - [ ] parser generates readable error messages
 - [ ] spawn command
 - [ ] thread hierarchy
 - [ ] function code generation
 - [ ] procedure code generation

*/

#include <string>

// ---------------------------------------------------------------------------

#include "src/engine/MainLoop.h"
#include "src/runtime/VirtualMachine.h"
#include "src/Simulation/Agent.h"

// ---------------------------------------------------------------------------

int main(int argc, char**argv) {

    Engine::MainLoop loop;
    loop.entityScheduler.entities.push_back(new Agent("test.src"));
    loop.Update();

    return 0;
}

// ---------------------------------------------------------------------------
