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
        tokenItor = tokens.begin();
    }

    ModuleASTNode * Parse();
    ModuleASTNode * ParseModule();
    DeclarationASTNode *ParseDeclaration(ASTNode *P);        // decl var
    IdentifierListASTNode *ParseIdentList(ASTNode *P);

    WhileASTNode * ParseWhile(ASTNode *P= nullptr, bool returnable=false);
    IfASTNode * ParseIf(ASTNode *P= nullptr, bool returnable=false);
    BlockASTNode * ParseBlock(ASTNode *P= nullptr, bool returnable=false);

    AssignmentASTNode * ParseAssignment(ASTNode *P= nullptr, bool returnable=false);     // identifier equals value
    ASTNode * ParseExpression(ASTNode *P= nullptr, bool returnable=false);               // A + B etc

    NumberASTNode * ParseNumber(ASTNode *P= nullptr);                                    // constant        3
    IdentifierASTNode * ParseIdentifier(ASTNode *P= nullptr);                            // identifier      nFred
    OperatorASTNode * ParseOperator(ASTNode *P= nullptr);                                // + - * / etc

    ProcedureASTNode * ParseProcedure(ASTNode *P= nullptr);
    FunctionASTNode * ParseFunction(ASTNode *P= nullptr);
    ReturnASTNode * ParseReturn(ASTNode *P= nullptr);

    OutputASTNode * ParseOutput(ASTNode *P= nullptr);

    SymbolTableStack symbolTable;

    std::vector<Token> tokens;
    std::vector<Token>::iterator tokenItor;
    std::shared_ptr<ASTNode> abstractSyntaxTree;
};

