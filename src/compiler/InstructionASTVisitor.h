//
// Created by sean on 27/11/2020.
//

#pragma once

#include "Location.h"
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
class SpawnAtASTNode;
class LHSIdentifierASTNode;
class RHSIdentifierASTNode;
class OperatorASTNode;
class ReturnASTNode;
class OutputASTNode;
class SetposASTNode;
class SetvelASTNode;
class SetcolASTNode;
class SetspriteASTNode;
class SetcollisionASTNode;
class SetTextASTNode;
class GetInputASTNode;
class GetCollisionASTNode;
class FunctionASTNode;
class ProcedureASTNode;
class TransmitASTNode;
class ReceiveASTNode;


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
    void Visit(SpawnAtASTNode * A);
    void Visit(LHSIdentifierASTNode * A);
    void Visit(RHSIdentifierASTNode * A);
    void Visit(OperatorASTNode * A);
    void Visit(ReturnASTNode * A);
    void Visit(OutputASTNode * A);

    void Visit(SetposASTNode * A);
    void Visit(SetvelASTNode * A);
    void Visit(SetcolASTNode * A);

    void Visit(SetspriteASTNode * A);
    void Visit(SetTextASTNode * A);
    void Visit(GetInputASTNode * A);
    void Visit(SetcollisionASTNode * A);
    void Visit(GetCollisionASTNode * A);

    void Visit(FunctionASTNode * A);
    void Visit(ProcedureASTNode * A);

    void Visit(TransmitASTNode * A);
    void Visit(ReceiveASTNode * A);

    SymbolTableStack symbolTable;
    std::vector<Location> instructions;
    std::vector<std::string> strings;
};

// ---------------------------------------------------------------------------
