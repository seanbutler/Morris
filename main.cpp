#include <iostream>

#include "src/compiler/Emitter.h"

#include "src/compiler/Tokenizer.h"
#include "src/compiler/AST.h"
#include "src/compiler/Parser.h"

#include <string>
#include <fstream>
#include <streambuf>

#include "src/compiler/SymbolTable.h"

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

    std::shared_ptr<ASTNode> ast;
    ast = std::make_shared<ASTNode>();
    ast->type = "Module";
    ast->value = "";

    parser.Parse(ast);

//    Emitter emitter;
//    emitter.SetInput(ast);
//    emitter.Start();
//    emitter.DataSection();
//    emitter.CodeSection();
//    emitter.TreeWalk();

//    emitter.Exit();

//    std::ofstream assemblyFile("test.asm");
//    emitter.WriteOut(assemblyFile);
//    assemblyFile.close();


    return 0;
}
