//
// Created by sean on 10/02/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include "../Compiler/compiler.cpp"
#include "../runtime/VirtualMachine.h"
#include "../engine/Entity.h"

#include "XForm.h"

// ----------------------------------------------------------------------

class Agent : public Engine::Entity {
public:
    Agent(std::string F)
    :   Entity()
    ,   size(1.0, 1.0)
    ,   position(8.0, 8.0)
    ,   virtualMachine(Runtime::VM(Compiler::compile(F)))
    {
        sprite.setSize(size);
        sprite.setFillColor(sf::Color::Black);
        sprite.setPosition(position);
    }

    virtual void Update(float deltaTime) {
        virtualMachine.Execute(32);
    }

    virtual void Render(sf::RenderWindow *W) {
        W->draw(sprite);
    }

    void SetPosition(float X = 1.0, float Y = 1.0)  { sprite.setPosition(sf::Vector2f(X, Y)); }
    void SetSize(float X = 1.0, float Y = 1.0)      { sprite.setSize(sf::Vector2f(X, Y));    }
    void Move(float X = 1.0, float Y = 1.0)         { sprite.move(sf::Vector2f(X, Y));     }
    void MoveX(float X = 1.0)                       { sprite.move(sf::Vector2f(X, 0.0)); }
    void MoveY(float Y = 1.0)                       { sprite.move(sf::Vector2f(0.0, Y)); }

    void SetColour(float R = 128, float G = 128, float B = 128, float A=255)  {
        sprite.setFillColor(sf::Color(R, G, B, A));
    }

protected:
    Runtime::VM         virtualMachine;
    sf::RectangleShape  sprite;
    sf::Vector2f        size;
    sf::Vector2f        position;
};

// ----------------------------------------------------------------------
