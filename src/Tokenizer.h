//
// Created by sean on 24/09/2020.
//

#pragma once

#include "./Tokens.h"

#include <vector>
#include <string>

class Tokenizer {

public:
    Tokenizer() = default;

    void SetInputString(const std::string S){
        inputString = S;
        currentPosition = 0;
    }

    void SetFilename(const std::string F){
        filename = F;
    }

    void Scan();
    bool ScanToken();

    std::vector<Token> GetOutputTokens() {
        return outputTokens;
    }

private:
    std::string inputString;
    unsigned int currentPosition = 0;
    unsigned int currentLine = 1;
    std::vector<Token> outputTokens;
    std::string filename;
};
