//
// Created by sean on 10/02/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include "../compiler/compiler.cpp"
#include "../runtime/VirtualMachine.h"

#include "Entity.h"
#include "Scheduler.h"
#include "Textures.h"
#include "Input.h"

// ----------------------------------------------------------------------

extern Engine::Textures textures;

// ----------------------------------------------------------------------

class Agent : public Engine::Entity {

public:

    Agent(Engine::Scheduler * S, std::string & F,
          std::pair<unsigned int, unsigned int> POS = {0,0},
          std::pair<unsigned int, unsigned int> VEL = {0,0} )
        :   Engine::Entity(S)
        ,   virtualMachine(Runtime::VM(Compiler::compile(F)))
        ,   position(POS)
        ,   velocity(VEL)
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

    virtual void Spawn(std::string FN, unsigned int x=0, unsigned int y=0);     // SHOULDNT THIS BE IN THE SCHEDULER?
    virtual void Render(sf::RenderWindow *W) { W->draw(sprite); }

    virtual void Die();

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
    }

    sf::Sprite* GetSprite()
    {
        return &sprite;
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

    void OnCollision(Agent* other)
    {
        std::cout << "Collision" << std::endl;
    }

protected:
    Runtime::VM                             virtualMachine;
    sf::Sprite                              sprite;
    std::pair<unsigned int, unsigned int>   position;
    std::pair<unsigned int, unsigned int>   velocity;
};

// ----------------------------------------------------------------------