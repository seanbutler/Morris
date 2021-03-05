//
// Created by sean on 27/11/2020.
//

#pragma once

#include "../common/Location.h"
#include "./Visitor.h"
#include "./SymbolTable.h"


#include <iostream>
#include <memory>
#include <map>
#include <vector>


// ---------------------------------------------------------------------------

class ASTNode;
class ModuleASTNode;
class DeclarationASTNode;
class IdentifierListASTNode;
class WhileASTNode;
class IfASTNode;
class BlockASTNode;
class AssignmentASTNode;
class ExpressionASTNode;
class NumberASTNode;
class StringASTNode;
class SpawnASTNode;
class LHSIdentifierASTNode;
class RHSIdentifierASTNode;
class OperatorASTNode;
class ReturnASTNode;
class OutputASTNode;
class SetposASTNode;
class SetvelASTNode;
class SetspriteASTNode;
class SetcolASTNode;
class FunctionASTNode;
class ProcedureASTNode;

// ---------------------------------------------------------------------------

class InstructionASTVisitor : public ASTNodeVisitor {

public:
    InstructionASTVisitor() {}

    void Visit(ModuleASTNode * A);
    void Visit(DeclarationASTNode * A);
    void Visit(IdentifierListASTNode * A);
    void Visit(WhileASTNode * A);
    void Visit(IfASTNode * A);
    void Visit(BlockASTNode * A);
    void Visit(AssignmentASTNode * A);
    void Visit(ExpressionASTNode * A);
    void Visit(NumberASTNode * A);
    void Visit(StringASTNode * A);
    void Visit(SpawnASTNode * A);
    void Visit(LHSIdentifierASTNode * A);
    void Visit(RHSIdentifierASTNode * A);
    void Visit(OperatorASTNode * A);
    void Visit(ReturnASTNode * A);
    void Visit(OutputASTNode * A);
    void Visit(SetposASTNode * A);
    void Visit(SetvelASTNode * A);
    void Visit(SetspriteASTNode * A);
    void Visit(SetcolASTNode * A);
    void Visit(FunctionASTNode * A);
    void Visit(ProcedureASTNode * A);

    SymbolTableStack symbolTable;
    std::shared_ptr<ASTNode> ast;
    std::vector<Location> instructions;
    std::vector<Location> data;
    std::vector<std::string> strings;
};

// ---------------------------------------------------------------------------
