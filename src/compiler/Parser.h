//
// Created by sean on 25/09/2020.
//

#pragma once

#include <vector>
#include <memory>
#include "Tokens.h"
#include "AST.h"

class ASTNode;
class SymbolTable;

class Parser {

public:
    Parser() = default;

    void SetInput(const std::vector<Token> T) { tokens = T; }

    ASTNode * Parse();
    ModuleASTNode * ParseModule();
    DeclarationASTNode * ParseDeclaration(SymbolTable & ST, SymbolTable::Scope S = SymbolTable::local);        // decl var
    IdentifierListASTNode * ParseIdentList(SymbolTable & ST, SymbolTable::Scope S = SymbolTable::local);

    WhileASTNode * ParseWhile(bool returnable=false);
    IfASTNode * ParseIf(bool returnable=false);
    BlockASTNode * ParseBlock(bool returnable=false);

    AssignmentASTNode * ParseAssignment(bool returnable=false);       // identifier equals value
    ASTNode * ParseExpression(bool returnable=false);                 // A + B etc

    NumberASTNode * ParseNumber();                                    // constant        3
    IdentifierASTNode * ParseIdentifier();                            // identifier      nFred
    OperatorASTNode * ParseOperator();                                // + - * / etc

    ProcedureASTNode * ParseProcedure();
    FunctionASTNode * ParseFunction();
    ReturnASTNode * ParseReturn();

protected:
    std::vector<Token> tokens;
    std::vector<Token>::iterator tokenItor;
    std::shared_ptr<ASTNode> abstractSyntaxTree;
};

