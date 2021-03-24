//
// Created by sean on 21/03/2021.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "Agent.h"

namespace Engine {

    class CollisionManager {

    public:
        CollisionManager() {}
        void ResolveCollisions();

        Agent * player;
        std::vector<Agent *> others;
    };

}
