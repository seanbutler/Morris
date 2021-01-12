//
// Created by sean on 04/01/2021.
//

#ifndef MORRIS_INSTRUCTIONS_H
#define MORRIS_INSTRUCTIONS_H

extern char* instructionNames[];

enum INSTR {
    NOP = 0,
    HALT,
    YIELD,
    PUSH,
    POP,

    SAVE,
    LOAD,

    JMP,
    BRT,
    BRF,
    RET,

    ADD,
    SUB,
    MUL,
    DIV,
    MOD,

    EQU,
    NE,
    GT,
    GTE,
    LT,
    LTE,

    AND,
    OR,
    NOT,
    XOR,
    NAND,

    INPUT,
    OUTPUT,

    NUMBER,
    LABEL,

    ERROR,
    END_OF_FILE
};


#endif //MORRIS_INSTRUCTIONS_H
