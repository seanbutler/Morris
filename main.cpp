#include <iostream>

#include "src/compiler/Emitter.h"

#include "src/compiler/Tokenizer.h"
#include "src/compiler/AST.h"
#include "src/compiler/Parser.h"

#include <string>
#include <fstream>
#include <streambuf>

#include "src/compiler/SymbolTable.h"
#include "src/compiler/Runtime.h"
#include "src/compiler/Assembler.h"


int main(int argc, char**argv) {

    char filename[] = "test.src";

    std::ifstream t(filename);
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    Tokenizer tokenizer;
    tokenizer.SetInputString(str);
    tokenizer.SetFilename(filename);
    tokenizer.Scan();

    std::vector<Token> tokens = tokenizer.GetOutputTokens();

    Parser parser;
    parser.SetInput(tokens);
    ASTNode * ast = parser.Parse();


//    Assembler assembler;
//    assembler.Scan("PUSH 1\n PUSH 1\nADD\nOUTPUT\nHALT\n");



//    VM vm(assembler.instructions);

//    vm.


//    double A = 1.0;
//    double B = 2.0;

//    vm.instructions.emplace_back(Location(INSTR::PUSH));
//    vm.instructions.emplace_back(A);
//    vm.instructions.emplace_back(INSTR::SAVE);
//    vm.instructions.emplace_back(1UL);
//    vm.instructions.emplace_back(INSTR::PUSH);
//    vm.instructions.emplace_back(B);
//    vm.instructions.emplace_back(INSTR::SAVE);
//    vm.instructions.emplace_back(2UL);
//    vm.instructions.emplace_back(INSTR::LOAD);
//    vm.instructions.emplace_back(1UL);
//    vm.instructions.emplace_back(INSTR::LOAD);
//    vm.instructions.emplace_back(2UL);
//    vm.instructions.emplace_back(INSTR::ADD);
//    vm.instructions.emplace_back(INSTR::SAVE);
//    vm.instructions.emplace_back(3UL);
//    vm.instructions.emplace_back(INSTR::LOAD);
//    vm.instructions.emplace_back(3UL);
//    vm.instructions.emplace_back(INSTR::OUTPUT);
//    vm.instructions.emplace_back(INSTR::JMP);
//    vm.instructions.emplace_back(8UL);
//    vm.instructions.emplace_back(INSTR::HALT);
//    vm.state = VM::RUNNING;
//    vm.Execute(13);

    return 0;
}
