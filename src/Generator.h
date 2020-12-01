//
// Created by sean on 27/11/2020.
//

#ifndef MORRIS_GENERATOR_H
#define MORRIS_GENERATOR_H

#include <iostream>
#include <memory>

#include "./AST.h"

class Phase {

public:
    Phase(){}

    void SetInput(std::shared_ptr<ASTNode> A){
        ast = A;
    }

    std::shared_ptr<ASTNode> ast;
};




#endif //MORRIS_GENERATOR_H
