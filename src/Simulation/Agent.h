//
// Created by sean on 10/02/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include "../Compiler/compiler.cpp"
#include "../runtime/VirtualMachine.h"
#include "../engine/Entity.h"

// ----------------------------------------------------------------------

class Agent : public Engine::Entity {
public:
    Agent(std::string F)
    :   Entity()
    ,   virtualMachine(Runtime::VM(Compiler::compile(F)))
    {

    }

    virtual void Update(float deltaTime) {
        virtualMachine.Execute(16);
    }

    virtual void Render(sf::RenderWindow *W) {
    }

protected:
    Runtime::VM virtualMachine;
};

// ----------------------------------------------------------------------
