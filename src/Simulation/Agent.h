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

    virtual void Update(float deltaTime)                { virtualMachine.Execute(); }
    virtual void Spawn(std::string FN = "dummy.src");

    virtual void Render(sf::RenderWindow *W) {
        for (auto S : sprites) {
            W->draw(S);
        }
    }

    void SetPosition(float X = 1.0, float Y = 1.0, unsigned int index = 0)
    {
        sprites.back().setPosition( sf::Vector2f(X, Y));
    }

//    void SetSprite(unsigned int X, unsigned char Y, unsigned int index = 0)
//    {
//        sf::Sprite tmpSprite;
//        textures.SetSprite(X, Y, tmpSprite);
//        sprites.push_back(tmpSprite);
//    }

    void SetSprite(unsigned int N)
    {
        sf::Sprite tmpSprite;
        textures.SetSprite(N, tmpSprite);
        sprites.push_back(tmpSprite);
    }


    unsigned long int GetInput(unsigned int B) {
        return Engine::Input::GetButton(B);
    }

    void SetColour(unsigned char R, unsigned char G, unsigned char B, unsigned char A=3) {
        R = (R * 85);
        G = (G * 85);
        B = (B * 85);
        A = (A * 85);
        sprites.back().setColor(sf::Color((R<<24)|(G<<16)|(B<<8)|A));
    }

protected:
    Runtime::VM                         virtualMachine;
    std::vector<sf::Sprite>             sprites;
};

// ----------------------------------------------------------------------
