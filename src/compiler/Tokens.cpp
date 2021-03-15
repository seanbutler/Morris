//
// Created by sean on 24/09/2020.
//

#include "Tokens.h"


Token tokens[] = {

        Token(KWD_DECL,     "decl"      ),
        Token(KWD_CONST,    "const"     ),

        Token(KWD_IF,       "if"        ),
        Token(KWD_ELSE,     "else"      ),
        Token(KWD_WHILE,    "while"     ),

        Token(KWD_FUNC,     "func"      ),
        Token(KWD_RETURN,   "return"    ),
        Token(KWD_PROC,     "proc"      ),
        Token(KWD_THREAD,   "thread"    ),
        Token(KWD_PROC,     "exit"      ),
        Token(KWD_OUTPUT,   "output"    ),

        Token(KWD_SETPOS ,      "setpos"            ),
        Token(KWD_SETVEL ,      "setvel"            ),
        Token(KWD_SETCOL ,      "setcol"            ),
        Token(KWD_SETSPRITE ,   "setsprite"         ),

        Token(KWD_GETINPUT,   "getinput"            ),
        Token(KWD_SETATLAS,   "atlas"               ),

        Token(KWD_SPAWN ,   "spawn"    ),

};

Token symbols[] = {

        Token(SYM_LBRACES,      "{"     ),
        Token(SYM_LBRACKET,     "["     ),
        Token(SYM_LPAREN,       "("     ),

        Token(SYM_RBRACES,      "}"     ),
        Token(SYM_RBRACKET,     "]"     ),
        Token(SYM_RPAREN,       ")"     ),

        Token(SYM_SEMICOLON,    ";"     ),
        Token(SYM_HASH,         "#"     ),
        Token(SYM_COLON,        ":"     ),

        Token(SYM_ASSIGN,       "="    ),
        Token(SYM_QUOTES,       "\""    ),

        Token(OP_LT,        "<"         ),
        Token(OP_LTE,       "<="        ),
        Token(OP_GT,        ">"         ),
        Token(OP_GTE,       ">="        ),

        Token(OP_EQ,        "=="        ),

        Token(OP_ADD,        "+"     ),
        Token(OP_SUB,        "-"     ),
        Token(OP_MUL,        "*"     ),
        Token(OP_DIV,        "/"     ),
        Token(OP_MOD,        "%"     ),
        Token(OP_POW,        "^"     ),

        Token(OP_AND,       "and"     ),
        Token(OP_OR,        "or"     ),
        Token(OP_NE,       "!="     )
};