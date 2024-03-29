//
// Created by sean on 04/01/2021.
//

#ifndef MORRIS_INSTRUCTIONS_H
#define MORRIS_INSTRUCTIONS_H

extern std::string instructionNames[];

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
    POW,

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

    ASETPOS,
    ASETVEL,
    ASETCOL,
    ASETSPRITE,
    ASETTEXT,
    ASETVAR,

    AGETINPUT,
    ASETCOLLISION,
    AGETCOLLISION,

    SPAWNAT,
    SPAWN,

    TRANSMIT,
    RECEIVE,

    AGET,
    STRING,

    ERROR,
    END_OF_FILE,
    MAX
};


#endif //MORRIS_INSTRUCTIONS_H
