//
// Created by sean on 11/06/2020.
//

#pragma once

#include <SFML/Graphics.hpp>


namespace Engine {

    class Scheduler;

    class Entity {

    public:

        enum State {
            EMBRYO, ALIVE, CORPSE
        };

        Entity(Scheduler * S) : scheduler(S), state(State::ALIVE){}
        virtual ~Entity() { std::cout << "~Entity" << std::endl; }

        virtual void Update(float deltaTime) = 0;
        virtual void Render(sf::RenderWindow *W) = 0;

        bool IsAlive() {return state==ALIVE;}

        Scheduler * scheduler;
        State state;
    };
};

