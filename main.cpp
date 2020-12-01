#include <iostream>

#include "./src/Emitter.h"

#include "./src/Tokenizer.h"
#include "./src/AST.h"
#include "./src/Parser.h"

#include <string>
#include <fstream>
#include <streambuf>

int main(int argc, char**argv) {
    char filename[] = "test.src";

    std::ifstream t(filename);
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    Tokenizer tokenizer;
    tokenizer.SetInputString(str);
    tokenizer.SetFilename(filename);
    tokenizer.Scan();

    std::vector<Token> tokens = tokenizer.GetOutputTokens();

//    for(auto tok : tokens) {
//        std::cout << tok.file << "\t" << tok.line << "\t"
//                << (int)tok.kind  << "\t"
//                << tok.name << "\t"
//                << std::endl;
//    }

    Parser parser;
    parser.SetInput(tokens);

    std::shared_ptr<ASTNode> ast;
    ast = std::make_shared<ASTNode>();
    ast->type = "Module";
    ast->value = "";

    parser.Parse(ast);

    Emitter emitter;
    emitter.SetInput(ast);
    emitter.Start();
    emitter.DataSection();
    emitter.CodeSection();
    emitter.Exit();



    std::ofstream assemblyFile("test.asm");
    emitter.WriteOut(assemblyFile);
    assemblyFile.close();

    return 0;
}
