/*

 ## TODO

 - [x] tokenizer generates error message when bad token
 - [x] if code generation
 - [x] while  code generation

 - [~] basic integration with the graphics system
 - [~] parser generates readable error messages

 - [ ] spawn command
    - [ ] filenames/strings for spawn
    - [ ] set positions
    - [ ] inherit position
    - [ ] access child (via return handle? or other method)
    - [ ] access parent
    - [ ] thread hierarchy

 - [ ] function code generation
 - [ ] procedure code generation

*/


#include <string>

// ---------------------------------------------------------------------------

#include "src/engine/MainLoop.h"
#include "src/engine/Textures.h"
#include "src/runtime/VirtualMachine.h"
#include "src/Simulation/Agent.h"

// ---------------------------------------------------------------------------

Engine::MainLoop loop(192, 128, 4, 32, "Hello");
Engine::Textures textures;

// ---------------------------------------------------------------------------

int main(int argc, char**argv) {

    loop.entityScheduler.Spawn(new Agent("./assets/code/main.src"));
    loop.Update();

    return 0;
}


// ---------------------------------------------------------------------------
