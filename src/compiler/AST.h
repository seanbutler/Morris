//
// Created by sean on 28/09/2020.
//

#pragma once

#include <vector>
#include <memory>

#include <string>
#include <strstream>
#include <iostream>
#include <fstream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

#include "SymbolTable.h"
#include "Location.h"
#include "InstructionASTVisitor.h"

// ----------------------------------------------------------------------

static unsigned int ASTGID = 0;

// ----------------------------------------------------------------------

class ASTNode {

public:
    ASTNode(std::string T = "", std::string V = "", ASTNode * P = nullptr)
    : id(ASTGID++)
    , type(T)
    , value(V)
    , parent(P)
    {
        tag = boost::uuids::random_generator()();
    }

    virtual ~ASTNode(){
        for(auto C : children){
            delete C;
        }
        children.clear();
    }

    void Diagram(std::ofstream & outStream)
    {
        if ( outStream )
        {
            outStream << "node" << std::to_string(id) << " ["
                    << " uuid = \"" << boost::lexical_cast<std::string>(tag) << "\""
                    << " shape = \"record\""
                    << " label = \"" << type << "\n ";

            if (value == ">")  { outStream << "\\>"; }
            else if (value == "<")  { outStream << "\\<"; }
            else if (value == ">=") { outStream << "\\>="; }
            else if (value == "<=") { outStream << "\\<="; }
            else { outStream << value; }

            outStream << "\"" << " ];" << std::endl;

            for(auto N : children) {
                if (N != nullptr) {
                    N->Diagram(outStream);
                    outStream << "node" << this->id << " -> " << "node" << N->id << ";" << std::endl;
                }
            }
        }
    }

    virtual void Accept(InstructionASTVisitor* generator) {};

    unsigned int id;
    std::string type;
    std::string value;
//    std::string context;
    ASTNode * parent;

    boost::uuids::uuid tag;

    std::vector<ASTNode*>children;
    SymbolTable symbolTable;
};

// ----------------------------------------------------------------------

class ModuleASTNode : public ASTNode {
public:
    ModuleASTNode()
    : ASTNode("MDL")
    {
    }

    virtual ~ModuleASTNode(){
    }


    void Accept(InstructionASTVisitor* generator) {
        // NOW GENERATE CODE FOR ALL THE STATEMENTS
        generator->Visit((ModuleASTNode*)this);
    }

};

// ----------------------------------------------------------------------

class DeclarationASTNode : public ASTNode {
public:
    DeclarationASTNode(ASTNode * P=nullptr)
    : ASTNode("KWD", "decl", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((DeclarationASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class IdentifierListASTNode : public ASTNode {
public:
    IdentifierListASTNode(ASTNode * P=nullptr)
        : ASTNode("ID-LIST", "", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((IdentifierListASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class WhileASTNode : public ASTNode {
public:
    WhileASTNode(ASTNode * P=nullptr)
        : ASTNode("KWD", "while", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((WhileASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class IfASTNode : public ASTNode {
public:
    IfASTNode(ASTNode * P=nullptr)
        : ASTNode("KWD", "if", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((IfASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class BlockASTNode : public ASTNode {
public:
    BlockASTNode(ASTNode * P=nullptr)
        : ASTNode("Block", "", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((BlockASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class AssignmentASTNode : public ASTNode {
public:
    AssignmentASTNode(ASTNode * P=nullptr)
        : ASTNode("ASGN", "=", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((AssignmentASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class ExpressionASTNode : public ASTNode {
public:
    ExpressionASTNode(ASTNode * P=nullptr)
            : ASTNode("EXPR", "=", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((ExpressionASTNode*)this);
    }
};


// ----------------------------------------------------------------------

class NumberASTNode : public ASTNode {
public:
    NumberASTNode(std::string V, ASTNode * P=nullptr)
        : ASTNode("NUM", V, P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((NumberASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class RHSIdentifierASTNode : public ASTNode {
public:
    RHSIdentifierASTNode(std::string V, ASTNode * P=nullptr)
        : ASTNode("ID-RHS", V, P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((RHSIdentifierASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class LHSIdentifierASTNode : public ASTNode {
public:
    LHSIdentifierASTNode(std::string V, ASTNode * P=nullptr)
            : ASTNode("ID-LHS", V, P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((LHSIdentifierASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class OperatorASTNode : public ASTNode {
public:
    OperatorASTNode(std::string V, ASTNode * P=nullptr)
        : ASTNode("OP", V, P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((OperatorASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class ReturnASTNode : public ASTNode {
public:
    ReturnASTNode(ASTNode * P=nullptr)
        : ASTNode("RET", "", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((ReturnASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class OutputASTNode : public ASTNode {
public:
    OutputASTNode(ASTNode * P=nullptr)
        : ASTNode("KWD", "output", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((OutputASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class FunctionASTNode : public ASTNode {
public:
    FunctionASTNode(ASTNode * P=nullptr)
        : ASTNode("KWD", "func", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((FunctionASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class ProcedureASTNode : public ASTNode {
public:
    ProcedureASTNode(ASTNode * P=nullptr)
        : ASTNode("KWD", "proc", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((ProcedureASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class SetposASTNode : public ASTNode {
public:
    SetposASTNode(ASTNode * P=nullptr)
            : ASTNode("KWD", "setpos", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((SetposASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class SetvelASTNode : public ASTNode {
public:
    SetvelASTNode(ASTNode * P=nullptr)
            : ASTNode("KWD", "setvel", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((SetvelASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class SetcolASTNode : public ASTNode {
public:
    SetcolASTNode(ASTNode * P=nullptr)
            : ASTNode("KWD", "setcol", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((SetcolASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class SetspriteASTNode : public ASTNode {
public:
    SetspriteASTNode(ASTNode * P=nullptr)
            : ASTNode("KWD", "setsprite", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((SetspriteASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class GetInputASTNode : public ASTNode {
public:
    GetInputASTNode(ASTNode * P=nullptr)
            : ASTNode("KWD", "getinput", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((GetInputASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class StringASTNode : public ASTNode {
public:
    StringASTNode(std::string V, ASTNode * P=nullptr)
            : ASTNode("STR", V, P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((StringASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class SpawnASTNode : public ASTNode {
public:
    SpawnASTNode(ASTNode * P = nullptr)
            : ASTNode("KWD", "spawn", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((SpawnASTNode*)this);
    }
};

class SpawnAtASTNode : public ASTNode {
public:
    SpawnAtASTNode(ASTNode * P = nullptr)
            : ASTNode("KWD", "spawnat", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((SpawnAtASTNode*)this);
    }
};



// ----------------------------------------------------------------------

class SetTextASTNode : public ASTNode {
public:
    SetTextASTNode(ASTNode * P = nullptr)
            : ASTNode("KWD", "settext", P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((SetTextASTNode*)this);
    }
};


// ----------------------------------------------------------------------

