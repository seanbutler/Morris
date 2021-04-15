//
// Created by sean on 24/09/2020.
//

#include "Tokens.h"


Token tokens[] = {

        Token(KWD_DECL,     "decl"      ),

        Token(KWD_IF,       "if"        ),
        Token(KWD_ELSE,     "else"      ),  // todo
        Token(KWD_WHILE,    "while"     ),

        Token(KWD_FUNC,     "func"      ),  // todo
        Token(KWD_RETURN,   "return"    ),  // todo
        Token(KWD_PROC,     "proc"      ),  // todo
        Token(KWD_THREAD,   "thread"    ),  // todo - remove
        Token(KWD_PROC,     "exit"      ),  // todo - remove
        Token(KWD_OUTPUT,   "output"    ),  // todo - remove

        Token(KWD_SETPOS ,      "setpos"            ),
        Token(KWD_SETVEL ,      "setvel"            ),
        Token(KWD_SETCOL ,      "setcol"            ),
        Token(KWD_SETSPRITE,    "setsprite"         ),
        Token(KWD_SETTEXT,      "settext"           ),

        Token(KWD_GETINPUT,     "getinput"          ),
        Token(KWD_SETCOLLISION, "setcollision"      ),
        Token(KWD_GETCOLLISION, "getcollision"      ),

        Token(KWD_SPAWN ,       "spawn"             ),
        Token(KWD_SPAWNAT,      "spawnat"           ),

        Token(KWD_SETALIEN,     "setalien"          ),

        Token(KWD_TRANSMIT, "transmit"  ),
        Token(KWD_RECEIVE, "receive"    ),

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

        Token(OP_AND,       "and"       ),
        Token(OP_OR,        "or"        ),
        Token(OP_NE,        "!="        )
};