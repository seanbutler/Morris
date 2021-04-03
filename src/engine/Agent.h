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
#include "Font.h"
#include "Input.h"
#include "CollisionManager.h"

// ----------------------------------------------------------------------

extern Engine::Textures textures;
extern Engine::Fonts font_manager;

// ----------------------------------------------------------------------

class Agent : public Engine::Entity, public Engine::Collider{

public:
    Agent(Engine::Scheduler * S, std::string & F,
          std::pair<unsigned int, unsigned int> POS = {0,0},
          std::pair<unsigned int, unsigned int> VEL = {0,0} )
        :   Engine::Entity(S)
        ,   Engine::Collider(&sprite)
        ,   virtualMachine(Runtime::VM(Compiler::compile(F)))
        ,   position(POS)
        ,   velocity(VEL)
    {
        virtualMachine.SetOwner(this);
        Collider::SetLabel("Agent");
    }

    virtual void Update(float deltaTime)
    {
        virtualMachine.Execute();

        position.first += velocity.first;
        position.second += velocity.second;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
        text.setPosition( sf::Vector2f(position.first, position.second));
    }

    virtual void Spawn(std::string FN, unsigned int x=0, unsigned int y=0);     // SHOULDNT THIS BE IN THE SCHEDULER?
    virtual void Render(sf::RenderWindow *W) { W->draw(text); W->draw(sprite); }

    virtual void Die();

    void SetPosition(float X = 1.0, float Y = 1.0, unsigned int index = 0)
    {
        position.first = X;
        position.second = Y;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
        text.setPosition(sf::Vector2f(position.first, position.second));
    }

    void SetVelocity(float X = 1.0, float Y = 1.0)
    {
        velocity.first = X;
        velocity.second = Y;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
        text.setPosition(sf::Vector2f(position.first, position.second));
    }

    void SetSprite(unsigned int N)
    {
        sf::Sprite tmpSprite;
        textures.SetSprite(N, tmpSprite);
        tmpSprite.setPosition(position.first, position.second);
        sprite = tmpSprite;
        text.setPosition(sf::Vector2f(position.first, position.second));
    }

    void SetText(std::string message, unsigned int SZ = 32, sf::Color COL = sf::Color::White)
    {
        const_cast<sf::Texture&>(font_manager.font.getTexture(SZ)).setSmooth(false);

        text.setFont(font_manager.font);
        text.setString(message);
        text.setCharacterSize(SZ);
        text.setScale(1, 1);
        text.setPosition(sf::Vector2f(position.first, position.second));

        text.setFillColor(COL);
        text.setPosition(sf::Vector2f(position.first, position.second));
//        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
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

    void OnCollision(Collider* other)
    {
        std::cout << "OnCollision " << other->GetGlobalBounds().left
                << " " << other->GetGlobalBounds().top
                << " " << other->label << std::endl;
    }

public:
    void SetAlienVar(std::string index, unsigned int value)     { alienVarTable[index] = value; }
    unsigned int GetAlienVar(std::string index)                 { return alienVarTable[index];  }
    void ClearAlienVars()                                       { alienVarTable.clear();        }

private:
    std::map<std::string, unsigned int> alienVarTable;

protected:
    Runtime::VM                             virtualMachine;
    sf::Sprite                              sprite;
    sf::Text                                text;
    std::pair<unsigned int, unsigned int>   position;
    std::pair<unsigned int, unsigned int>   velocity;


};

// ----------------------------------------------------------------------
