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
    ,   size(1.0, 1.0)
    ,   position(8.0, 8.0)
    ,   virtualMachine(Runtime::VM(Compiler::compile(F)))
    {
        rectangle.setSize(size);
        rectangle.setFillColor(sf::Color::Black);
        rectangle.setPosition(position);
    }

    virtual void Update(float deltaTime) {
        virtualMachine.Execute(64);
    }

    virtual void Render(sf::RenderWindow *W) {
        W->draw(rectangle);
    }

    void SetPosition(float X = 1.0, float Y = 1.0)  { rectangle.setPosition(sf::Vector2f(X, Y)); }
    void SetSize(float X = 1.0, float Y = 1.0)      { rectangle.setSize(sf::Vector2f(X, Y)); }

    void SetColour(float R = 128, float G = 128, float B = 128, float A=255)  {
        rectangle.setFillColor(sf::Color(R, G, B, A));
    }


protected:
    Runtime::VM virtualMachine;
    sf::RectangleShape rectangle;
    sf::Vector2f size;
    sf::Vector2f position;
};

// ----------------------------------------------------------------------
