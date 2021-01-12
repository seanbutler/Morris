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
                    << " label = \"" << type << " " << value << std::endl;

            symbolTable.Diagram(outStream);

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

    bool IsValueLocal(std::string V) {
        if ( symbolTable.Pos(V) >= 0 )
            return true;
        else
            return false;
    }

    bool GetValuePosition(std::string V) {
        return symbolTable.Pos(V);
    }

    unsigned int id;
    std::string type;
    std::string value;
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
        : ASTNode("IDL", "", P)
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

class IdentifierASTNode : public ASTNode {
public:
    IdentifierASTNode(std::string V, ASTNode * P=nullptr)
        : ASTNode("ID", V, P)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((IdentifierASTNode*)this);
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

