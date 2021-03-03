//
// Created by sean on 11/06/2020.
//

#pragma once

#include <SFML/Graphics.hpp>


namespace Engine {

    class Scheduler;

    class Entity {
    public:
        Entity() : scheduler(nullptr) {}
        virtual ~Entity() {}

        virtual void Update(float deltaTime) = 0;
        virtual void Render(sf::RenderWindow *W) = 0;

        Scheduler * scheduler;
    };
};

