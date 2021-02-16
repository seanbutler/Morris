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
    ,   position(1.0, 1.0)
    ,   virtualMachine(Runtime::VM(Compiler::compile(F)))
    {
        sprite.setSize(size);
        SetColour(3, 0, 0);
        sprite.setPosition(position);
        virtualMachine.owner = this;
    }

    virtual void Update(float deltaTime) { virtualMachine.Execute(32); }
    virtual void Render(sf::RenderWindow *W) { W->draw(sprite); }

    void SetPosition(float X = 1.0, float Y = 1.0)  { sprite.setPosition(sf::Vector2f(X, Y)); }

    void SetSize(float X = 1.0, float Y = 1.0)      { sprite.setSize(sf::Vector2f(X, Y));        }
    void Move(float X = 1.0, float Y = 1.0)         { sprite.move(sf::Vector2f(X, Y));          }
    void MoveX(float X = 1.0)                       { sprite.move(sf::Vector2f(X, 0.0));      }
    void MoveY(float Y = 1.0)                       { sprite.move(sf::Vector2f(0.0, Y));      }

    void SetColour(unsigned char R,
                   unsigned char G,
                   unsigned char B,
                   unsigned char A=3) {

        R = (R * 85);
        G = (G * 85);
        B = (B * 85);
        A = (A * 85);
        sprite.setFillColor(sf::Color((R<<24)|(G<<16)|(B<<8)|A));
    }


protected:
    Runtime::VM         virtualMachine;
    sf::RectangleShape  sprite;
    sf::Vector2f        size;
    sf::Vector2f        position;
};

// ----------------------------------------------------------------------
