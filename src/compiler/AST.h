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
        std::cout << tag << " --- " << value << std::endl;
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
    :ASTNode("Module")
    {

    }
};

