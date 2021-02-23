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
//        std::cout << " >>> DECLARE SYMBOL " << child->value << std::endl;
        symbolTable.Insert(child->value, SymbolTable::number, SymbolTable::local);
    }
}

void InstructionASTVisitor::Visit(WhileASTNode * A){
    std::cout << "InstructionASTVisitor WhileASTNode" << std::endl;

    // STORE THE ADDRESS BEFORE THE EXPRESSION, SO WE CAN DO IT AGAIN
//    unsigned long int beforeConditionAddr = instructions.size();
    unsigned long int beforeConditionAddr = instructions.size()-1;

    // GENERATE CODE FOR THE FIRST CHILD, THE EXPRESSION
    A->children[0]->Accept(this);

    // GENERATE CODE FOR THE CONDITIONAL/BRANCH
    instructions.emplace_back(Location(INSTR::PUSH));
    instructions.emplace_back(Location((unsigned long int)0));
    unsigned long int jumpStartAddr = instructions.size()-1;
    instructions.emplace_back(Location(INSTR::BRF));

    // GENERATE CODE FOR THE SECOND CHILD, THE BLOCK
    A->children[1]->Accept(this);

    instructions.emplace_back(Location(INSTR::PUSH));
    instructions.emplace_back(Location((unsigned long int)beforeConditionAddr));
    instructions.emplace_back(Location(INSTR::JMP));

    instructions[jumpStartAddr] = Location((unsigned long int) (instructions.size()-1));
}

void InstructionASTVisitor::Visit(IfASTNode * A){
    std::cout << "InstructionASTVisitor IfASTNode" << std::endl;

    // GENERATE CODE FOR THE FIRST CHILD, THE EXPRESSION
    A->children[0]->Accept(this);

    instructions.emplace_back(Location(INSTR::PUSH));
    instructions.emplace_back(Location((unsigned long int)0));
    unsigned long int jumpStartAddr = instructions.size()-1;
    instructions.emplace_back(Location(INSTR::BRF));

    A->children[1]->Accept(this);
    instructions[jumpStartAddr] = Location((unsigned long int) instructions.size()-1);
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
    std::cout << "InstructionASTVisitor AssignmentASTNode " << A->type << " " << A->value << std::endl;

    // VISIT THE RHS
    for(auto rhs_child = A->children.begin() + 1; rhs_child != A->children.end(); rhs_child++) {
        (*rhs_child)->Accept(this);
    }

    // VISIT THE LHS
    LHSIdentifierASTNode * lhs_child = (LHSIdentifierASTNode*)(A->children[0]);
    lhs_child->Accept(this);

}

void InstructionASTVisitor::Visit(ExpressionASTNode * A){
    std::cout << "ExpressionASTNode NumberASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::PUSH));
    instructions.emplace_back(Location((double) std::stoi(A->value)));

    for(auto child : A->children) {
        child->Accept(this);
    }
}


void InstructionASTVisitor::Visit(NumberASTNode * A){
    std::cout << "InstructionASTVisitor NumberASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::PUSH));
    instructions.emplace_back(Location((double) std::stoi(A->value)));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(StringASTNode * A){
    std::cout << "InstructionASTVisitor StringASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::STRING));
    instructions.emplace_back(Location((double) 0));

    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(LHSIdentifierASTNode * A){
    std::cout << "InstructionASTVisitor LHSIdentifierASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::PUSH));

    //
    // RESOLVE VARIABLE
    //
//    std::cout << " <<< RESOLVE " << A->value << " ";
    std::pair<int, int > stackTablePosition = symbolTable.Find(A->value);
    std::cout << stackTablePosition.first << " " << stackTablePosition.second << std::endl;

//    instructions.emplace_back(Location( (unsigned long int) stackTablePosition.second));
    // TODO get this value from identifier/varname lookup

    instructions.emplace_back(Location((double)stackTablePosition.second));
    instructions.emplace_back(Location(INSTR::SAVE));

    for(auto child : A->children) {
        child->Accept(this);
    }
}


void InstructionASTVisitor::Visit(RHSIdentifierASTNode * A){
    std::cout << "InstructionASTVisitor RHSIdentifierASTNode" << std::endl;

    instructions.emplace_back(Location(INSTR::PUSH));

    //
    // RESOLVE VARIABLE
    //
//    std::cout << " <<< RESOLVE " << A->value << " ";
    std::pair<int, int > stackTablePosition = symbolTable.Find(A->value);
    std::cout << stackTablePosition.first << " " << stackTablePosition.second << std::endl;

    instructions.emplace_back(Location( (unsigned long int) stackTablePosition.second));
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

    if ( A->value == "^" ) {
        instructions.emplace_back(Location(INSTR::POW));
        return;
    }

    if ( A->value == "==" ) {
        instructions.emplace_back(Location(INSTR::EQU));
        return;
    }

    if ( A->value == "!=" ) {
        instructions.emplace_back(Location(INSTR::NE));
        return;
    }

    if ( A->value == ">" ) {
        instructions.emplace_back(Location(INSTR::GT));
        return;
    }

    if ( A->value == ">=" ) {
        instructions.emplace_back(Location(INSTR::GTE));
        return;
    }

    if ( A->value == "<" ) {
        instructions.emplace_back(Location(INSTR::LT));
        return;
    }

    if ( A->value == "<=" ) {
        instructions.emplace_back(Location(INSTR::LTE));
        return;
    }
}

void InstructionASTVisitor::Visit(ReturnASTNode * A){
    std::cout << "Visit ReturnASTNode" << std::endl;
    for(auto child : A->children) {
        child->Accept(this);
    }
    instructions.emplace_back(Location(INSTR::RET));
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
    for(auto child : A->children) {
        child->Accept(this);
    }
}

void InstructionASTVisitor::Visit(ProcedureASTNode * A){
    std::cout << "Visit ProcedureASTNode" << std::endl;
    for(auto child : A->children) {
        child->Accept(this);
    }
}

// --------------------------------------------------

void InstructionASTVisitor::Visit(SetposASTNode * A){
    std::cout << "Visit SetposASTNode" << std::endl;
    A->children[0]->Accept(this);
    A->children[1]->Accept(this);
    instructions.emplace_back(Location(INSTR::ASETPOS));
}

void InstructionASTVisitor::Visit(SetvelASTNode * A){
    std::cout << "Visit SetvelASTNode" << std::endl;
    A->children[0]->Accept(this);
    A->children[1]->Accept(this);
    instructions.emplace_back(Location(INSTR::ASETVEL));
}

void InstructionASTVisitor::Visit(SetcolASTNode * A){
    std::cout << "Visit SetcolASTNode" << std::endl;
    A->children[0]->Accept(this);
    A->children[1]->Accept(this);
    A->children[2]->Accept(this);
    instructions.emplace_back(Location(INSTR::ASETCOL));
}
