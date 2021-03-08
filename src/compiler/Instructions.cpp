
char* instructionNames[] = {
        "NOP",
        "HALT",
        "YIELD",
        "PUSH",
        "POP",

        "SAVE",
        "LOAD",

        "JMP",
        "BRT",
        "BRF",
        "RET",

        "ADD",
        "SUB",
        "MUL",
        "DIV",
        "MOD",
        "POW",

        "EQU",
        "NE",
        "GT",
        "GTE",
        "LT",
        "LTE",

        "AND",
        "OR",
        "NOT",
        "XOR",
        "NAND",

        "INPUT",
        "OUTPUT",

        "ASETPOS",      // this one is a special hack while we work it out
        "ASETVEL",      // this one is a special hack while we work it out
        "ASETCOL",      // this one is a special hack while we work it out ( TODO - make them an AFUNC or similar )
        "ASETSPRITE",

        "AGETINPUT",

        "SPAWN",

        "AGET",
        "STRING",

        "TOK_ERROR",
        "END_OF_FILE",
        "MAX"
};