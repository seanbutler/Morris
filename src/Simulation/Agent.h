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

        if ( ! sprites.empty() ) {
            position.first += velocity.first;
            position.second += velocity.second;

            sprites.back().setPosition( sf::Vector2f(position.first, position.second));
        }
    }


    virtual void Spawn(std::string FN = "dummy.src", unsigned int x=0, unsigned int y=0);

    virtual void Render(sf::RenderWindow *W) {
        for (auto S : sprites) {
            W->draw(S);
        }
    }

    void SetPosition(float X = 1.0, float Y = 1.0, unsigned int index = 0)
    {
        position.first = X;
        position.second = Y;

//        if ( ! sprites.empty() ) {
//            sprites.back().setPosition( sf::Vector2f(position.first, position.second));
//        }
    }

    void SetVelocity(float X = 1.0, float Y = 1.0)
    {
        velocity.first = X;
        velocity.second = Y;

//        if ( ! sprites.empty() ) {
//            sprites.back().setPosition( sf::Vector2f(position.first, position.second));
//        }
    }

//    void MovePosition(float X = 1.0, float Y = 1.0, unsigned int index = 0)
//    {
//        position.first += X;
//        position.second += Y;
//
//        if ( ! sprites.empty() ) {
//            sprites.back().setPosition( sf::Vector2f(position.first, position.second));
//        }
//    }

    void SetSprite(unsigned int N)
    {
        sf::Sprite tmpSprite;
        textures.SetSprite(N, tmpSprite);
        tmpSprite.setPosition(position.first, position.second);
        sprites.push_back(tmpSprite);
    }

    unsigned long int GetInput(unsigned int B) {
        return Engine::Input::GetButton(B);
    }

    void SetColour(unsigned char R, unsigned char G, unsigned char B, unsigned char A=3) {
        if ( ! sprites.empty() ) {
            R = (R * 85);
            G = (G * 85);
            B = (B * 85);
            A = (A * 85);
            sprites.back().setColor(sf::Color((R << 24) | (G << 16) | (B << 8) | A));
        }
    }

protected:
    Runtime::VM                             virtualMachine;
    std::pair<unsigned int, unsigned int>   velocity;
    std::pair<unsigned int, unsigned int>   position;
    std::vector<sf::Sprite>                 sprites;
};

// ----------------------------------------------------------------------
