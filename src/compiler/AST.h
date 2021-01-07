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
    ASTNode(std::string T = "", std::string V = "")
    : id(ASTGID++)
    , type(T)
    , value(V)
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


//    void Accept(InstructionASTVisitor* generator) {
//        generator->Visit((ModuleASTNode*)this);
//    }

//    virtual void Accept(InstructionASTVisitor* generator) = 0;

    virtual void Accept(InstructionASTVisitor* generator) {};

    unsigned int id;
    std::string type;
    std::string value;
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
        generator->Visit((ModuleASTNode*)this);
    }

};

// ----------------------------------------------------------------------

class DeclarationASTNode : public ASTNode {
public:
    DeclarationASTNode()
    : ASTNode("KWD", "decl")
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((DeclarationASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class IdentifierListASTNode : public ASTNode {
public:
    IdentifierListASTNode()
        : ASTNode("IDL")
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((IdentifierListASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class WhileASTNode : public ASTNode {
public:
    WhileASTNode()
        : ASTNode("KWD", "while")
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((WhileASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class IfASTNode : public ASTNode {
public:
    IfASTNode()
        : ASTNode("KWD", "if")
    {
    }
    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((IfASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class BlockASTNode : public ASTNode {
public:
    BlockASTNode()
        : ASTNode("Block")
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((BlockASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class AssignmentASTNode : public ASTNode {
public:
    AssignmentASTNode()
        : ASTNode("ASGN", "=")
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((AssignmentASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class NumberASTNode : public ASTNode {
public:
    NumberASTNode(std::string V)
        : ASTNode("NUM", V)
    {
    }

    void Accept(InstructionASTVisitor* generator) {
        generator->Visit((NumberASTNode*)this);
    }
};

// ----------------------------------------------------------------------

class IdentifierASTNode : public ASTNode {
public:
    IdentifierASTNode(std::string V)
        : ASTNode("ID", V)
    {
    }
};

// ----------------------------------------------------------------------

class OperatorASTNode : public ASTNode {
public:
    OperatorASTNode(std::string V)
            : ASTNode("OP", V)
    {
    }
};

// ----------------------------------------------------------------------

class ReturnASTNode : public ASTNode {
public:
    ReturnASTNode()
        : ASTNode("RET")
    {
    }
};

// ----------------------------------------------------------------------

class FunctionASTNode : public ASTNode {
public:
    FunctionASTNode()
        : ASTNode("KWD", "func")
    {
    }
};

// ----------------------------------------------------------------------

class ProcedureASTNode : public ASTNode {
public:
    ProcedureASTNode()
        : ASTNode("KWD", "proc")
    {
    }
};

// ----------------------------------------------------------------------

