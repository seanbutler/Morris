//
// Created by sean on 27/11/2020.
//

#include "InstructionASTVisitor.h"
#include "AST.h"

// --------------------------------------------------

void InstructionASTVisitor::Visit(ModuleASTNode * A){
    std::cout << "InstructionASTVisitor ModuleASTNode" << std::endl;

    for(auto child : A->children) {
        child->Accept(this);
    }

    instructions.emplace_back(Location(INSTR::HALT));
}

void InstructionASTVisitor::Visit(DeclarationASTNode * A){
    std::cout << "InstructionASTVisitor DeclarationASTNode" << std::endl;

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(IdentifierListASTNode * A){
    std::cout << "InstructionASTVisitor IdentifierListASTNode " << A->value << " " << A->type << std::endl;

    for(auto child : A->children) {
        std::cout << " >>> DECLARE " << child->value << std::endl;
        symbolTable.Insert(child->value, SymbolTable::integer, SymbolTable::local);
    }
}

void InstructionASTVisitor::Visit(WhileASTNode * A){
    std::cout << "InstructionASTVisitor WhileASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }

    instructions.emplace_back(Location(INSTR::NOP));
}

void InstructionASTVisitor::Visit(IfASTNode * A){
    std::cout << "InstructionASTVisitor IfASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(BlockASTNode * A){
    std::cout << "InstructionASTVisitor BlockASTNode" << std::endl;

    symbolTable.IncreaseNestLevel();

    for(auto child : A->children) {
        child->Accept(this);
    }

    symbolTable.DecreaseNestLevel();

}

void InstructionASTVisitor::Visit(AssignmentASTNode * A){
    std::cout << "InstructionASTVisitor AssignmentASTNode" << std::endl;

    for(auto child : A->children) {
        child->Accept(this);
    }

    instructions.emplace_back(Location(INSTR::PUSH));
    instructions.emplace_back(Location( (unsigned long int) 666));        // TODO get this value from identifier/varname lookup
    instructions.emplace_back(Location(INSTR::SAVE));
}

void InstructionASTVisitor::Visit(NumberASTNode * A){
    std::cout << "InstructionASTVisitor NumberASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::PUSH));
    instructions.emplace_back(Location((unsigned long int) std::stoi(A->value)));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(IdentifierASTNode * A){
    std::cout << "InstructionASTVisitor IdentifierASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::PUSH));

    //
    // RESOLVE VARIABLE
    //
    std::cout << " <<< RESOLVE " << A->value << std::endl;

//    std::tuple<std::string, SymbolTable::BaseTypes, SymbolTable::Scope> * currentIdent;
//    currentIdent = symbolTable.Get(A->value);

    std::pair<int, int > stackTablePosition = symbolTable.Find(A->value);
    std::cout << stackTablePosition.first << " " << stackTablePosition.second << std::endl;

    instructions.emplace_back(Location( (unsigned long int) 0));
    // TODO get this value from identifier/varname lookup

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
