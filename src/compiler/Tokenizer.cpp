//
// Created by sean on 24/09/2020.
//

//----------------------------------------------------------------------

#include <iostream>

//----------------------------------------------------------------------

#include "Tokenizer.h"
#include "./Tokens.h"
extern Token tokens[];

//----------------------------------------------------------------------

bool Tokenizer::ScanToken() {
    char currentChar = inputString[currentPosition++];
    std::string currentFile = this->filename;

    LABEL_STARTSCAN:


    //
    // skip whitespace
    //
    while (currentChar == ' ' || currentChar == '\t' || currentChar == '\n') {
        if (currentChar == '\n') {
            currentLine++;
        }
        currentChar = inputString[currentPosition++];
    }


    //
    // skip comments
    //
    if (currentChar == '#') {
        do{
            currentChar = inputString[currentPosition++];
        } while (currentChar != '\n');
        currentLine++;
        currentChar = inputString[currentPosition++];
        goto LABEL_STARTSCAN;
    }


    //
    // token, probably keyword
    //
    if (isalpha(currentChar) ) {

        // starting a new token ... probably a keyword
        std::string tokenString;

        // get the next character
        tokenString += currentChar;
        currentChar = inputString[currentPosition++];

        // scan forward letters, numbers and underscores only
        while (isalnum(currentChar) || currentChar == '_') {
            tokenString += currentChar;
            currentChar = inputString[currentPosition++];
        }
        --currentPosition;

        // TODO CHANGE THIS INTO MODERN c++ with proper lookup
        for (unsigned int i = 0; i < 21; i++ ) {
            if ( tokenString == tokens[i].name )
            {
                Token newTok(tokens[i]);                // copy!
                newTok.file = currentFile;
                newTok.line = currentLine;
                outputTokens.push_back(newTok);
                return true;
            }
        }

        Token newTok(TokenEnum::TOK_IDENTIFIER, tokenString);
        newTok.file = currentFile;
        newTok.line = currentLine;
        outputTokens.push_back(newTok);
        return true;
    }


    //
    // parse and store strings in a table
    //
    if ( (currentChar == '\"') || (currentChar == '\'') ){
        // starting a new token ... probably a string
        std::string stringString;

        // advance to the next character skipping quote
        currentChar = inputString[currentPosition++];

        do{
            stringString += currentChar;
            currentChar = inputString[currentPosition++];
        } while ( ( currentChar != '\n') && (currentChar != '\"') && (currentChar != '\'') );

//        std::cerr << "STRING DEBUG " <<  stringString << std::endl;

        Token newTok(TokenEnum::TOK_STRING, stringString);
        newTok.file = currentFile;
        newTok.line = currentLine;
        outputTokens.push_back(newTok);

        return true;
    }

    //
    // numbers
    //
    // def: start with [0-9.], follow by [0-9.]
    // number only has 'float' type
    if (isdigit(currentChar) || currentChar == '.') {
        std::string numberStr;
        numberStr += currentChar;
        currentChar = inputString[currentPosition++];
        while (isdigit(currentChar) || currentChar == '.') {
            numberStr += currentChar;
            currentChar = inputString[currentPosition++];
        }
        --currentPosition;

        Token newTok(TokenEnum::TOK_NUMBER, numberStr);
        newTok.file = currentFile;
        newTok.line = currentLine;
        outputTokens.push_back(newTok);

        return true;
    }

    //
    // other symbols...
    //

    switch (currentChar) {

        case '\0': {
            Token newTok(TokenEnum::TOK_END_OF_FILE, "eof");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return false;
        }

        case '{': {
            Token newTok(TokenEnum::SYM_LBRACES, "{");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '}': {
            Token newTok(TokenEnum::SYM_RBRACES, "}");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '(': {
            Token newTok(TokenEnum::SYM_LPAREN, "(");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case ')': {
            Token newTok(TokenEnum::SYM_RPAREN, ")");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '[': {
            Token newTok(TokenEnum::SYM_LBRACKET, "[");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case ']': {
            Token newTok(TokenEnum::SYM_RBRACKET, "]");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case ';': {
            Token newTok(TokenEnum::SYM_SEMICOLON, ";");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case ':': {
            Token newTok(TokenEnum::SYM_COLON, ":");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '=': {
            char nextChar = inputString[currentPosition];

            if (nextChar == '=') {
                Token newTok(TokenEnum::OP_EQ, "==");
                newTok.file = currentFile;
                newTok.line = currentLine;
                outputTokens.push_back(newTok);
                ++currentPosition;
                return true;
            }

            Token newTok(TokenEnum::SYM_ASSIGN, "=");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '>': {
            char nextChar = inputString[currentPosition];

            if (nextChar == '=') {
                Token newTok(TokenEnum::OP_GTE, ">=");
                newTok.file = currentFile;
                newTok.line = currentLine;
                outputTokens.push_back(newTok);
                ++currentPosition;
                return true;
            }

            Token newTok(TokenEnum::OP_GT, ">");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '<': {
            char nextChar = inputString[currentPosition];

            if (nextChar == '=') {
                Token newTok(TokenEnum::OP_LTE, "<=");
                newTok.file = currentFile;
                newTok.line = currentLine;
                outputTokens.push_back(newTok);
                ++currentPosition;
                return true;
            }

            Token newTok(TokenEnum::OP_LT, "<");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '+': {
            Token newTok(TokenEnum::OP_ADD, "+");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '-': {
            Token newTok(TokenEnum::OP_SUB, "-");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '*': {
            Token newTok(TokenEnum::OP_MUL, "*");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '/': {
            Token newTok(TokenEnum::OP_DIV, "/");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '%': {
            Token newTok(TokenEnum::OP_MOD, "%");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '^': {
            Token newTok(TokenEnum::OP_POW, "^");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case ',': {
            Token newTok(TokenEnum::SYM_COMMA, ",");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '!': {
            char nextChar = inputString[currentPosition];

            if (nextChar == '=') {
                Token newTok(TokenEnum::OP_NE, "!=");
                newTok.file = currentFile;
                newTok.line = currentLine;
                outputTokens.push_back(newTok);
                ++currentPosition;
                return true;
            }

            std::cerr << "ERROR : Unknown Token Expected !=" << std::endl;
            return false;
        }
    }

    std::cerr << "ERROR : Unknown Token " << std::endl;
    return false;
}

//----------------------------------------------------------------------

void Tokenizer::Scan() {
    bool result;
    do {
        result = ScanToken();
    } while (result);
}

//----------------------------------------------------------------------
