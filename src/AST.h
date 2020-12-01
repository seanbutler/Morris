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

// ----------------------------------------------------------------------

static unsigned int gid = 0;

class ASTNode {

public:
    ASTNode()
    {
        id = gid++;
        tag = boost::uuids::random_generator()();
        type = "notype";
        value = "novalue";
        std::cout << tag << " --- " << value << std::endl;
    }

    virtual ~ASTNode(){}

    std::string Stringify()
    {
        return (std::string) "node" + std::to_string(id) + " ["
            + " uuid = \"" + boost::lexical_cast<std::string>(tag) + "\""
                + " label = \"" + type + " " + value + "\""
            + " ];\n"
            ;
    }

    void Diagram(std::ofstream & outStream)
    {
        if ( outStream )
        {
            outStream << "node" << std::to_string(id) << " ["
                      << " uuid = \"" << boost::lexical_cast<std::string>(tag) << "\""
                      << " label = \"" << type << " " << value + "\""
                      << " ];"
                      << std::endl;

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
    std::vector<std::shared_ptr<ASTNode>>children;
    std::vector<std::string>symbols;
};

// ----------------------------------------------------------------------

