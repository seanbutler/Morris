#include <iostream>

#include <string>
#include <fstream>
#include <streambuf>

#include "src/compiler/Tokenizer.h"
#include "src/compiler/AST.h"
#include "src/compiler/Parser.h"
#include "src/compiler/InstructionASTVisitor.h"

#include "src/compiler/SymbolTable.h"
#include "src/compiler/Runtime.h"
#include "src/compiler/Location.h"

// ---------------------------------------------------------------------------

int main(int argc, char**argv) {

    char filename[] = "test.src";

    std::ifstream t(filename);
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    Tokenizer tokenizer;
    tokenizer.SetInputString(str);
    tokenizer.SetFilename(filename);
    tokenizer.Scan();

    std::vector<Token> tokens = tokenizer.GetOutputTokens();

    Parser parser;
    parser.SetInput(tokens);
    ModuleASTNode * ast = parser.ParseModule();

    std::ofstream diagramFile("test.gv");
    diagramFile << "digraph G {" <<  std::endl;
    diagramFile << "node [shape = circle];" << std::endl;
    ast->Diagram(diagramFile);
    diagramFile << "}" << std::endl;
    diagramFile.close();

    parser.symbolTable.Dump();

    InstructionASTVisitor generator;
    generator.Visit(ast);
    for(auto L : generator.instructions){
        std::cout << L << std::endl;
    }

    return 0;
}

// ---------------------------------------------------------------------------
