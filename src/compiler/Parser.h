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

    void Parse(std::shared_ptr<ASTNode> & ast);
    std::shared_ptr<ASTNode> ParseModule();         // multiple statements in a row
    std::shared_ptr<ASTNode> ParseDeclaration(SymbolTable & ST, SymbolTable::Scope S = SymbolTable::local);        // decl var
    std::shared_ptr<ASTNode> ParseNumber();             // constant        3
    std::shared_ptr<ASTNode> ParseIdentifier();         // identifier      nFred
    std::shared_ptr<ASTNode> ParseOperator();           // + - * / etc

    std::shared_ptr<ASTNode> ParseAssignment(bool returnable=false);         // identifier equals value
    std::shared_ptr<ASTNode> ParseExpression(bool returnable=false);         // A + B etc
    std::shared_ptr<ASTNode> ParseWhile(bool returnable=false);
    std::shared_ptr<ASTNode> ParseIf(bool returnable=false);
    std::shared_ptr<ASTNode> ParseBlock(bool returnable=false);

    std::shared_ptr<ASTNode> ParseProcedure();
    std::shared_ptr<ASTNode> ParseFunction();
    std::shared_ptr<ASTNode> ParseIdentList(SymbolTable & ST, SymbolTable::Scope S = SymbolTable::local);
    std::shared_ptr<ASTNode> ParseReturn();

protected:
    std::vector<Token> tokens;
    std::vector<Token>::iterator tokenItor;
    std::shared_ptr<ASTNode> abstractSyntaxTree;
};

