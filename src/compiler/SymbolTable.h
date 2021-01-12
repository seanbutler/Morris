//
// Created by sean on 02/12/2020.
//

#ifndef MORRIS_SYMBOLTABLE_H
#define MORRIS_SYMBOLTABLE_H

#include <iostream>

#include <tuple>
#include <string>
#include <vector>

#include <string>
#include <strstream>
#include <iostream>
#include <fstream>

// ------------------------------------------------------------

static unsigned int STGID;

class SymbolTable {

public:
    SymbolTable(){id = STGID++;}
    virtual ~SymbolTable(){}

    enum BaseTypes {
        procedure,
        function,
        integer
    };

    const std::string BaseTypeStrs[3] = {
            "procedure",
            "function",
            "integer"
    };

    enum Scope {
        global,
        local,
        param
    };

    const std::string ScopeStrs[3] = {
            "global",
            "local",
            "param"
    };

    void Insert(std::string K,
                BaseTypes T = integer,
                Scope S = local) {
        theTable.emplace_back(std::make_tuple(K, T, S));
    }

    int Pos(std::string K) {

        int pos = 0;

        for ( auto E : theTable) {
            if (std::get<0>(E)==K)
                return pos;

            pos++;
        }

        return -1;
    }

    std::tuple<std::string, BaseTypes, Scope> Get(unsigned int pos) {
        return theTable[pos];
    }

    unsigned int Size() {
        return theTable.size();
    }

    void Dump() {
        for (auto const &foo : theTable) {
            std::cout << "ST: ";
            std::cout << std::get<0>(foo) << " " << BaseTypeStrs[std::get<1>(foo)] << " " << ScopeStrs[std::get<2>(foo)] << std::endl;
        }
    }

    void Diagram(std::ofstream & outStream) {

        if (theTable.size() )
        {
            outStream << "|";

            for (auto const &foo : theTable) {
                std::cout << std::get<0>(foo) << " " << BaseTypeStrs[std::get<1>(foo)] << " " << ScopeStrs[std::get<2>(foo)] << std::endl;
            }
        }
    }

    unsigned int id;
    std::vector<std::tuple<std::string, BaseTypes, Scope>> theTable;
};

// ------------------------------------------------------------

#endif //MORRIS_SYMBOLTABLE_H
