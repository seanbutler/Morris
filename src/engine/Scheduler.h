//
// Created by sean on 11/06/2020.
//

#pragma once

// ----------------------------------------------------------------------

#include <vector>
#include <memory>

// ----------------------------------------------------------------------

#include "Entity.h"

namespace Engine {

    class Scheduler {

    public:
        Scheduler() {}
        virtual ~Scheduler() {}

        virtual void Spawn(Engine::Entity * E) {
            // TODO - this is super inefficient
            E->scheduler = this;
            entities.insert(entities.begin(), E);
        }

        virtual void Update(float deltaTime)
        {
            for (auto entity : entities)
            {
                entity->Update(deltaTime);
            }
        }

        // TODO - this should be a part of a component not the entity
        virtual void Render(sf::RenderWindow *W)
        {
            for (auto entity : entities)
            {
                entity->Render(W);
            }
        }

        // TODO - this should be a map (or tree) so we can id and retrieve specific entities
        std::vector<Engine::Entity*> entities;
    };

};

// ----------------------------------------------------------------------
