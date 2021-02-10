//
// Created by sean on 11/06/2020.
//

#pragma once

#include <vector>
#include <memory>

#include "Entity.h"

namespace Engine {

    class Scheduler {

    public:
        Scheduler() {}
        virtual ~Scheduler() {}

        virtual void Update(float deltaTime)
        {
            for (auto entity : entities)
            {
                entity->Update(deltaTime);
            }
        }

        virtual void Render(sf::RenderWindow *W)
        {
            for (auto entity : entities)
            {
                entity->Render(W);
            }
        }

        // TODO - this should be a map (or tree) so we can id and retrieve specific entities
        std::vector<Entity*> entities;
    };

};

