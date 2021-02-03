
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
    machine->state = Runtime::VM::RUNNING;
    scheduler.Add(machine);

    scheduler.Update(128);

    return 0;
}

// ---------------------------------------------------------------------------
