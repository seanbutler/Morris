//
// Created by sean on 10/02/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include "../runtime/VirtualMachine.h"

// ----------------------------------------------------------------------

#include "../core/Object.h"

// ----------------------------------------------------------------------

#include "Textures.h"
#include "Font.h"
#include "Input.h"
#include "Collision.h"

// ----------------------------------------------------------------------
namespace Engine {

class Scheduler;    // i manage agents

class Agent : public Core::Object {

    public:
        Agent( Scheduler & S,
                std::string & F,
                std::pair<unsigned int, unsigned int> POS = {0,0},
                std::pair<unsigned int, unsigned int> VEL = {0,0},
                unsigned int collisionLayer = 0);

        virtual ~Agent() {
        }

        enum State {
            ALIVE, CORPSE
        };

        bool IsAlive();
        virtual void Update(float deltaTime);
        virtual void Render(sf::RenderWindow *W);

        void SetPosition(float X = 1.0, float Y = 1.0, unsigned int index = 0);
        void SetVelocity(float X = 1.0, float Y = 1.0);
        void SetSprite(unsigned int N);
        sf::Sprite* GetSprite();

        void SetText(std::string T);
        sf::Text* GetText();

        unsigned long int GetInput(unsigned int B);

        void SetCollisionLayer(unsigned int B);
        bool CheckCollided(unsigned int B);
        void SetColour(unsigned char R, unsigned char G, unsigned char B, unsigned char A=3);

        void Transmit(unsigned int B) {
            Agent::signals[B]++;
        }

        bool Receive(unsigned int B)
        {
            if ( Agent::signals[B] > 0 ){
                Agent::signals[B]--;
                return true;
            }

            return false;
        }

        void Spawn(std::string FN, unsigned int x, unsigned int y);
        void Die();

    public:
        State                                   state;
        Engine::Collider                        collider;

    private:
        static unsigned int signals[1024];

        Runtime::VM                             virtualMachine;
        std::pair<unsigned int, unsigned int>   position;
        std::pair<unsigned int, unsigned int>   velocity;

        sf::Sprite                              sprite;
        sf::Text                                text;

        //
        // references to external objects, useful parts of engine
        //
        Scheduler & scheduler;
    };
}

// ----------------------------------------------------------------------

