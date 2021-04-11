//
// Created by sean on 10/02/2021.
//


#include "../compiler/compiler.cpp"
#include "../runtime/VirtualMachine.h"

// ----------------------------------------------------------------------

#include "Font.h"
#include "Input.h"
#include "Collision.h"

#include "Agent.h"
#include "Scheduler.h"

// ----------------------------------------------------------------------
namespace Engine{

    Agent::Agent( Scheduler & S,
                  CollisionManager & CM,
                  std::string & F,
                  std::pair<unsigned int, unsigned int> POS,
                  std::pair<unsigned int, unsigned int> VEL,
                  unsigned int collisionLayer) :
            scheduler(S),
            collisionManager(CM),
            state(State::ALIVE),
            virtualMachine(Runtime::VM(Compiler::compile(F))),
            position(POS),
            velocity(VEL),
            sprite(),
            collider(nullptr)
    {
        virtualMachine.SetOwner(this);
    }

    bool Agent::IsAlive() {return state==ALIVE;}

    void Agent::Update(float deltaTime)
    {
        virtualMachine.Execute();

        position.first += velocity.first;
        position.second += velocity.second;
        sprite.setPosition( sf::Vector2f(position.first, position.second) );
        text.setPosition( sf::Vector2f(position.first, position.second) );
    }

    void Agent::Render(sf::RenderWindow *W)
    {
        W->draw(text); W->draw(sprite);
    }

    void Agent::SetPosition(float X, float Y, unsigned int index)
    {
        position.first = X;
        position.second = Y;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
        text.setPosition(sf::Vector2f(position.first, position.second));
    }

    void Agent::SetVelocity(float X, float Y)
    {
        velocity.first = X;
        velocity.second = Y;
        sprite.setPosition( sf::Vector2f(position.first, position.second));
        text.setPosition(sf::Vector2f(position.first, position.second));
    }

    void Agent::SetSprite(unsigned int N)
    {
        sf::Sprite tmpSprite;
        textures.SetSprite(N, tmpSprite);
        tmpSprite.setPosition(position.first, position.second);
        sprite = tmpSprite;
        text.setPosition(sf::Vector2f(position.first, position.second));
    }

    void Agent::SetText(std::string message, unsigned int SZ, sf::Color COL)
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

    sf::Sprite* Agent::GetSprite()
    {
        return &sprite;
    }

    unsigned long int Agent::GetInput(unsigned int B) {
        return Engine::Input::GetButton(B);
    }

    void Agent::SetCollisionLayer(unsigned int B){
        if ( collider == nullptr )
        {
            collider = collisionManager.GetNewCollider(sprite);
        }
        collider->SetLayer(B);
    }

    bool Agent::CheckCollided(unsigned int B) {
        // WORKING HERE
        return collider->GetCollided(B);
    }

    void Agent::SetColour(unsigned char R, unsigned char G, unsigned char B, unsigned char A) {
        R = (R * 85);
        G = (G * 85);
        B = (B * 85);
        A = (A * 85);
        sprite.setColor(sf::Color((R << 24) | (G << 16) | (B << 8) | A));
    }

    void Agent::SetAlienVar(std::string index, unsigned int value)
    {
        alienVarTable[index] = value;
    }

    unsigned int Agent::GetAlienVar(std::string index)
    {
        return alienVarTable[index];
    }

    void Agent::ClearAlienVars()
    {
        alienVarTable.clear();
    }

    sf::Rect<float> Agent::GetGlobalBounds() {
        return sprite.getGlobalBounds();
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
