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
        Scheduler()             { std::cout << "Scheduler" << std::endl;  }
        virtual ~Scheduler()    { std::cout << "~Scheduler" << std::endl; }

        virtual void Spawn(std::string FN, std::pair<unsigned int, unsigned int> POS);

        virtual void Remove(Engine::Entity*E) {
            E->state = Entity::CORPSE;
        }

        virtual void Update(float deltaTime)
        {
            std::cout << "Update Entities = " << executing.size() << std::endl;
            for (auto EXE : executing ) {
                if ( EXE->IsAlive() ) {
                    EXE->Update(deltaTime);
                }
            }

            std::cout << "Update Embryos = " << embryos.size() << std::endl;
            for (auto EMB : embryos ) {
                executing.push_back(std::move(EMB));
            }
            embryos.clear();

            std::cout << "Update Graveyard = " << embryos.size() << std::endl;
            for (auto EXE : executing ) {
                if (EXE->state == Entity::CORPSE) {
                    graveyard.push_back(EXE);
                    delete(EXE);
                    std::erase(executing, EXE);
                }
            }
            graveyard.clear();
        }

        // TODO - this should be a part of a component not the entity
        virtual void Render(sf::RenderWindow *W)
        {
            std::cout << "Render Entities = " << executing.size() << std::endl;

            for (auto EXE : executing ) {
                EXE->Render(W);
            }
        }

    private:
        // TODO - this should be a map (or tree) so we can id and retrieve specific executing?
        std::vector <Engine::Entity*> embryos, executing, graveyard;

    };

};

// ----------------------------------------------------------------------
