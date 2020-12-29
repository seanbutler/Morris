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

    void SetInput(const std::vector<Token> T) {
        tokens = T;
    }

    ASTNode * Parse();
    ModuleASTNode * ParseModule();
    ASTNode * ParseDeclaration(SymbolTable & ST, SymbolTable::Scope S = SymbolTable::local);        // decl var
    ASTNode * ParseIdentList(SymbolTable & ST, SymbolTable::Scope S = SymbolTable::local);

    ASTNode * ParseWhile(bool returnable=false);
    ASTNode * ParseIf(bool returnable=false);
    ASTNode * ParseBlock(bool returnable=false);

    ASTNode * ParseAssignment(bool returnable=false);         // identifier equals value
    ASTNode * ParseExpression(bool returnable=false);         // A + B etc

    ASTNode * ParseNumber();                                    // constant        3
    ASTNode * ParseIdentifier();                                // identifier      nFred
    ASTNode * ParseOperator();                                  // + - * / etc

    ASTNode * ParseProcedure();
    ASTNode * ParseFunction();
    ASTNode * ParseReturn();

protected:
    std::vector<Token> tokens;
    std::vector<Token>::iterator tokenItor;
    std::shared_ptr<ASTNode> abstractSyntaxTree;
};

