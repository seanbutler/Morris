//
// Created by sean on 11/06/2020.
//

#pragma once

// ----------------------------------------------------------------------
#include <iostream>

#include <vector>
#include <memory>

// ----------------------------------------------------------------------

#include "Entity.h"


namespace Engine {

    class Scheduler {

    public:
        Scheduler() {}
        virtual ~Scheduler() {
            for(auto E : entities) {
                delete E;
            }
        }

        virtual void Spawn(Engine::Entity * E) {
            // TODO - this is probably super inefficient
            E->scheduler = this;
            embryos.push_back(E);
        }

        virtual void Remove(Engine::Entity * E) {
            corpses.push_back(E);
        }

        virtual void Update(float deltaTime)
        {
            std::cout << "Entities = " << entities.size() << std::endl;
            for (auto entity : entities)
            {
                entity->Update(deltaTime);
            }

            if ( embryos.size() )
            {
                std::cout << "Embryos = " << embryos.size() << std::endl;
                for(auto NE : embryos){
                    entities.push_back(NE);
                }
                embryos.clear();
            }

            if ( corpses.size() )
            {
                std::cout << "Corpses = " << corpses.size() << std::endl;

                for(auto CE : corpses){
//                    entities.erase(CE);
                }

                corpses.clear();
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
        std::vector<Engine::Entity*> embryos;
        std::vector<Engine::Entity*> corpses;
    };

};

// ----------------------------------------------------------------------
