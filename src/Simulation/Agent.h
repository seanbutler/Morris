//
// Created by sean on 10/02/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include "../Compiler/compiler.cpp"
#include "../runtime/VirtualMachine.h"
#include "../engine/Entity.h"
#include "../engine/Scheduler.h"

#include "XForm.h"

// ----------------------------------------------------------------------

class Agent : public Engine::Entity {

public:
    Agent(std::string F)
    :   virtualMachine(Runtime::VM(Compiler::compile(F)))
    ,   size(1.0, 1.0)
    ,   position(1.0, 1.0)
    ,   slice(32)
    {
        sprite.setSize(size);
        SetColour(0, 0, 0);
        sprite.setPosition(position);
        virtualMachine.SetOwner(this);
    }

    virtual void Update(float deltaTime)                { virtualMachine.Execute(slice); }
    virtual void Render(sf::RenderWindow *W)            { W->draw(sprite); }
    virtual void Spawn(std::string FN = "dummy.src");

    //
    // TODO - move these into a separate library of sorts maybe
    //
    void SetPosition(float X = 1.0, float Y = 1.0)  { sprite.setPosition(sf::Vector2f(X, Y)); }
    void SetVelocity(float X = 1.0, float Y = 1.0)  { velocity = sf::Vector2f(X, Y); }

    void SetColour(unsigned char R, unsigned char G, unsigned char B, unsigned char A=3) {
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
    sf::Vector2f        velocity;

    unsigned int        slice;
};

// ----------------------------------------------------------------------
