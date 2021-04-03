
#pragma once

#include <string>

// ----------------------------------------------------------------------

enum TokenTypeEnum : int {
    TT_KEYWORD,
    TT_SYMBOL,
    TT_OPERAND
};

enum TokenEnum : int {
    KWD_DECL,
    KWD_CONST,
//    KWD_MUTABLE,

    KWD_IF,
    KWD_ELSE,

    KWD_WHILE,

    KWD_FUNC,
    KWD_PROC,
    KWD_THREAD,
    KWD_RETURN,
    KWD_EXIT,

    SYM_ASSIGN,
    SYM_LBRACES,
    SYM_RBRACES,
    SYM_LPAREN,
    SYM_RPAREN,
    SYM_LBRACKET,
    SYM_RBRACKET,
    SYM_COLON,
    SYM_SEMICOLON,
    SYM_HASH,
    SYM_COMMA,
    SYM_QUOTES,

    OP_GT,
    OP_GTE,
    OP_LT,
    OP_LTE,
    OP_EQ,
    OP_NE,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_POW,

    OP_AND,
    OP_OR,
//    OP_NOT,

    TOK_NUMBER,
    TOK_IDENTIFIER,
    TOK_STRING,

    KWD_OUTPUT,

    KWD_SETPOS,
    KWD_SETVEL,
    KWD_SETCOL,
    KWD_SETSPRITE,
    KWD_SETTEXT,

    KWD_GETINPUT,
    KWD_GETCOLLISION,
    KWD_SETATLAS,

    KWD_SPAWNAT,
    KWD_SPAWN,
    KWD_SETALIEN,

    TOK_END_OF_FILE = 666,
    TOK_ERROR = 667
};

// ----------------------------------------------------------------------

class Token {

public:
    Token(TokenEnum K,
          std::string N,
          std::string C = "no comment",
          unsigned int L = 0,
          std::string F = "source filename")
    : kind(K)
    , name(N)
    , line(L)
    , file(F)
    , comment(C)
    {
    }

    Token (const Token &obj)
    : kind(obj.kind)
    , name(obj.name)
    , line(obj.line)
    , file(obj.file)
    , comment(obj.comment)
    {
    }

    TokenEnum         kind;
    std::string       name;
    std::string       comment;

    unsigned int      line;
    std::string       file;
};

// ----------------------------------------------------------------------

