//
// Created by sean on 04/01/2021.
//


#include "Assembler.h"
#include <string>
#include <algorithm>
#include <iostream>

INSTR Assembler::ScanInstruction() {

    char currentChar = assemblyStr[assemblyPos++];

    START_OF_SCAN:

    //
    // skip whitespace
    //
    while (currentChar == ' ' || currentChar == '\t' || currentChar == '\n') {
        if (currentChar == '\n') {
            currentLine++;
        }
        currentChar = assemblyStr[assemblyPos++];
        goto START_OF_SCAN;
    }

    //
    // comments begin with a semicolon (#) skip them
    //
    if (currentChar == '#') {
        do {
            currentChar = assemblyStr[assemblyPos++];
        } while (currentChar != '\n');
        currentLine++;
        goto START_OF_SCAN;
    }

    //
    // assembly instructions
    //
    if (isalpha(currentChar)) {

        // starting a new token ...
        std::string tokenString;

        // get the next character
        tokenString += currentChar;
        currentChar = assemblyStr[assemblyPos++];

        // scan forward letters and underscore
        while (isalnum(currentChar) || currentChar == '_') {
            tokenString += currentChar;
            currentChar = assemblyStr[assemblyPos++];
        }
        --assemblyPos;

//        std::cout << "asm got op/lab\t\t" << tokenString << std::endl;

        // TODO - turn this whole logic into a lookup or polymorphism or something better than this

        if (tokenString.compare("NOP") == 0) {
            this->instructions.push_back((int) INSTR::NOP);
            return INSTR::NOP;
        }

        if (tokenString.compare("HALT") == 0) {
            this->instructions.push_back((int) INSTR::HALT);
            return INSTR::HALT;
        }

        if (tokenString.compare("YIELD") == 0) {
            this->instructions.push_back((int) INSTR::YIELD);
            return INSTR::YIELD;
        }

        if (tokenString.compare("SAVE") == 0) {
            this->instructions.push_back((int) INSTR::SAVE);
            return INSTR::SAVE;
        }

        if (tokenString.compare("LOAD") == 0) {
            this->instructions.push_back((int) INSTR::LOAD);
            return INSTR::LOAD;
        }

        if (tokenString.compare("PUSH") == 0) {
            this->instructions.push_back((int) INSTR::PUSH);
            return INSTR::PUSH;
        }

        if (tokenString.compare("POP") == 0) {
            this->instructions.push_back((int) INSTR::POP);
            return INSTR::POP;
        }

        if (tokenString.compare("ADD") == 0) {
            this->instructions.push_back((int) INSTR::ADD);
            return INSTR::ADD;
        }
        if (tokenString.compare("SUB") == 0) {
            this->instructions.push_back((int) INSTR::SUB);
            return INSTR::SUB;
        }
        if (tokenString.compare("MUL") == 0) {
            this->instructions.push_back((int) INSTR::MUL);
            return INSTR::MUL;
        }
        if (tokenString.compare("DIV") == 0) {
            this->instructions.push_back((int) INSTR::DIV);
            return INSTR::DIV;
        }


        if (tokenString.compare("AND") == 0) {
            this->instructions.push_back((int) INSTR::AND);
            return INSTR::AND;
        }
        if (tokenString.compare("OR") == 0) {
            this->instructions.push_back((int) INSTR::OR);
            return INSTR::OR;
        }
        if (tokenString.compare("EQU") == 0) {
            this->instructions.push_back((int) INSTR::EQU);
            return INSTR::EQU;
        }
        if (tokenString.compare("NE") == 0) {
            this->instructions.push_back((int) INSTR::NE);
            return INSTR::NE;
        }
        if (tokenString.compare("GT") == 0) {
            this->instructions.push_back((int) INSTR::GT);
            return INSTR::GT;
        }
        if (tokenString.compare("GTE") == 0) {
            this->instructions.push_back((int) INSTR::GTE);
            return INSTR::GTE;
        }
        if (tokenString.compare("LT") == 0) {
            this->instructions.push_back((int) INSTR::LT);
            return INSTR::LT;
        }
        if (tokenString.compare("LTE") == 0) {
            this->instructions.push_back((int) INSTR::LTE);
            return INSTR::LTE;
        }



        if (tokenString.compare("OUTPUT") == 0) {
            this->instructions.push_back((int) INSTR::OUTPUT);
            return INSTR::OUTPUT;
        }
        if (tokenString.compare("INPUT") == 0) {
            this->instructions.push_back((int) INSTR::INPUT);
            return INSTR::INPUT;
        }


        if (tokenString.compare("JMP") == 0) {
            this->instructions.push_back((int) INSTR::JMP);
            return INSTR::JMP;
        }
        if (tokenString.compare("BRT") == 0) {
            this->instructions.push_back((int) INSTR::BRT);
            return INSTR::BRT;
        }
        if (tokenString.compare("BRF") == 0) {
            this->instructions.push_back((int) INSTR::BRF);
            return INSTR::BRF;
        }

    }

    //
    // numbers
    //
    // def: start with [0-9], follow by [0-9.]
    // number currently turns into a int in the VM
    if (isdigit(currentChar)) {

        std::string numberStr = "";
        numberStr += currentChar;
        currentChar = assemblyStr[assemblyPos++];
        while (isdigit(currentChar) || currentChar == '.') {
            numberStr += currentChar;
            currentChar = assemblyStr[assemblyPos++];
        }

        --assemblyPos;

        this->instructions.push_back(std::stoi(numberStr));
        return INSTR::NUMBER;
    }

    //
    // %LABELS - they indicate data addresses
    // add them to a map and insert their memory address here)
    //
    if (currentChar == '%') {

        // starting a new token ...
        std::string tokenString;

        // starting from the next character so we lose the LOCATION PREFIX
        currentChar = assemblyStr[assemblyPos++];

        // scan forward letters and underscore
        while (isalnum(currentChar) || currentChar == '_') {
            tokenString += currentChar;
            currentChar = assemblyStr[assemblyPos++];
        }
        --assemblyPos;

//        std::cout << "asm got "<< VARIABLE << " label\t\t" << tokenString << std::endl;

        std::pair<std::map<std::string,int>::iterator,bool> ret;

        ret = data.insert(std::make_pair(tokenString, data.size()));
        if ( ret.second ) {
//            std::cout << "element " << tokenString << " inserted at address " << ret.first->second << '\n';
        } else  {
//            std::cout << "element " << tokenString << " already existed at address " << ret.first->second << '\n';
        }
        this->instructions.push_back(ret.first->second);

        return INSTR::LABEL;
    }

    //
    // :LABELS (they indicate jump destinations, no instructions emitted,
    //          instead add these addresses to a map with the label string)
    //
    if (currentChar == ':') {

        // starting a new token ...
        std::string tokenString;

        // starting from the next character so we lose the LOCATION PREFIX
        currentChar = assemblyStr[assemblyPos++];

        // scan forward letters and underscore
        while (isalnum(currentChar) || currentChar == '_') {
            tokenString += currentChar;
            currentChar = assemblyStr[assemblyPos++];
        }
        --assemblyPos;

//        std::cout << "asm got : label\t\t" << tokenString << std::endl;

        labels.insert(std::make_pair(tokenString, this->instructions.size()));
        return INSTR::LABEL;
    }

    //
    // @LABELS addresses to be jumped to, emit a NOP (or NaN) for now and patch them up later
    //
    if (currentChar == '@') {

        // starting a new token ... probably an instruction address
        std::string tokenString;

        // starting from the next character so we lose the DESTINATION PREFIX
        currentChar = assemblyStr[assemblyPos++];

        // scan forward letters, numbers and underscores only
        while (isalnum(currentChar) || currentChar == '_') {
            tokenString += currentChar;
            currentChar = assemblyStr[assemblyPos++];
        }
        --assemblyPos;

        // add it to a map indexed on the string
//        std::cout << "asm got @ label\t\t" << tokenString << "\n";

        // reference to a location in the instructions
        jumps.insert(std::make_pair(this->instructions.size(), tokenString));
        this->instructions.push_back((int) -999999);
        return INSTR::LABEL;
    }

    //
    // other symbols...
    //
    if (currentChar == '\0') {
        instructions.push_back((int) INSTR::END_OF_FILE);
        return INSTR::END_OF_FILE;
    }
}