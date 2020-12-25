//
// Created by sean on 24/09/2020.
//

#include "Tokens.h"

Token tokens[] = {

        Token(KWD_DECL,     "decl"      ),
        Token(KWD_CONST,    "const"     ),
//        Token(KWD_MUTABLE,  "mut"       ),

        Token(KWD_IF,       "if"        ),
        Token(KWD_ELSE,     "else"      ),
        Token(KWD_WHILE,    "while"     ),

        Token(KWD_FUNC,     "func"      ),
        Token(KWD_RETURN,   "return"    ),
        Token(KWD_PROC,     "proc"      ),
        Token(KWD_THREAD,   "thread"    ),
        Token(KWD_PROC,     "exit"      )

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

        Token(OP_LT,        "<"         ),
        Token(OP_LTE,       "<="        ),
        Token(OP_GT,        ">"         ),
        Token(OP_GTE,       ">="        ),

        Token(OP_EQ,        "="        ),

        Token(OP_ADD,        "+"     ),
        Token(OP_SUB,        "-"     ),
        Token(OP_MUL,        "*"     ),
        Token(OP_DIV,        "/"     ),

        Token(OP_AND,       "and"     ),
        Token(OP_OR,        "or"     ),
        Token(OP_NE,       "!="     ),

//        Token(OP_MOD,        "%"     ),

};