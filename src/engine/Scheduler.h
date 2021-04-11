//
// Created by sean on 11/06/2020.
//

#pragma once

// ----------------------------------------------------------------------

#include <list>
#include <memory>
#include <algorithm>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Collision.h"

// ----------------------------------------------------------------------

namespace Engine {

    class Agent;

    class Scheduler {

    public:
        Scheduler(CollisionManager & CM)
        : collisionManager(CM){}

        virtual ~Scheduler()        {
            for(auto E : executing){
                delete E;
            }
            executing.clear();
        }

        void Spawn(std::string FN, std::pair<unsigned int, unsigned int> POS = {0.0, 0.0});

        virtual void Remove(Agent* E);
        virtual void Update(float deltaTime);

        virtual void Render(sf::RenderWindow *W);
        virtual void Collide();

    private:
        // TODO - this should be a map (or tree) so we can id and retrieve specific executing?
        std::vector <Agent*> embryos, executing, graveyard;

        CollisionManager& collisionManager;
    };

};

// ----------------------------------------------------------------------
