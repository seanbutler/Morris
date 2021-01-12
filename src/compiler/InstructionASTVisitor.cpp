//
// Created by sean on 27/11/2020.
//

#include "InstructionASTVisitor.h"
#include "AST.h"

// --------------------------------------------------

void InstructionASTVisitor::Visit(ModuleASTNode * A){
    std::cout << "Visit ModuleASTNode" << std::endl;

    for(auto child : A->children) {
        child->Accept(this);
    }
    instructions.emplace_back(Location(INSTR::HALT));
}

void InstructionASTVisitor::Visit(DeclarationASTNode * A){
    std::cout << "Visit DeclarationASTNode" << std::endl;

    // TODO (later) set visibility of var in local symbol table to true

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(IdentifierListASTNode * A){
    std::cout << "Visit IdentifierListASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(WhileASTNode * A){
    std::cout << "Visit WhileASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }

    instructions.emplace_back(Location(INSTR::NOP));
}

void InstructionASTVisitor::Visit(IfASTNode * A){
    std::cout << "Visit IfASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(BlockASTNode * A){
    std::cout << "Visit BlockASTNode" << std::endl;

    // TODO - blocks can have their own local symbol table, which is nice
//    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(AssignmentASTNode * A){
    std::cout << "Visit AssignmentASTNode" << std::endl;

    for(auto child : A->children) {
        child->Accept(this);
    }

    instructions.emplace_back(Location(INSTR::PUSH));
    instructions.emplace_back(Location( (unsigned long int) 666));        // TODO get this value from identifier/varname lookup
    instructions.emplace_back(Location(INSTR::SAVE));
}

void InstructionASTVisitor::Visit(NumberASTNode * A){
    std::cout << "Visit NumberASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::PUSH));
    instructions.emplace_back(Location((unsigned long int) std::stoi(A->value)));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(IdentifierASTNode * A){
    std::cout << "Visit IdentifierASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::PUSH));

    std::cout << " ---- " << A->value << std::endl;

    // RESOLVE A->value





    instructions.emplace_back(Location( (unsigned long int) 0));        // TODO get this value from identifier/varname lookup

    instructions.emplace_back(Location(INSTR::LOAD));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(OperatorASTNode * A){
    std::cout << "Visit OperatorASTNode" << std::endl;

    A->children[0]->Accept(this);
    A->children[1]->Accept(this);

    if ( A->value == "+" ) {
        instructions.emplace_back(Location(INSTR::ADD));
        return;
    }

    if ( A->value == "-" ) {
        instructions.emplace_back(Location(INSTR::SUB));
        return;
    }

    if ( A->value == "*" ) {
        instructions.emplace_back(Location(INSTR::MUL));
        return;
    }

    if ( A->value == "/" ) {
        instructions.emplace_back(Location(INSTR::DIV));
        return;
    }

    if ( A->value == "%" ) {
        instructions.emplace_back(Location(INSTR::MOD));
        return;
    }
}

void InstructionASTVisitor::Visit(ReturnASTNode * A){
    std::cout << "Visit ReturnASTNode" << std::endl;


    for(auto child : A->children) {
        child->Accept(this);
    }

//    instructions.emplace_back(Location(INSTR::RET));
}

void InstructionASTVisitor::Visit(OutputASTNode * A){
    std::cout << "Visit OutputASTNode" << std::endl;

    for(auto child : A->children) {
        child->Accept(this);
    }

    instructions.emplace_back(Location(INSTR::OUTPUT));
}


void InstructionASTVisitor::Visit(FunctionASTNode * A){
    std::cout << "Visit FunctionASTNode" << std::endl;

//    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(ProcedureASTNode * A){
    std::cout << "Visit ProcedureASTNode" << std::endl;

//    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

// --------------------------------------------------
