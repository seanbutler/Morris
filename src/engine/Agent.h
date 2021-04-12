//
// Created by sean on 10/02/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include "../runtime/VirtualMachine.h"

// ----------------------------------------------------------------------

#include "Textures.h"
#include "Font.h"
#include "Input.h"
#include "Collision.h"

// ----------------------------------------------------------------------

extern Engine::Textures textures;
//extern Engine::Fonts font_manager;

// ----------------------------------------------------------------------
namespace Engine {

    class Scheduler;

    class Agent {

    public:
        Agent( Scheduler & S,
               CollisionManager & CM,
               std::string & F,
              std::pair<unsigned int, unsigned int> POS = {0,0},
              std::pair<unsigned int, unsigned int> VEL = {0,0},
              unsigned int collisionLayer = 0);

        enum State {
            ALIVE, CORPSE
        };

        bool IsAlive();
        virtual void Update(float deltaTime);
        virtual void Render(sf::RenderWindow *W);
        void SetPosition(float X = 1.0, float Y = 1.0, unsigned int index = 0);
        void SetVelocity(float X = 1.0, float Y = 1.0);
        void SetSprite(unsigned int N);
        void SetText(std::string message, unsigned int SZ = 32, sf::Color COL = sf::Color::White);

        sf::Sprite* GetSprite();
        unsigned long int GetInput(unsigned int B);
        void SetCollisionLayer(unsigned int B);
        bool CheckCollided(unsigned int B);
        void SetColour(unsigned char R, unsigned char G, unsigned char B, unsigned char A=3);

//        void SetAlienVar(std::string index, unsigned int value);
//        unsigned int GetAlienVar(std::string index);
//        void ClearAlienVars();
//        sf::Rect<float> GetGlobalBounds();

        void Spawn(std::string FN, unsigned int x, unsigned int y);
        void Die();

    public:
        State                                   state;

    protected:
        Runtime::VM                             virtualMachine;
        sf::Sprite                              sprite;
        Engine::Collider*                       collider;
//        sf::Text                                text;
        std::pair<unsigned int, unsigned int>   position;
        std::pair<unsigned int, unsigned int>   velocity;

    public:
//        unsigned int                layer;
//        std::vector<unsigned int>   collidedWithThisFrame;

    private:
        std::map<std::string, unsigned int> alienVarTable;
        Scheduler & scheduler;
        CollisionManager & collisionManager;
    };
}

// ----------------------------------------------------------------------
