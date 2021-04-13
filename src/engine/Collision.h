//
// Created by sean on 21/03/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include <SFML/Graphics.hpp>
#include "../core/Object.h"
#include "../engine/Scheduler.h"

// ----------------------------------------------------------------------

namespace Engine {

class Scheduler;

class Collider : public Core::Object{

    public:
        Collider()
                : Core::Object("Collider"),
                layer(0),
                rect(sf::Rect<float>(0.0, 0.0, 0.0, 0.0))
        {
        }

        Collider(sf::Rect<float> RCT, unsigned int L = 0)
                : Core::Object("Collider"),
                layer(L),
                rect(RCT)
        {
        }

        virtual ~Collider() {
         }

        void SetRect(sf::Rect<float> R)             { rect = R;                             }
        sf::Rect<float> & GetRect()                 { return rect;                          }

        void SetCollided(unsigned int L)            { collidedWithThisFrame.push_back(L);   }
        void ClearCollided()                        { collidedWithThisFrame.clear();        }

        void SetLayer(unsigned int L)               { layer = L; }
        unsigned int GetLayer()                     { return layer; }

        bool GetCollided(unsigned int L) {
            for ( unsigned int C : collidedWithThisFrame )
                if ( C == L ) return true;

            return false;
        }

        void HandleCollisions(Engine::Scheduler & S);


    private:
        sf::Rect<float>             rect;   // set me manually whenever agent moves
        unsigned int                layer;
        std::vector<unsigned int>   collidedWithThisFrame;

    };

}

// ----------------------------------------------------------------------
