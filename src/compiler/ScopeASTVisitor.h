//
// Created by sean on 27/11/2020.
//

#pragma once

#include <iostream>
#include <memory>

#include "Location.h"
#include "./Visitor.h"

// ---------------------------------------------------------------------------

class ASTNode;
class ModuleASTNode;
class DeclarationASTNode;
class IdentifierListASTNode;
class WhileASTNode;
class IfASTNode;
class BlockASTNode;
class AssignmentASTNode;
class NumberASTNode;
class IdentifierASTNode;
class OperatorASTNode;
class ReturnASTNode;
class OutputASTNode;
class FunctionASTNode;
class ProcedureASTNode;

// ---------------------------------------------------------------------------

class ScopeASTVisitor : public ASTNodeVisitor {

public:
    ScopeASTVisitor() {}

    void Visit(ModuleASTNode * A);
    void Visit(DeclarationASTNode * A);
    void Visit(IdentifierListASTNode * A);
    void Visit(WhileASTNode * A);
    void Visit(IfASTNode * A);
    void Visit(BlockASTNode * A);
    void Visit(AssignmentASTNode * A);
    void Visit(NumberASTNode * A);
    void Visit(IdentifierASTNode * A);
    void Visit(OperatorASTNode * A);
    void Visit(ReturnASTNode * A);
    void Visit(OutputASTNode * A);
    void Visit(FunctionASTNode * A);
    void Visit(ProcedureASTNode * A);

    std::shared_ptr<ASTNode> ast;
    std::vector<Location> instructions;
    std::vector<Location> data;
};

// ---------------------------------------------------------------------------
