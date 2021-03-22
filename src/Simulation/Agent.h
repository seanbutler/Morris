//
// Created by sean on 10/02/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include "../compiler/compiler.cpp"
#include "../runtime/VirtualMachine.h"
#include "../engine/Entity.h"
#include "../engine/Scheduler.h"
#include "../engine/Textures.h"
#include "../engine/Input.h"

#include "XForm.h"

// ----------------------------------------------------------------------

extern Engine::Textures textures;

// ----------------------------------------------------------------------

class Agent : public Engine::Entity {

public:
    Agent(std::string F)
    :   virtualMachine(Runtime::VM(Compiler::compile(F)))
    {
        virtualMachine.SetOwner(this);
    }

    virtual void Update(float deltaTime)
    {
        virtualMachine.Execute();

        position.first += velocity.first;
        position.second += velocity.second;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
    }

    virtual void Spawn(std::string FN = "dummy.src", unsigned int x=0, unsigned int y=0);

    virtual void Render(sf::RenderWindow *W) {
        W->draw(sprite);
    }

    void SetPosition(float X = 1.0, float Y = 1.0, unsigned int index = 0)
    {
        position.first = X;
        position.second = Y;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
    }

    void SetVelocity(float X = 1.0, float Y = 1.0)
    {
        velocity.first = X;
        velocity.second = Y;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
    }

    void SetSprite(unsigned int N)
    {
        sf::Sprite tmpSprite;
        textures.SetSprite(N, tmpSprite);
        tmpSprite.setPosition(position.first, position.second);
        sprite = tmpSprite;

//        std::cout << "Sprite Bounds (" << sprite.getGlobalBounds().top
//                << ", " << sprite.getGlobalBounds().left
//                << ", " << sprite.getGlobalBounds().height
//                << ", " << sprite.getGlobalBounds().width
//                << ")" << std::endl;

    }

    unsigned long int GetInput(unsigned int B) {
        return Engine::Input::GetButton(B);
    }

    void SetColour(unsigned char R, unsigned char G, unsigned char B, unsigned char A=3) {
        R = (R * 85);
        G = (G * 85);
        B = (B * 85);
        A = (A * 85);
        sprite.setColor(sf::Color((R << 24) | (G << 16) | (B << 8) | A));
    }

protected:
    Runtime::VM                             virtualMachine;

    std::pair<unsigned int, unsigned int>   velocity;
    std::pair<unsigned int, unsigned int>   position;
    sf::Sprite                              sprite;
};

// ----------------------------------------------------------------------
