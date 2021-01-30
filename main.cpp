#include <iostream>

#include <string>
#include <fstream>
#include <streambuf>

#include "src/compiler/Tokenizer.h"
#include "src/compiler/AST.h"
#include "src/compiler/Parser.h"
#include "src/compiler/InstructionASTVisitor.h"

#include "src/runtime/Runtime.h"
#include "src/runtime/Scheduler.h"

#include "src/common/Location.h"


#include "src/compiler/compiler.h"

// ---------------------------------------------------------------------------

int main(int argc, char**argv) {

    Scheduler scheduler;
    VM * machine;

    machine = new VM(Compiler::compile("test.src"));
    machine->state = VM::RUNNING;
    scheduler.Add(machine);


//    machine = new VM(Compiler::compile("test2.src"));
//    machine->state = VM::RUNNING;
//    scheduler.Add(machine);
//
//
//    scheduler.Update(8);
//    scheduler.Update(8);
//    scheduler.Update(8);
//    scheduler.Update(8);
//    scheduler.Update(8);
//    scheduler.Update(8);
//    scheduler.Update(8);
//    scheduler.Update(8);

    scheduler.Update(64);

    return 0;
}

// ---------------------------------------------------------------------------
