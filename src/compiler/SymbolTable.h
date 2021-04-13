//
// Created by sean on 02/12/2020.
//

#pragma once

#include <iostream>

#include <tuple>
#include <string>
#include <vector>

#include <string>
//#include <strstream>
#include <iostream>
#include <fstream>

// ------------------------------------------------------------

class SymbolDescriptor {
// TODO maybe refactor to a separate class?
};

class SymbolTable {

public:
    SymbolTable() {}
    virtual ~SymbolTable() {}

    enum BaseTypes {
        procedure,
        function,
        number
    };

    const std::string BaseTypeStrs[3] = {
        "procedure",
        "function",
        "number"
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
                BaseTypes T = number,
                Scope S = local) {
        theTable.emplace_back(std::make_tuple(K, T, S));
    }

    std::tuple<std::string, BaseTypes, Scope> * Get(std::string ident) {

        for(auto I : theTable)
        {
            if ( std::get<0>(I) == ident ) {
                return &I;
            }

            std::cout << std::get<0>(I) << std::get<1>(I) << std::get<2>(I);
        }
        return nullptr;
    }

    int Find(std::string ident) {

        for(int i=0;i<theTable.size();i++)
        {
            if ( std::get<0>(theTable[i]) == ident ) {
                return i;
            }
        }
        return -1;
    }

    void Dump() {
        for (auto const &foo : theTable) {
            std::cout << "ST: " << std::get<0>(foo) << " "
                    << BaseTypeStrs[std::get<1>(foo)] << " "
                    << ScopeStrs[std::get<2>(foo)] << std::endl;
        }
    }

private:
    std::vector<std::tuple<std::string, BaseTypes, Scope>> theTable;
};

// ------------------------------------------------------------

class SymbolTableStack {

public:
    SymbolTableStack(){
        tableStack.emplace_back(SymbolTable());
    }

    ~SymbolTableStack(){
        tableStack.emplace_back(SymbolTable());
    }

    void Insert(std::string K,
                SymbolTable::BaseTypes T = SymbolTable::number,
                SymbolTable::Scope S = SymbolTable::local) {
        tableStack[tableStack.size()-1].Insert(K, T, S);
    }

    std::pair<int, int> Find(std::string K) {

        for(int i = tableStack.size() - 1; i >= 0; i--)
        {
            int j;
            if ( ( j = tableStack[i].Find(K) ) != -1 )
                return std::make_pair(i, j);
        }

        return std::make_pair(-1, -1);
    }

    std::tuple<std::string, SymbolTable::BaseTypes, SymbolTable::Scope> * Get(std::string K) {

        for(int i = tableStack.size() - 1; i >= 0; i--)
        {
            std::tuple<std::string, SymbolTable::BaseTypes, SymbolTable::Scope> * tmpPtr;
            tmpPtr = tableStack[i].Get(K);
            if ( tmpPtr != nullptr)
            {
                return tmpPtr;
            }
        }

        return nullptr;
    }

    void IncreaseNestLevel() {
        tableStack.emplace_back(SymbolTable());
    }

    void DecreaseNestLevel() {
        tableStack.pop_back();
    }

    void Dump() {
        for(auto T : tableStack) {
            T.Dump();
        }
    }

public:
    std::vector<SymbolTable>tableStack;
};

// ------------------------------------------------------------
