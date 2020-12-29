//
// Created by sean on 02/12/2020.
//

#ifndef MORRIS_SYMBOLTABLE_H
#define MORRIS_SYMBOLTABLE_H

#include <iostream>

#include <tuple>
#include <string>
#include <map>

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
        theTable.emplace(K, std::make_pair(T, S));
    }

    std::pair<BaseTypes, Scope> Find(std::string K) {
        return theTable[K];
    }


    void Dump() {
        for (auto const &foo : theTable) {
            std::cout << "ST: ";
            std::cout << foo.first << " " << BaseTypeStrs[foo.second.first] << " " << ScopeStrs[foo.second.second] << std::endl;
        }
    }

    void Diagram(std::ofstream & outStream) {

        if (theTable.size() )
        {
            outStream << "|";

            for (auto const &foo : theTable) {
                outStream << foo.first << " " << BaseTypeStrs[foo.second.first] << " " << ScopeStrs[foo.second.second] << std::endl;
            }

        }
    }

private:
    unsigned int id;
    std::map<std::string, std::pair<BaseTypes, Scope>> theTable;

};

// ------------------------------------------------------------

#endif //MORRIS_SYMBOLTABLE_H
