//
// Created by sean on 02/12/2020.
//

#pragma once

#include <iostream>

#include <tuple>
#include <string>
#include <vector>

#include <string>
#include <strstream>
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
                SymbolTable::BaseTypes T = SymbolTable::integer,
                SymbolTable::Scope S = SymbolTable::local) {
        tableStack[tableStack.size()-1].Insert(K, T, S);
    }

    std::tuple<std::string, SymbolTable::BaseTypes, SymbolTable::Scope> * Find(std::string K) {

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
