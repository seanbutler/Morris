/*

 ## TODO

 - [x] tokenizer generates error message when bad token
 - [x] if code generation
 - [ ] while  code generation

 - [ ] parser generates readable error messages
 - [ ] spawn command
 - [ ] thread hierarchy

 - [ ] function code generation
 - [ ] procedure code generation

*/

#include <string>

// ---------------------------------------------------------------------------

#include "src/engine/MainLoop.h"
#include "src/compiler/compiler.h"
#include "src/runtime/VirtualMachine.h"
#include "src/runtime/Scheduler.h"

// ---------------------------------------------------------------------------

int main(int argc, char**argv) {

//    Engine::MainLoop loop;
//    loop.Update();

    Runtime::Scheduler scheduler;
    Runtime::VM * machine;

    machine = new Runtime::VM(Compiler::compile("test.src"));

    machine->DumpInstructions();

    machine->state = Runtime::VM::RUNNING;
    scheduler.Add(machine);

    scheduler.Update(2048);

    return 0;
}

// ---------------------------------------------------------------------------
