//
// Created by sean on 21/03/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include <SFML/Graphics.hpp>
#include "Agent.h"

// ----------------------------------------------------------------------

namespace Engine {

    class Collider;

    // --------------------------------------------------

    class CollisionManager {
    public:
        CollisionManager() {}
        void Update();

        std::vector<Collider *> colliders;
        std::vector<Collider *> collidees;
    };

    // --------------------------------------------------

    class Collider {
    public:
        Collider(sf::Sprite *SPR)
        : sprite(SPR)
        , label("undefined")
        {

        }

        virtual void OnCollision(Collider* other) = 0;
        sf::Rect<float> GetGlobalBounds()           { return sprite->getGlobalBounds(); }
        void SetLabel(std::string L="undefined")    { label = L; }
        bool IsLabel(std::string S)                 { return label==S; }

        sf::Sprite* sprite;
        std::string label;
    };

    // --------------------------------------------------

}

// ----------------------------------------------------------------------
