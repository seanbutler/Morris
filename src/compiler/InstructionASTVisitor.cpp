//
// Created by sean on 27/11/2020.
//

#include "InstructionASTVisitor.h"
#include "AST.h"

// --------------------------------------------------

void InstructionASTVisitor::Visit(ASTNode * A){
    std::cout << "Visit ASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }

    instructions.emplace_back(Location(INSTR::HALT));
}

void InstructionASTVisitor::Visit(ModuleASTNode * A){
    std::cout << "Visit ModuleASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(DeclarationASTNode * A){
    std::cout << "Visit DeclarationASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

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

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(AssignmentASTNode * A){
    std::cout << "Visit AssignmentASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(NumberASTNode * A){
    std::cout << "Visit NumberASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(IdentifierASTNode * A){
    std::cout << "Visit IdentifierASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(OperatorASTNode * A){
    std::cout << "Visit OperatorASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(ReturnASTNode * A){
    std::cout << "Visit ReturnASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(FunctionASTNode * A){
    std::cout << "Visit FunctionASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(ProcedureASTNode * A){
    std::cout << "Visit ProcedureASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::NOP));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

// --------------------------------------------------
