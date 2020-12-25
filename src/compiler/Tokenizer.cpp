//
// Created by sean on 24/09/2020.
//

#include "Tokenizer.h"
#include "./Tokens.h"
extern Token tokens[];

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

        for (unsigned int i = 0; i < 10; i++ ) {
            if ( tokenString == tokens[i].name )
            {
                Token newTok(tokens[i]);        // copy!
                newTok.file = currentFile;
                newTok.line = currentLine;
                outputTokens.push_back(newTok);
                return true;
            }
        }

        Token newTok(TokenEnum::IDENTIFIER, tokenString);
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

        Token newTok(TokenEnum::NUMBER, numberStr);
        newTok.file = currentFile;
        newTok.line = currentLine;
//        newTok.number = currentLine;
        outputTokens.push_back(newTok);

        return true;
    }

    //
    // other symbols...
    //

    switch (currentChar) {

        case '\0': {
            Token newTok(TokenEnum::END_OF_FILE, "eof");
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
            Token newTok(TokenEnum::OP_GT, ">");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }

        case '<': {
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

        case ',': {
            Token newTok(TokenEnum::SYM_COMMA, ",");
            newTok.file = currentFile;
            newTok.line = currentLine;
            outputTokens.push_back(newTok);
            return true;
        }


//        case '&': {
//            char nextChar = lexingStr[lexingPos];
//
//            if (nextChar == '&') {
//                tokens.push_back(std::make_pair(Token::OP_AND, "&&"));
//                tokensWithLine.push_back(std::make_tuple(Token::OP_AND, "&&", currentLine));
//
//                ++lexingPos;
//                return Token::OP_AND;
//            }
//
//            std::cerr << "TOKENIZER ERROR after \'&\' at Line " << currentLine << " Got " << currentChar << std::endl;
//            return Token::ERROR;
//        }
//
//        case '|': {
//            char nextChar = lexingStr[lexingPos];
//
//            if (nextChar == '|') {
//                tokens.push_back(std::make_pair(Token::OP_OR, "||"));
//                tokensWithLine.push_back(std::make_tuple(Token::OP_OR, "||", currentLine));
//
//                ++lexingPos;
//                return Token::OP_OR;
//            }
//
//            std::cerr << "TOKENIZER ERROR after \'|\' at Line " << currentLine << " Got " << currentChar << std::endl;
//            return Token::ERROR;
//        }
//
//        case '!': {
//            char nextChar = lexingStr[lexingPos];
//
//            if (nextChar == '=') {
//                tokens.push_back(std::make_pair(Token::OP_NE, "!="));
//                tokensWithLine.push_back(std::make_tuple(Token::OP_NE, "!=", currentLine));
//
//                ++lexingPos;
//                return Token::OP_NE;
//            }
//            std::cerr << "TOKENIZER ERROR after \'!\' at Line " << currentLine << " Got " << currentChar << std::endl;
//            return Token::ERROR;
//        }
//
//        default: {
//            std::cerr << "TOKENIZER WARNING Line (" << currentLine << ") Possibly '" << currentChar << "'" << std::endl;
//            return Token::ERROR;
//        }

    }
    return false;
}

void Tokenizer::Scan() {
    bool result;
    do {
        result = ScanToken();
    } while (result);
}


