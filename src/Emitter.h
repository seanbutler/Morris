//
// Created by sean on 25/11/2020.
//

#ifndef MORRIS_EMITTER_H
#define MORRIS_EMITTER_H

#include "./AST.h"

#include <iostream>
#include <string>
#include <strstream>
#include <vector>
#include <iomanip>

enum InsEnum : int {
    IN_NOP,
    IN_MOVE,
    IN_PUSH,
    IN_POP,
    IN_LEA,

    IN_ADD,
    IN_SUB,
    IN_INC,
    IN_DEC,
    IN_IMUL,
    IN_IDIV,

    IN_AND,
    IN_OR,
    IN_XOR,
    IN_NOT,
    IN_NEG,
    IN_SHL,
    IN_SHR,

    IN_CMP,
    IN_JMP,
    IN_JE,
    IN_JNE,
    IN_JZ,
    IN_JG,
    IN_JGE,
    IN_JL,
    IN_JLE,

    IN_CALL,
    IN_RET,
    IN_SYSCALL,

    GLOBAL,
    SECTION
};

enum RegsEnum : int {
    EAX = 0,
    ECX,
    EBX,
    EDX,
    ESI,
    EDI,
    ESP,
    EBP
};

extern std::string regStr[8];

// ----------------------------------------------------------------------------

class Instruction {
public:
    Instruction(std::string L,
                std::string N,
                std::string P1 = "",
                std::string P2 = "",
                std::string P3 = "",
                std::string C = "")
    :   label(L)
    ,   name(N)
    ,   param1(P1)
    ,   param2(P2)
    ,   param3(P3)
    ,   comment(C)
    {

    }

    std::string     label;
    std::string     name;
    std::string     param1;
    std::string     param2;
    std::string     param3;
    std::string     comment;

    void Write(std::ofstream & OFST) {

        OFST << std::setw(8) << std::left << label
            << std::setw(8) << std::left << name
            << std::setw(8) << std::right << param1;

        if ( param2 != "")
            OFST << ", " << std::setw(8) << std::left << param2;
        else
            OFST << "\t\t";

        if ( param3 != "" )
            OFST << ", " << std::setw(8) << std::left << param3;
        else
            OFST << "\t\t";

        if ( comment != "" )
            OFST << "; " << std::left <<  comment;

        OFST << std::endl;
    }

};



class NASM_X86_64 {
public:

    static Instruction Push(unsigned int u32)     { return(Instruction( "", "push", std::to_string(u32))); }
    static Instruction Push(std::string label)    { return(Instruction( "", "push", "["+label+"]")); }
    static Instruction Push(RegsEnum reg)         { return(Instruction( "", "push", regStr[reg])); }

    static Instruction Pop(std::string label)     { return(Instruction( "", "pop", "["+label+"]")); }
    static Instruction Pop(RegsEnum reg)          { return(Instruction( "", "pop", regStr[reg])); }

    static Instruction Cmp(RegsEnum reg, std::string label)           { return(Instruction( "", "cmp", regStr[reg], "["+label+"]")); }
    static Instruction Cmp(RegsEnum reg1, RegsEnum reg2)              { return(Instruction( "", "cmp", regStr[reg1], regStr[reg2])); }
    static Instruction Cmp(RegsEnum reg1, int num)                    { return(Instruction( "", "cmp", regStr[reg1], std::to_string(num))); }
    static Instruction Cmp(std::string label1, std::string label2)    { return(Instruction( "", "cmp", "["+label2+"]","["+label2+"]")); }

    static Instruction Jmp(std::string label)     { return(Instruction( "", "jmp", "["+label+"]" )); }
    static Instruction JmpEq(std::string label)   { return(Instruction( "", "je", "["+label+"]")); }
    static Instruction JmpNeq(std::string label)  { return(Instruction( "", "jne", "["+label+"]")); }
    static Instruction JmpZ(std::string label)    { return(Instruction( "", "jz", "["+label+"]")); }
    static Instruction JmpG(std::string label)    { return(Instruction( "", "jg", "["+label+"]")); }
    static Instruction JmpGE(std::string label)   { return(Instruction( "", "jge", "["+label+"]")); }
    static Instruction JmpL(std::string label)    { return(Instruction( "", "jl", "["+label+"]")); }
    static Instruction JmpLE(std::string label)   { return(Instruction( "", "jle", "["+label+"]")); }

    static Instruction Add()      { return(Instruction( "", "add")); }
    static Instruction Subtract() { return(Instruction( "", "sub")); }
    static Instruction Multiply() { return(Instruction( "", "imul")); }
    static Instruction Divide()   { return(Instruction( "", "idiv")); }

    static Instruction Call(std::string label)    { return(Instruction( "", "call", "["+label+"]")); }
    static Instruction Ret()                      { return(Instruction( "", "ret")); }

    static Instruction Start(){ return(Instruction( "global", "_start", "", "", "", "entry point needed at least once per executable")); }
    static Instruction StartFunction() { return(Instruction( "_start:", "")); }
    static Instruction DataSection(){ return(Instruction( "section", ".data")); }
    static Instruction CodeSection() { return (Instruction("section", ".text")); }

    // ----------

//    void Exit(){
//        instructions.push_back(Instruction("", "mov", "rax",  "60",   "", "system call for exit"));
//        instructions.push_back(Instruction("", "xor", "rdi",  "rdi",  "", "exit code 0"));
//        instructions.push_back(Instruction("", "syscall",  "",    "",  "", "invoke operating system to exit"));
//    }
//
//    void ToConsole(std::string addrlab, unsigned int len){
//        instructions.push_back(Instruction( "", "mov", regStr[RegsEnum::EAX], 0, "", "to stdout"));
//        instructions.push_back(Instruction( "", "mov", regStr[RegsEnum::EBX], 0, "", "to stdout"));
//        instructions.push_back(Instruction( "", "mov", regStr[RegsEnum::ECX], addrlab, "", "label"));
//        instructions.push_back(Instruction( "", "mov", regStr[RegsEnum::EDX], std::to_string(len), "", "length"));
//        instructions.push_back(Instruction( "", "syscall", "", "", "", "invoke operating system"));
//    }

};


// ----------------------------------------------------------------------------

class Emitter {
public:
    Emitter(){
    }

    void SetInput(std::shared_ptr<ASTNode> A){
        ast = A;
    }

    void Start(){
        instructions.push_back(NASM_X86_64::Start());
        instructions.push_back(NASM_X86_64::StartFunction());
    }

    void DataSection(){
        instructions.push_back(NASM_X86_64::DataSection());
    }

    void CodeSection(){
        instructions.push_back(NASM_X86_64::CodeSection());
    }

    //
    // THESE SHOULD BE ELSEWHERE, think about moving please
    //

    void Out(std::string addrlab, unsigned int len){
        instructions.push_back(Instruction( "", "mov", regStr[RegsEnum::EAX], 0, "", "to stdout"));
        instructions.push_back(Instruction( "", "mov", regStr[RegsEnum::EBX], 0, "", "to stdout"));
        instructions.push_back(Instruction( "", "mov", regStr[RegsEnum::ECX], addrlab, "", "label"));
        instructions.push_back(Instruction( "", "mov", regStr[RegsEnum::EDX], std::to_string(len), "", "length"));
        instructions.push_back(Instruction( "", "syscall", "", "", "", "invoke operating system"));
    }

    void Exit(){
        instructions.push_back(Instruction("", "mov", "rax",  "60",   "", "system call for exit"));
        instructions.push_back(Instruction("", "xor", "rdi",  "rdi",  "", "exit code 0"));
        instructions.push_back(Instruction("", "syscall",  "",    "",  "", "invoke operating system to exit"));
    }


    void WriteOut(std::ofstream & OST) {
        for (auto I : instructions){
            I.Write(OST);
        }
    }

    std::shared_ptr<ASTNode> ast;
    std::vector<Instruction> instructions;
};


// ----------------------------------------------------------------------------


#endif //MORRIS_EMITTER_H
