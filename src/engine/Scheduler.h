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
        Scheduler(){ }
        virtual ~Scheduler();

        void Spawn(std::string FN, std::pair<unsigned int, unsigned int> POS = {0.0, 0.0});
        virtual void Remove(Agent* E);
        virtual void Update(float deltaTime);
        virtual void Render(sf::RenderWindow *W);

        std::vector<Agent*> & GetExecutingAgents(){
            return executing;
        }

    private:
        // TODO - this should be a map (or tree) so we can id and retrieve specific executing?
        std::vector <Agent*> embryos, executing, graveyard;
    };

};

// ----------------------------------------------------------------------
