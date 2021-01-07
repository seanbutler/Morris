//
// Created by sean on 25/09/2020.
//

#include "Parser.h"
#include "AST.h"

#include <iostream>

ASTNode * Parser::Parse() {

    tokenItor = tokens.begin();

    ASTNode * ast = ParseModule();

//    std::ofstream diagramFile("test.gv");
//    diagramFile << "digraph G {" <<  std::endl;
//    diagramFile << "node [shape = box];" << std::endl;
//    ast->Diagram(diagramFile);
//    diagramFile << "}" << std::endl;
//    diagramFile.close();

    return ast;
}

// ----------------------------------------------------------------------

ModuleASTNode * Parser::ParseModule() {

    auto * statementsNodePtr = new ModuleASTNode();

    while ( tokenItor->kind != TokenEnum::TOK_END_OF_FILE )
    {
        switch (tokenItor->kind) {

            // BLOCK
            case TokenEnum::SYM_LBRACES: {
                tokenItor++;
                std::cout << "Parser::Parse() TokenEnum::SYM_LBRACES" << std::endl;
                statementsNodePtr->children.push_back(ParseBlock(false));
                tokenItor++;
                break;
            }

            // DECLARATION
            case TokenEnum::KWD_DECL: {
                std::cout << "Parser::Parse() TokenEnum::KWD_DECL" << std::endl;
                statementsNodePtr->children.push_back(ParseDeclaration(statementsNodePtr->symbolTable, SymbolTable::global));
                break;
            }

            // TOK_IDENTIFIER therefore ASSIGNMENT
            case TokenEnum::TOK_IDENTIFIER: {
                std::cout << "Parser::Parse() TokenEnum::TOK_IDENTIFIER" << std::endl;
                statementsNodePtr->children.push_back(ParseAssignment());
                break;
            }

            // WHILE statement
            case TokenEnum::KWD_WHILE:{
                std::cout << "Parser::Parse() TokenEnum::KWD_WHILE" << std::endl;
                statementsNodePtr->children.push_back(ParseWhile());
                break;
            }

            // IF statement
            case TokenEnum::KWD_IF:{
                std::cout << "Parser::Parse() TokenEnum::KWD_IF" << std::endl;
                statementsNodePtr->children.push_back(ParseIf());
                break;
            }

            // PROCEDURE
            case TokenEnum::KWD_PROC: {
                std::cout << "Parser::Parse() TokenEnum::KWD_PROC" << std::endl;
                statementsNodePtr->children.push_back(ParseProcedure());
                break;
            }

            // FUNCTION
            case TokenEnum::KWD_FUNC:{
                std::cout << "Parser::Parse() TokenEnum::KWD_FUNC" << std::endl;
                statementsNodePtr->children.push_back(ParseFunction());
                break;
            }

        }
    }

    return statementsNodePtr;

}

// ----------------------------------------------------------------------

DeclarationASTNode * Parser::ParseDeclaration(SymbolTable & ST, SymbolTable::Scope S) {
    DeclarationASTNode * declarationNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::KWD_DECL) {
        std::cout << "ParseDeclaration() TokenEnum::KWD_DECL" << std::endl;
        declarationNodeSP = new DeclarationASTNode();
        tokenItor++;
        declarationNodeSP->children.push_back(ParseIdentList(ST, S));
    }

    return declarationNodeSP;

}

// ----------------------------------------------------------------------

IdentifierListASTNode * Parser::ParseIdentList(SymbolTable & ST, SymbolTable::Scope S) {

    IdentifierListASTNode* listNodeSP = nullptr;
    ASTNode* identifierNodeSP;

    if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {

        listNodeSP = new IdentifierListASTNode();
        std::cout << "ParseIdentList() TokenEnum::TOK_IDENTIFIER" << std::endl;
        identifierNodeSP = new ASTNode("ID", tokenItor->name);
        listNodeSP->children.push_back(identifierNodeSP);

        ST.Insert(tokenItor->name, SymbolTable::integer, S);

        tokenItor++;

        while ( tokenItor->kind == TokenEnum::SYM_COMMA ) {
            std::cout << "ParseIdentList() TokenEnum::SYM_COMMA" << std::endl;

            tokenItor++;

            if (tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {
                std::cout << "ParseIdentList() TokenEnum::TOK_IDENTIFIER" << std::endl;
                identifierNodeSP = new ASTNode("ID", tokenItor->name);
                listNodeSP->children.push_back(identifierNodeSP);

                ST.Insert(tokenItor->name, SymbolTable::integer, SymbolTable::local);

                tokenItor++;
            }
        }
    }

    return listNodeSP;

}

// ----------------------------------------------------------------------

AssignmentASTNode * Parser::ParseAssignment(bool returnable) {

    AssignmentASTNode * assignmentNodeSP = nullptr;
    ASTNode * identifierNodeSP;
    ASTNode * rhsNodeSP;

    if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER ) {

        std::cout << "ParseAssignment() TokenEnum::TOK_IDENTIFIER" << std::endl;
        identifierNodeSP = new ASTNode();
        identifierNodeSP->type = "ID";
        identifierNodeSP->value = tokenItor->name;
        tokenItor++;

        if ( tokenItor->kind == TokenEnum::SYM_ASSIGN ) {

            std::cout << "ParseAssignment() TokenEnum::SYM_ASSIGN" << std::endl;
            assignmentNodeSP = new AssignmentASTNode();
            tokenItor++;

            rhsNodeSP = ParseExpression();
            assignmentNodeSP->children.push_back(identifierNodeSP);
            assignmentNodeSP->children.push_back(rhsNodeSP);
        }
    }

    return assignmentNodeSP;

}

// ----------------------------------------------------------------------

IfASTNode * Parser::ParseIf(bool returnable) {

    IfASTNode * statementNodeSP = nullptr;
    ASTNode * conditionNodeSP = nullptr;
    ASTNode * blockNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::KWD_IF ) {
        std::cout << "ParseIf() TokenEnum::KWD_IF" << std::endl;
        statementNodeSP = new IfASTNode();
        tokenItor++;

        if ( tokenItor->kind == TokenEnum::SYM_LPAREN) {

            tokenItor++;
            conditionNodeSP = ParseExpression();
            statementNodeSP->children.push_back(conditionNodeSP);

            if ( tokenItor->kind == TokenEnum::SYM_RPAREN) {
                tokenItor++;

                if ( tokenItor->kind == TokenEnum::SYM_LBRACES) {
                    tokenItor++;

                    blockNodeSP = ParseBlock();
                    statementNodeSP->children.push_back(blockNodeSP);

                    if (tokenItor->kind == TokenEnum::SYM_RBRACES) {
                        tokenItor++;

                        return statementNodeSP;
                    }
                }
            }
        }
    }
}

// ----------------------------------------------------------------------

WhileASTNode * Parser::ParseWhile(bool returnable) {

    WhileASTNode * statementNodeSP = nullptr;
    ASTNode * conditionNodeSP = nullptr;
    ASTNode * blockNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::KWD_WHILE ) {
        std::cout << "ParseWhile() TokenEnum::KWD_WHILE" << std::endl;
        statementNodeSP = new WhileASTNode( );
        tokenItor++;

        if ( tokenItor->kind == TokenEnum::SYM_LPAREN) {

            tokenItor++;
            conditionNodeSP = ParseExpression();
            statementNodeSP->children.push_back(conditionNodeSP);

            if ( tokenItor->kind == TokenEnum::SYM_RPAREN) {
                tokenItor++;

                if ( tokenItor->kind == TokenEnum::SYM_LBRACES) {
                    tokenItor++;

                    blockNodeSP = ParseBlock();
                    statementNodeSP->children.push_back(blockNodeSP);

                    if (tokenItor->kind == TokenEnum::SYM_RBRACES) {
                        tokenItor++;

                        return statementNodeSP;
                    }
                }
            }
        }
    }
}

// ----------------------------------------------------------------------

BlockASTNode * Parser::ParseBlock(bool returnable) {

    std::cout << "ParseBlock()" << std::endl;
    BlockASTNode * statementsNodeSP = nullptr;
    statementsNodeSP = new BlockASTNode();

    while ( tokenItor->kind != TokenEnum::SYM_RBRACES )
    {
        switch (tokenItor->kind) {

            // BLOCK
            case TokenEnum::SYM_LBRACES: {
                tokenItor++;
                std::cout << "Parser::Parse() TokenEnum::SYM_LBRACES" << std::endl;
                statementsNodeSP->children.push_back(ParseBlock(returnable));
                tokenItor++;
                break;
            }

            // DECLARATION
            case TokenEnum::KWD_DECL: {
                std::cout << "Parser::Parse() TokenEnum::KWD_DECL" << std::endl;
                statementsNodeSP->children.push_back(ParseDeclaration(statementsNodeSP->symbolTable));
                break;
            }

            // TOK_IDENTIFIER therefore ASSIGNMENT
            case TokenEnum::TOK_IDENTIFIER: {
                std::cout << "Parser::Parse() TokenEnum::TOK_IDENTIFIER" << std::endl;
                statementsNodeSP->children.push_back(ParseAssignment(returnable));
                break;
            }

            // WHILE Statement
            case TokenEnum::KWD_WHILE:{
                std::cout << "Parser::Parse() TokenEnum::KWD_WHILE" << std::endl;
                statementsNodeSP->children.push_back(ParseWhile(returnable));
                break;
            }

            // IF Statement
            case TokenEnum::KWD_IF:{
                std::cout << "Parser::Parse() TokenEnum::KWD_IF" << std::endl;
                statementsNodeSP->children.push_back(ParseIf(returnable));
                break;
            }

            // RETURN Statement
            case TokenEnum::KWD_RETURN:{
                if ( returnable ){
                    std::cout << "Parser::ParseFunctionBlock() TokenEnum::KWD_RETURN" << std::endl;
                    statementsNodeSP->children.push_back(ParseReturn());
                    break;
                }
            }

            // PROCEDURE
            case TokenEnum::KWD_PROC: {
                if ( !returnable ) {
                    // NOT RETURNABLE THEREFORE TOPLEVEL?
                    std::cout << "Parser::Parse() TokenEnum::KWD_PROC" << std::endl;
                    statementsNodeSP->children.push_back(ParseProcedure());
                    break;
                }
            }

            // FUNCTION
            case TokenEnum::KWD_FUNC:{
                if ( !returnable ) {
                    // NOT RETURNABLE THEREFORE TOPLEVEL?
                    std::cout << "Parser::Parse() TokenEnum::KWD_FUNC" << std::endl;
                    statementsNodeSP->children.push_back(ParseFunction());
                    break;
                }
            }
        }
    }

    return statementsNodeSP;
}

// ----------------------------------------------------------------------

ASTNode * Parser::ParseExpression(bool returnable) {

    ASTNode * lhsNodeSP = nullptr;
    ASTNode * exprNodeSP = nullptr;
    ASTNode * rhsNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::TOK_NUMBER) {
        lhsNodeSP = ParseNumber();
    }
    else if( tokenItor->kind == TokenEnum::TOK_IDENTIFIER ) {
        lhsNodeSP = ParseIdentifier();
    }
    else {
        return nullptr;
    }

    if ( ( (tokenItor+1)->kind == TokenEnum::OP_ADD )
            || ( (tokenItor+1)->kind == TokenEnum::OP_SUB )
            || ( (tokenItor+1)->kind == TokenEnum::OP_MUL )
            || ( (tokenItor+1)->kind == TokenEnum::OP_DIV ) ) {

        std::cout << "ParseAssignment() TokenEnum::SYM_ASSIGN" << std::endl;

        tokenItor++;
        exprNodeSP = ParseOperator();
        tokenItor++;
        exprNodeSP->children.push_back(lhsNodeSP);
        exprNodeSP->children.push_back(ParseExpression());
        return exprNodeSP;
    }

    tokenItor++;
    return lhsNodeSP;
}


// ----------------------------------------------------------------------

OperatorASTNode * Parser::ParseOperator() {
    OperatorASTNode * opNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::OP_ADD) {
        std::cout << "ParseValue() TokenEnum::OP_ADD" << std::endl;
        opNodeSP = new OperatorASTNode("+");
    }
    else if ( tokenItor->kind == TokenEnum::OP_SUB) {
        std::cout << "ParseValue() TokenEnum::OP_SUB" << std::endl;
        opNodeSP = new OperatorASTNode("-");
    }
    else if ( tokenItor->kind == TokenEnum::OP_MUL) {
        std::cout << "ParseValue() TokenEnum::OP_MUL" << std::endl;
        opNodeSP = new OperatorASTNode("*");
    }
    else if ( tokenItor->kind == TokenEnum::OP_DIV) {
        std::cout << "ParseValue() TokenEnum::OP_DIV" << std::endl;
        opNodeSP = new OperatorASTNode("/");
    }

    return opNodeSP;
}

// ----------------------------------------------------------------------

NumberASTNode * Parser::ParseNumber() {
    NumberASTNode * valueNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::TOK_NUMBER) {
        std::cout << "ParseNumber() TokenEnum::TOK_NUMBER" << std::endl;
        valueNodeSP = new NumberASTNode(tokenItor->name);
    }

    return valueNodeSP;
}

IdentifierASTNode * Parser::ParseIdentifier() {
    IdentifierASTNode * nodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {
        std::cout << "ParseIdentifier() TokenEnum::TOK_IDENTIFIER" << std::endl;
        nodeSP = new IdentifierASTNode(tokenItor->name);
    }

    return nodeSP;
}

// ----------------------------------------------------------------------

ProcedureASTNode * Parser::ParseProcedure() {

    ProcedureASTNode * statementNodeSP = nullptr;
    ASTNode * identifierNodeSP = nullptr;
    ASTNode * varsListNodeSP = nullptr;
    ASTNode * blockNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::KWD_PROC ) {
        std::cout << "ParseProcedure() TokenEnum::KWD_PROC" << std::endl;
        statementNodeSP = new ProcedureASTNode();

        tokenItor++;

        if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {
            std::cout << "ParseProcedure() TokenEnum::TOK_IDENTIFIER" << std::endl;
            identifierNodeSP = new ASTNode("ID", tokenItor->name);
            statementNodeSP->children.push_back(identifierNodeSP);

            tokenItor++;

            if ( tokenItor->kind == TokenEnum::SYM_LPAREN) {
                tokenItor++;

                if (tokenItor->kind != TokenEnum::SYM_RPAREN) {
                    varsListNodeSP = ParseIdentList(statementNodeSP->symbolTable);
                    statementNodeSP->children.push_back(varsListNodeSP);
                }

                if (tokenItor->kind == TokenEnum::SYM_RPAREN) {
                    tokenItor++;

                    if ( tokenItor->kind == TokenEnum::SYM_LBRACES) {
                        tokenItor++;

                        blockNodeSP = ParseBlock();
                        statementNodeSP->children.push_back(blockNodeSP);

                        if (tokenItor->kind == TokenEnum::SYM_RBRACES) {
                            tokenItor++;

                            return statementNodeSP;
                        }
                    }
                }
            }
        }
    }
}

// ----------------------------------------------------------------------

FunctionASTNode * Parser::ParseFunction() {

    FunctionASTNode * statementNodeSP = nullptr;
    ASTNode * identifierNodeSP = nullptr;
    ASTNode * varsListNodeSP = nullptr;
    ASTNode * blockNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::KWD_FUNC ) {
        std::cout << "ParseFunction() TokenEnum::KWD_FUNC" << std::endl;
        statementNodeSP = new FunctionASTNode();
        tokenItor++;

        if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {
            std::cout << "ParseFunction() TokenEnum::TOK_IDENTIFIER" << std::endl;
            identifierNodeSP = new ASTNode("ID", tokenItor->name);
            statementNodeSP->children.push_back(identifierNodeSP);

            tokenItor++;

            if ( tokenItor->kind == TokenEnum::SYM_LPAREN) {
                tokenItor++;

                if (tokenItor->kind != TokenEnum::SYM_RPAREN) {
                    varsListNodeSP = ParseIdentList(statementNodeSP->symbolTable, SymbolTable::Scope::param);
                    statementNodeSP->children.push_back(varsListNodeSP);
                }

                if (tokenItor->kind == TokenEnum::SYM_RPAREN) {
                    tokenItor++;

                    if ( tokenItor->kind == TokenEnum::SYM_LBRACES) {
                        tokenItor++;

                        blockNodeSP = ParseBlock(true);
                        statementNodeSP->children.push_back(blockNodeSP);

                        if (tokenItor->kind == TokenEnum::SYM_RBRACES) {
                            tokenItor++;

                            return statementNodeSP;
                        }
                    }
                }
            }
        }
    }
}

// ----------------------------------------------------------------------

ReturnASTNode * Parser::ParseReturn() {
    ReturnASTNode * statementNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::KWD_RETURN) {
        std::cout << "ParseDeclaration() TokenEnum::KWD_RETURN" << std::endl;
        statementNodeSP = new ReturnASTNode();
        tokenItor++;

        statementNodeSP->children.push_back(ParseExpression());
    }

    return statementNodeSP;
}
