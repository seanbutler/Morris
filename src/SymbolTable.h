//
// Created by sean on 02/12/2020.
//

#ifndef MORRIS_SYMBOLTABLE_H
#define MORRIS_SYMBOLTABLE_H

#include <iostream>

#include <tuple>
#include <string>
#include <map>

// ------------------------------------------------------------

class SymbolTable {

public:
    SymbolTable(){}
    ~SymbolTable(){}

    enum BaseTypesEnum {
        procedure,
        function,
        integer
    };

    enum ScopeEnum {
        local,
        param
    };

    void Insert(std::string K,
                BaseTypesEnum T = integer,
                ScopeEnum S = local) {
        theTable.emplace(K, std::make_pair(T, S));
    }

    std::pair<BaseTypesEnum, ScopeEnum> Find(std::string K) {
        return theTable[K];
    }


    void Dump(){
        for (auto const &foo : theTable)
            std::cout << foo.first << " " << foo.second.first << foo.second.second << std::endl;
    }

private:
    std::map<std::string, std::pair<BaseTypesEnum, ScopeEnum>> theTable;

};

// ------------------------------------------------------------

#endif //MORRIS_SYMBOLTABLE_H
