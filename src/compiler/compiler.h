//
// Created by sean on 29/01/2021.
//

#pragma once

//--------------------------------------------------------------------------------


#include <string>

//--------------------------------------------------------------------------------

#include "Tokenizer.h"
#include "Parser.h"
#include "Tokenizer.h"
#include "InstructionASTVisitor.h"

//--------------------------------------------------------------------------------

#include "FileCache.h"

static SimpleFileCache file_cache;


class Compiler {
public:
    static std::pair<std::vector<Location>, std::vector<std::string>> compile(std::string filename){

        // std::ifstream t(filename);
        // std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

        std::string str = file_cache.Get(filename);

        Tokenizer tokenizer;
        tokenizer.SetInputString(str);
        tokenizer.SetFilename(filename);
        tokenizer.Scan();

        // t.close();

        std::vector<Token> tokens = tokenizer.GetOutputTokens();

        Parser parser;
        parser.SetInput(tokens);
        ModuleASTNode * ast = parser.ParseModule();

        // std::ofstream diagramFile(filename + ".gv");
        // diagramFile << "digraph G {" <<  std::endl;
        // diagramFile << "node [shape = circle];" << std::endl;
        // ast->Diagram(diagramFile);
        // diagramFile << "}" << std::endl;
        // diagramFile.close();

        InstructionASTVisitor generator;
        generator.Visit(ast);

    //    for(auto L : generator.instructions){
    //        std::cout << L << std::endl;
    //    }

        delete ast;

        return std::make_pair(generator.instructions, generator.strings);

    }
};


//--------------------------------------------------------------------------------
