//
// Created by sean on 11/06/2020.
//

#pragma once

// ----------------------------------------------------------------------
#include <iostream>

//#include <vector>
#include <list>
#include <memory>
#include <algorithm>

// ----------------------------------------------------------------------

#include "Entity.h"
#include "Agent.h"

namespace Engine {

    class Scheduler {

    public:
        Scheduler()             {std::cout << "Scheduler" << std::endl;}
        virtual ~Scheduler()    {std::cout << "~Scheduler" << std::endl;}

        virtual void Spawn(std::string FN);
        virtual void Spawn(std::shared_ptr<Engine::Entity> E);

        virtual void Remove(std::shared_ptr<Engine::Entity> E) {
            E->state = Entity::CORPSE;
            graveyard.push_back(E);
        }

        virtual void Update(float deltaTime)
        {
            for(auto EMB : pending){
                executing.push_back(EMB);
            }
            pending.clear();

            std::cout << "Update Entities = " << executing.size() << std::endl;
            for (auto ENT : executing) {
                ENT->Update(deltaTime);
            }

            auto itor = executing.begin();
            while (itor != executing.end()) {
                if ((*itor)->state == Entity::CORPSE) {
                    itor = executing.erase(itor);
                }
                else {
                    ++itor;
                }
           }
        }

        // TODO - this should be a part of a component not the entity
        virtual void Render(sf::RenderWindow *W)
        {
            std::cout << "Render Entities = " << executing.size() << std::endl;
            for (auto ENT : executing)
            {
                if ( ENT->state != Entity::CORPSE)
                    ENT->Render(W);
            }
        }

    private:
        // TODO - this should be a map (or tree) so we can id and retrieve specific executing?
        std::list<std::shared_ptr<Engine::Entity>> pending;
        std::list<std::shared_ptr<Engine::Entity>> executing;
        std::list<std::shared_ptr<Engine::Entity>> graveyard;
    };

};

// ----------------------------------------------------------------------
