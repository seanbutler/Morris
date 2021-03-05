//
// Created by sean on 25/09/2020.
//

#include "Parser.h"
#include "AST.h"

#include <iostream>

// ----------------------------------------------------------------------

ModuleASTNode * Parser::Parse() {

    tokenItor = tokens.begin();
    ModuleASTNode * ast = ParseModule();

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
                statementsNodePtr->children.push_back(ParseBlock(statementsNodePtr, false));
                tokenItor++;
                break;
            }

            // DECLARATION
            case TokenEnum::KWD_DECL: {
                std::cout << "Parser::Parse() TokenEnum::KWD_DECL" << std::endl;
                statementsNodePtr->children.push_back(ParseDeclaration(statementsNodePtr));
                break;
            }

            // TOK_IDENTIFIER therefore ASSIGNMENT
            case TokenEnum::TOK_IDENTIFIER: {
                std::cout << "Parser::Parse() TokenEnum::TOK_IDENTIFIER" << std::endl;
                statementsNodePtr->children.push_back(ParseAssignment(statementsNodePtr));
                break;
            }

            // WHILE statement
            case TokenEnum::KWD_WHILE: {
                std::cout << "Parser::Parse() TokenEnum::KWD_WHILE" << std::endl;
                statementsNodePtr->children.push_back(ParseWhile(statementsNodePtr));
                break;
            }

            // IF statement
            case TokenEnum::KWD_IF: {
                std::cout << "Parser::Parse() TokenEnum::KWD_IF" << std::endl;
                statementsNodePtr->children.push_back(ParseIf(statementsNodePtr));
                break;
            }

            // PROCEDURE
            case TokenEnum::KWD_PROC: {
                std::cout << "Parser::Parse() TokenEnum::KWD_PROC" << std::endl;
                statementsNodePtr->children.push_back(ParseProcedure(statementsNodePtr));
                break;
            }

            // FUNCTION
            case TokenEnum::KWD_FUNC: {
                std::cout << "Parser::Parse() TokenEnum::KWD_FUNC" << std::endl;
                statementsNodePtr->children.push_back(ParseFunction(statementsNodePtr));
                break;
            }

            // OUTPUT
            case TokenEnum::KWD_OUTPUT: {
                std::cout << "Parser::Parse() TokenEnum::KWD_OUTPUT" << std::endl;
                statementsNodePtr->children.push_back(ParseOutput(statementsNodePtr));
                break;
            }

            // SETPOS
            case TokenEnum::KWD_SETPOS: {
                std::cout << "Parser::Parse() TokenEnum::KWD_FUNC" << std::endl;
                statementsNodePtr->children.push_back(ParseSetpos(statementsNodePtr));
                break;
            }

            case TokenEnum::KWD_SETCOL:{
                std::cout << "Parser::Parse() TokenEnum::KWD_SETCOL" << std::endl;
                statementsNodePtr->children.push_back(ParseSetcol(statementsNodePtr));
                break;
            }

            case TokenEnum::KWD_SETVEL:{
                std::cout << "Parser::Parse() TokenEnum::KWD_SETVEL" << std::endl;
                statementsNodePtr->children.push_back(ParseSetvel(statementsNodePtr));
                break;
            }

            case TokenEnum::KWD_SETSPRITE:{
                std::cout << "Parser::Parse() TokenEnum::KWD_SETSPRITE" << std::endl;
                statementsNodePtr->children.push_back(ParseSetsprite(statementsNodePtr));
                break;
            }



            // SPAWN
            case TokenEnum::KWD_SPAWN: {
                std::cout << "Parser::Parse() TokenEnum::KWD_SPAWN" << std::endl;
                statementsNodePtr->children.push_back(ParseSpawn(statementsNodePtr));
                break;
            }

//            default: {
//                std::cout << "ERROR - Unknown Parse Error" << std::endl;
//            }

        }
    }

    return statementsNodePtr;

}

// ----------------------------------------------------------------------

DeclarationASTNode * Parser::ParseDeclaration(ASTNode *P) {
    DeclarationASTNode * declarationNodeSP = nullptr;

    // is this if redundant?
    if ( tokenItor->kind == TokenEnum::KWD_DECL) {
        std::cout << "ParseDeclaration() TokenEnum::KWD_DECL" << std::endl;
        declarationNodeSP = new DeclarationASTNode(P);
        tokenItor++;
        declarationNodeSP->children.push_back(ParseIdentList(declarationNodeSP));
    }

    return declarationNodeSP;

}

// ----------------------------------------------------------------------

IdentifierListASTNode * Parser::ParseIdentList(ASTNode *P) {

    IdentifierListASTNode* listNodeSP = nullptr;
    ASTNode* identifierNodeSP;

    if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {

        listNodeSP = new IdentifierListASTNode();
        std::cout << "ParseIdentList() TokenEnum::TOK_IDENTIFIER" << std::endl;
        identifierNodeSP = new ASTNode("ID-DECL", tokenItor->name);
        listNodeSP->children.push_back(identifierNodeSP);

        symbolTable.Insert(tokenItor->name, SymbolTable::number, SymbolTable::local);
        tokenItor++;

        while ( tokenItor->kind == TokenEnum::SYM_COMMA ) {
            std::cout << "ParseIdentList() TokenEnum::SYM_COMMA" << std::endl;

            tokenItor++;

            if (tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {
                std::cout << "ParseIdentList() TokenEnum::TOK_IDENTIFIER" << std::endl;
                identifierNodeSP = new ASTNode("ID-DEC", tokenItor->name);
                listNodeSP->children.push_back(identifierNodeSP);

                symbolTable.Insert(tokenItor->name, SymbolTable::number, SymbolTable::local);

                tokenItor++;
            }
            else
            {
                std::cout << "ERROR - Parse Identifier List Item, Expected Identifier Found " << tokenItor->kind << " " << tokenItor->name << std::endl;
            }
        }
    }
    else
    {
        std::cout << "ERROR - Parse Identifier List, Expected Identifier Found " << tokenItor->kind << " " << tokenItor->name << std::endl;

    }

    return listNodeSP;
}

// ----------------------------------------------------------------------

AssignmentASTNode * Parser::ParseAssignment(ASTNode *P, bool returnable) {

    AssignmentASTNode * assignmentNodeSP = nullptr;
    ASTNode * identifierNodeSP;
    ASTNode * rhsNodeSP;

    if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER ) {

        std::cout << "ParseAssignment() TokenEnum::TOK_IDENTIFIER" << std::endl;
        identifierNodeSP = new LHSIdentifierASTNode(tokenItor->name);
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

IfASTNode * Parser::ParseIf(ASTNode *P, bool returnable) {

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
                    else
                    {
                        std::cerr << "Parse Error : If Expected } Right Braces" << std::endl;
                    }
                }
                else
                {
                    std::cerr << "Parse Error : If Expected { Left Braces" << std::endl;
                }
            }
            else
            {
                std::cerr << "Parse Error : If Expected ) Right Parenthesis" << std::endl;
            }
        }
        else
        {
            std::cerr << "Parse Error : If Expected ( Left Parenthesis" << std::endl;
        }
    }
}

// ----------------------------------------------------------------------

WhileASTNode * Parser::ParseWhile(ASTNode *P, bool returnable) {

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

BlockASTNode * Parser::ParseBlock(ASTNode *P, bool returnable) {

    std::cout << "ParseBlock()" << std::endl;
    BlockASTNode * statementsNodeSP = nullptr;
    statementsNodeSP = new BlockASTNode(P);

    symbolTable.IncreaseNestLevel();

    while ( tokenItor->kind != TokenEnum::SYM_RBRACES )
    {
        switch (tokenItor->kind) {

            // BLOCK
            case TokenEnum::SYM_LBRACES: {
                tokenItor++;
                std::cout << "Parser::Parse() TokenEnum::SYM_LBRACES" << std::endl;
                statementsNodeSP->children.push_back(ParseBlock(P, returnable));
                tokenItor++;
                break;
            }

            // DECLARATION
            case TokenEnum::KWD_DECL: {
                std::cout << "Parser::Parse() TokenEnum::KWD_DECL" << std::endl;
                statementsNodeSP->children.push_back(ParseDeclaration(P));
                break;
            }

            // TOK_IDENTIFIER therefore ASSIGNMENT
            case TokenEnum::TOK_IDENTIFIER: {
                std::cout << "Parser::Parse() TokenEnum::TOK_IDENTIFIER" << std::endl;
                statementsNodeSP->children.push_back(ParseAssignment(P, returnable));
                break;
            }

            // WHILE Statement
            case TokenEnum::KWD_WHILE:{
                std::cout << "Parser::Parse() TokenEnum::KWD_WHILE" << std::endl;
                statementsNodeSP->children.push_back(ParseWhile(P, returnable));
                break;
            }

            // IF Statement
            case TokenEnum::KWD_IF:{
                std::cout << "Parser::Parse() TokenEnum::KWD_IF" << std::endl;
                statementsNodeSP->children.push_back(ParseIf(P, returnable));
                break;
            }

            // RETURN Statement
            case TokenEnum::KWD_RETURN:{
                if ( returnable ){
                    std::cout << "Parser::ParseFunctionBlock() TokenEnum::KWD_RETURN" << std::endl;
                    statementsNodeSP->children.push_back(ParseReturn(P));
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

            // OUTPUT
            case TokenEnum::KWD_OUTPUT:{
                std::cout << "Parser::Parse() TokenEnum::KWD_OUTPUT" << std::endl;
                statementsNodeSP->children.push_back(ParseOutput(statementsNodeSP));
                break;
            }

            // SETPOS
            case TokenEnum::KWD_SETPOS:{
                std::cout << "Parser::Parse() TokenEnum::KWD_SETPOS" << std::endl;
                statementsNodeSP->children.push_back(ParseSetpos(statementsNodeSP));
                break;
            }

            case TokenEnum::KWD_SETVEL:{
                std::cout << "Parser::Parse() TokenEnum::KWD_SETVEL" << std::endl;
                statementsNodeSP->children.push_back(ParseSetvel(statementsNodeSP));
                break;
            }

            case TokenEnum::KWD_SETCOL:{
                std::cout << "Parser::Parse() TokenEnum::KWD_SETCOL" << std::endl;
                statementsNodeSP->children.push_back(ParseSetcol(statementsNodeSP));
                break;
            }
        }
    }

    symbolTable.DecreaseNestLevel();

    return statementsNodeSP;
}

// ----------------------------------------------------------------------

ASTNode * Parser::ParseExpression(ASTNode *P, bool returnable) {

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
            || ( (tokenItor+1)->kind == TokenEnum::OP_DIV )
            || ( (tokenItor+1)->kind == TokenEnum::OP_MOD )
            || ( (tokenItor+1)->kind == TokenEnum::OP_EQ )
            || ( (tokenItor+1)->kind == TokenEnum::OP_NE )
            || ( (tokenItor+1)->kind == TokenEnum::OP_GT )
            || ( (tokenItor+1)->kind == TokenEnum::OP_GTE )
            || ( (tokenItor+1)->kind == TokenEnum::OP_LT )
            || ( (tokenItor+1)->kind == TokenEnum::OP_LTE ) ) {

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

OperatorASTNode * Parser::ParseOperator(ASTNode *P) {
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
    else if ( tokenItor->kind == TokenEnum::OP_MOD) {
        std::cout << "ParseValue() TokenEnum::OP_MOD" << std::endl;
        opNodeSP = new OperatorASTNode("%");
    }
    else if ( tokenItor->kind == TokenEnum::OP_EQ) {
        std::cout << "ParseValue() TokenEnum::OP_EQ" << std::endl;
        opNodeSP = new OperatorASTNode("==");
    }
    else if ( tokenItor->kind == TokenEnum::OP_NE) {
        std::cout << "ParseValue() TokenEnum::OP_NE" << std::endl;
        opNodeSP = new OperatorASTNode("!=");
    }
    else if ( tokenItor->kind == TokenEnum::OP_POW) {
        std::cout << "ParseValue() TokenEnum::OP_POW" << std::endl;
        opNodeSP = new OperatorASTNode("^");
    }
    else if ( tokenItor->kind == TokenEnum::OP_GT) {
        std::cout << "ParseValue() TokenEnum::OP_GT" << std::endl;
        opNodeSP = new OperatorASTNode(">");
    }
    else if ( tokenItor->kind == TokenEnum::OP_GTE) {
        std::cout << "ParseValue() TokenEnum::OP_GTE" << std::endl;
        opNodeSP = new OperatorASTNode(">=");
    }
    else if ( tokenItor->kind == TokenEnum::OP_LT) {
        std::cout << "ParseValue() TokenEnum::OP_LT" << std::endl;
        opNodeSP = new OperatorASTNode("<");
    }
    else if ( tokenItor->kind == TokenEnum::OP_LTE) {
        std::cout << "ParseValue() TokenEnum::OP_LTE" << std::endl;
        opNodeSP = new OperatorASTNode("<=");
    }

    return opNodeSP;
}

// ----------------------------------------------------------------------

NumberASTNode * Parser::ParseNumber(ASTNode *P) {
    NumberASTNode * valueNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::TOK_NUMBER) {
        std::cout << "ParseNumber() TokenEnum::TOK_NUMBER" << std::endl;
        valueNodeSP = new NumberASTNode(tokenItor->name);
    }

    return valueNodeSP;
}


StringASTNode * Parser::ParseString(ASTNode *P) {
    StringASTNode * nodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::TOK_STRING) {
        std::cout << "ParseString() TokenEnum::TOK_STRING " << tokenItor->name << " " << std::endl;
        nodeSP = new StringASTNode(tokenItor->name);
    }

    return nodeSP;
}


RHSIdentifierASTNode * Parser::ParseIdentifier(ASTNode *P) {
    RHSIdentifierASTNode * nodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {
        std::cout << "ParseIdentifier() TokenEnum::TOK_IDENTIFIER" << std::endl;
        nodeSP = new RHSIdentifierASTNode(tokenItor->name);
    }

    return nodeSP;
}

// ----------------------------------------------------------------------

ProcedureASTNode * Parser::ParseProcedure(ASTNode *P) {

    ProcedureASTNode * statementNodeSP = nullptr;
    ASTNode * identifierNodeSP = nullptr;
    ASTNode * varsListNodeSP = nullptr;
    ASTNode * blockNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::KWD_PROC ) {
        std::cout << "ParseProcedure() TokenEnum::KWD_PROC" << std::endl;
        statementNodeSP = new ProcedureASTNode(P);

        tokenItor++;

        if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {
            std::cout << "ParseProcedure() TokenEnum::TOK_IDENTIFIER" << std::endl;
            identifierNodeSP = new RHSIdentifierASTNode(tokenItor->name, statementNodeSP);
            statementNodeSP->children.push_back(identifierNodeSP);

            tokenItor++;

            if ( tokenItor->kind == TokenEnum::SYM_LPAREN) {
                tokenItor++;

                if (tokenItor->kind != TokenEnum::SYM_RPAREN) {
                    varsListNodeSP = ParseIdentList(statementNodeSP);
                    statementNodeSP->children.push_back(varsListNodeSP);
                }

                if (tokenItor->kind == TokenEnum::SYM_RPAREN) {
                    tokenItor++;

                    if ( tokenItor->kind == TokenEnum::SYM_LBRACES) {
                        tokenItor++;

                        blockNodeSP = ParseBlock(statementNodeSP);
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

FunctionASTNode * Parser::ParseFunction(ASTNode *P) {

    FunctionASTNode * statementNodeSP = nullptr;
    ASTNode * identifierNodeSP = nullptr;
    ASTNode * varsListNodeSP = nullptr;
    ASTNode * blockNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::KWD_FUNC ) {
        std::cout << "ParseFunction() TokenEnum::KWD_FUNC" << std::endl;
        statementNodeSP = new FunctionASTNode(P);
        tokenItor++;

        if ( tokenItor->kind == TokenEnum::TOK_IDENTIFIER) {
            std::cout << "ParseFunction() TokenEnum::TOK_IDENTIFIER" << std::endl;
            identifierNodeSP = new RHSIdentifierASTNode(tokenItor->name, statementNodeSP);
            statementNodeSP->children.push_back(identifierNodeSP);

            tokenItor++;

            if ( tokenItor->kind == TokenEnum::SYM_LPAREN) {
                tokenItor++;

                if (tokenItor->kind != TokenEnum::SYM_RPAREN) {
                    varsListNodeSP = ParseIdentList(statementNodeSP);
                    statementNodeSP->children.push_back(varsListNodeSP);
                }

                if (tokenItor->kind == TokenEnum::SYM_RPAREN) {
                    tokenItor++;

                    if ( tokenItor->kind == TokenEnum::SYM_LBRACES) {
                        tokenItor++;

                        blockNodeSP = ParseBlock(statementNodeSP, true);
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

ReturnASTNode * Parser::ParseReturn(ASTNode *P) {
    ReturnASTNode * statementNodeSP = nullptr;

    if ( tokenItor->kind == TokenEnum::KWD_RETURN) {
        std::cout << "ParseReturn() TokenEnum::KWD_RETURN" << std::endl;
        statementNodeSP = new ReturnASTNode(P);
        tokenItor++;

        statementNodeSP->children.push_back(ParseExpression(statementNodeSP));
    }

    return statementNodeSP;
}

// ----------------------------------------------------------------------

OutputASTNode * Parser::ParseOutput(ASTNode *P) {
    OutputASTNode * statementNodeSP = nullptr;
    ASTNode * rhsNodeSP;

    if ( tokenItor->kind == TokenEnum::KWD_OUTPUT ) {
        statementNodeSP = new OutputASTNode();

        tokenItor++;
        rhsNodeSP = ParseExpression();
        statementNodeSP->children.push_back(rhsNodeSP);
    }

    return statementNodeSP;
}


// ----------------------------------------------------------------------

SetposASTNode * Parser::ParseSetpos(ASTNode *P) {
    SetposASTNode * statementNodeSP = nullptr;
    ASTNode * xExprNodeSP;
    ASTNode * yExprNodeSP;

    if ( tokenItor->kind == TokenEnum::KWD_SETPOS ) {
        statementNodeSP = new SetposASTNode();

        tokenItor++;

        if ( tokenItor->kind == TokenEnum::SYM_LPAREN ) {
            tokenItor++;
            xExprNodeSP = ParseExpression();
            statementNodeSP->children.push_back(xExprNodeSP);

            if (tokenItor->kind == TokenEnum::SYM_COMMA) {

                tokenItor++;
                yExprNodeSP = ParseExpression();
                statementNodeSP->children.push_back(yExprNodeSP);

                if (tokenItor->kind == TokenEnum::SYM_RPAREN) {
                    tokenItor++;
                }
                else
                {
                    std::cerr << "Parse Error : Setpos Expected ) Right Parenthesis" << std::endl;
                }
            }
            else
            {
                std::cerr << "Parse Error : Setpos Expected , Comma" << std::endl;
            }
        }
    }

    return statementNodeSP;
}

// ----------------------------------------------------------------------

SetvelASTNode * Parser::ParseSetvel(ASTNode *P) {
    SetvelASTNode * statementNodeSP = nullptr;
    ASTNode * xExprNodeSP;
    ASTNode * yExprNodeSP;

    if ( tokenItor->kind == TokenEnum::KWD_SETVEL ) {
        statementNodeSP = new SetvelASTNode();

        tokenItor++;

        if ( tokenItor->kind == TokenEnum::SYM_LPAREN ) {
            tokenItor++;
            xExprNodeSP = ParseExpression();
            statementNodeSP->children.push_back(xExprNodeSP);

            if (tokenItor->kind == TokenEnum::SYM_COMMA) {

                tokenItor++;
                yExprNodeSP = ParseExpression();
                statementNodeSP->children.push_back(yExprNodeSP);

                if (tokenItor->kind == TokenEnum::SYM_RPAREN) {
                    tokenItor++;
                }
                else
                {
                    std::cerr << "Parse Error : Setvel Expected ) Right Parenthesis" << std::endl;
                }
            }
            else
            {
                std::cerr << "Parse Error : Setvel Expected , Comma" << std::endl;
            }
        }
    }

    return statementNodeSP;
}

// ----------------------------------------------------------------------

SetspriteASTNode * Parser::ParseSetsprite(ASTNode *P) {
    SetspriteASTNode * statementNodeSP = nullptr;
    ASTNode * xExprNodeSP;
    ASTNode * yExprNodeSP;

    if ( tokenItor->kind == TokenEnum::KWD_SETSPRITE ) {
        statementNodeSP = new SetspriteASTNode();

        tokenItor++;

        if ( tokenItor->kind == TokenEnum::SYM_LPAREN ) {
            tokenItor++;
            xExprNodeSP = ParseExpression();
            statementNodeSP->children.push_back(xExprNodeSP);

            if (tokenItor->kind == TokenEnum::SYM_COMMA) {

                tokenItor++;
                yExprNodeSP = ParseExpression();
                statementNodeSP->children.push_back(yExprNodeSP);

                if (tokenItor->kind == TokenEnum::SYM_RPAREN) {
                    tokenItor++;
                }
                else
                {
                    std::cerr << "Parse Error : Setsprite Expected ) Right Parenthesis" << std::endl;
                }
            }
            else
            {
                std::cerr << "Parse Error : Setsprite Expected , Comma" << std::endl;
            }
        }
    }

    return statementNodeSP;
}


// ----------------------------------------------------------------------

SetcolASTNode * Parser::ParseSetcol(ASTNode *P) {
    SetcolASTNode * statementNodeSP = nullptr;
    ASTNode * xExprNodeSP;
    ASTNode * yExprNodeSP;
    ASTNode * zExprNodeSP;

    if ( tokenItor->kind == TokenEnum::KWD_SETCOL ) {
        statementNodeSP = new SetcolASTNode();

        tokenItor++;

        if ( tokenItor->kind == TokenEnum::SYM_LPAREN ) {
            tokenItor++;
            xExprNodeSP = ParseExpression();
            statementNodeSP->children.push_back(xExprNodeSP);

            if (tokenItor->kind == TokenEnum::SYM_COMMA) {

                tokenItor++;
                yExprNodeSP = ParseExpression();
                statementNodeSP->children.push_back(yExprNodeSP);

                if (tokenItor->kind == TokenEnum::SYM_COMMA) {

                    tokenItor++;
                    zExprNodeSP = ParseExpression();
                    statementNodeSP->children.push_back(zExprNodeSP);


                    if (tokenItor->kind == TokenEnum::SYM_RPAREN) {
                        tokenItor++;
                    }
                    else
                    {
                        std::cerr << "Parse Error : Setcol Expected ) Right Parenthesis" << std::endl;
                    }
                }
                else
                {
                    std::cerr << "Parse Error : Setcol Expected , Comma" << std::endl;
                }
            }
            else
            {
                std::cerr << "Parse Error : Setcol Expected , Comma" << std::endl;
            }
        }
    }

    return statementNodeSP;
}

// ----------------------------------------------------------------------

SpawnASTNode * Parser::ParseSpawn(ASTNode *P) {
    SpawnASTNode * statementNodeSP = nullptr;
    ASTNode * stringNodeSP;

    if ( tokenItor->kind == TokenEnum::KWD_SPAWN ) {
        statementNodeSP = new SpawnASTNode();

        tokenItor++;
        if ( tokenItor->kind == TokenEnum::SYM_LPAREN ) {

            tokenItor++;
            stringNodeSP = ParseString();
            statementNodeSP->children.push_back(stringNodeSP);

            tokenItor++;
            if (tokenItor->kind == TokenEnum::SYM_RPAREN) {
                tokenItor++;
            }
            else
            {
                std::cerr << "Parse Error : Spawn Expected ) Right Parenthesis" << std::endl;
            }
        }
        else
        {
            std::cerr << "Parse Error : Spawn Expected ( Left Parenthesis" << std::endl;
        }
    }

    return statementNodeSP;
}

// ----------------------------------------------------------------------
