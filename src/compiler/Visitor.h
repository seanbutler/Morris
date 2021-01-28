//
// Created by sean on 27/11/2020.
//

#ifndef MORRIS_ASTNODEVISITOR_H
#define MORRIS_ASTNODEVISITOR_H

#include <iostream>
#include <memory>


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
class RHSIdentifierASTNode;
class OperatorASTNode;
class ReturnASTNode;
class FunctionASTNode;
class ProcedureASTNode;

// ---------------------------------------------------------------------------

class ASTNodeVisitor{

public:
    virtual void Visit(ModuleASTNode * A)=0;
    virtual void Visit(DeclarationASTNode * A)=0;
    virtual void Visit(IdentifierListASTNode * A)=0;
    virtual void Visit(WhileASTNode * A)=0;
    virtual void Visit(IfASTNode * A)=0;
    virtual void Visit(BlockASTNode * A)=0;
    virtual void Visit(AssignmentASTNode * A)=0;
    virtual void Visit(NumberASTNode * A)=0;
    virtual void Visit(RHSIdentifierASTNode * A)=0;
    virtual void Visit(OperatorASTNode * A)=0;
    virtual void Visit(ReturnASTNode * A)=0;
    virtual void Visit(FunctionASTNode * A)=0;
    virtual void Visit(ProcedureASTNode * A)=0;
};

// ---------------------------------------------------------------------------

#endif //MORRIS_ASTNODEVISITOR_H
