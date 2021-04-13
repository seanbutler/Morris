//
// Created by sean on 10/02/2021.
//

#include "../core/Object.h"


#include "../compiler/compiler.cpp"
#include "../runtime/VirtualMachine.h"

// ----------------------------------------------------------------------

#include "Font.h"
#include "Input.h"
#include "Collision.h"

#include "Agent.h"
#include "Scheduler.h"

extern Engine::Textures textures;

// ----------------------------------------------------------------------
namespace Engine{

    Agent::Agent( Scheduler & S,
                  std::string & F,
                  std::pair<unsigned int, unsigned int> POS,
                  std::pair<unsigned int, unsigned int> VEL,
                  unsigned int collisionLayer):
            Core::Object("Agent"),
            scheduler(S),
            state(State::ALIVE),
            virtualMachine(Runtime::VM(this, Compiler::compile(F))),
            position(POS),
            velocity(VEL),
            collider()
    {
        virtualMachine.SetOwner(this);
//        textures.SetSprite(0, sprite);
//        sprite.setPosition( sf::Vector2f(position.first, position.second));
    }

    bool Agent::IsAlive() {return state==ALIVE;}

    void Agent::Update(float deltaTime)
    {
        virtualMachine.Execute();

        position.first += velocity.first;
        position.second += velocity.second;
        sprite.setPosition( sf::Vector2f(position.first, position.second) );
        collider.SetRect(sprite.getGlobalBounds());

        collider.HandleCollisions(scheduler);
    }

    void Agent::Render(sf::RenderWindow *W)
    {
        W->draw(sprite);
    }

    void Agent::SetPosition(float X, float Y, unsigned int index)
    {
        position.first = X;
        position.second = Y;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
        collider.SetRect(sprite.getGlobalBounds());
    }

    void Agent::SetVelocity(float X, float Y)
    {
        velocity.first = X;
        velocity.second = Y;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
        collider.SetRect(sprite.getGlobalBounds());
    }

    void Agent::SetSprite(unsigned int N)
    {
        textures.SetSprite(N, &sprite);
        sprite.setPosition(position.first, position.second);
    }

    sf::Sprite* Agent::GetSprite()
    {
        return &sprite;
    }

    unsigned long int Agent::GetInput(unsigned int B) {
        return Engine::Input::GetButton(B);
    }

    void Agent::SetCollisionLayer(unsigned int B){
        collider.SetLayer(B);
    }

    bool Agent::CheckCollided(unsigned int B) {
        return collider.GetCollided(B);
    }

    void Agent::SetColour(unsigned char R, unsigned char G, unsigned char B, unsigned char A) {
        R = (R * 85);
        G = (G * 85);
        B = (B * 85);
        A = (A * 85);
        sprite.setColor(sf::Color((R << 24) | (G << 16) | (B << 8) | A));
    }

    void Agent::Spawn(std::string FN, unsigned int x, unsigned int y)
    {
        scheduler.Spawn(FN, std::pair<unsigned int, unsigned int>(x, y));
    }

    void Agent::Die()
    {
        scheduler.Remove(this);
    }

// ----------------------------------------------------------------------
}
