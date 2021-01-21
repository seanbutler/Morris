
#include "InstructionASTVisitor.h"
#include "AST.h"

// --------------------------------------------------

void ScopeASTVisitor::Visit(ModuleASTNode * A){
    std::cout << "Visit ModuleASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(DeclarationASTNode * A){
    std::cout << "Visit DeclarationASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(IdentifierListASTNode * A){
    std::cout << "Visit IdentifierListASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(WhileASTNode * A){
    std::cout << "Visit WhileASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(IfASTNode * A){
    std::cout << "Visit IfASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(BlockASTNode * A){
    std::cout << "Visit BlockASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(AssignmentASTNode * A){
    std::cout << "Visit AssignmentASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(NumberASTNode * A){
    std::cout << "Visit NumberASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(IdentifierASTNode * A){
    std::cout << "Visit IdentifierASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(OperatorASTNode * A){
    std::cout << "Visit OperatorASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(ReturnASTNode * A){
    std::cout << "Visit ReturnASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(OutputASTNode * A){
    std::cout << "Visit OutputASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(FunctionASTNode * A){
    std::cout << "Visit FunctionASTNode" << std::endl;
}

void ScopeASTVisitor::Visit(ProcedureASTNode * A){
    std::cout << "Visit ProcedureASTNode" << std::endl;
}

// --------------------------------------------------
