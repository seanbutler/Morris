//
// Created by sean on 21/03/2021.
//

#pragma once

// ----------------------------------------------------------------------

#include <SFML/Graphics.hpp>

// ----------------------------------------------------------------------

namespace Engine {

    class Collider;

    class CollisionManager {

    public:
        CollisionManager(unsigned int n=32);
        virtual ~CollisionManager();
        Collider* GetNewCollider(sf::Sprite& SPR, unsigned int L=0);

        void Update();

        std::vector<Collider*> colliders;
    };

    // --------------------------------------------------

    class Collider {

    public:
        Collider(sf::Sprite& SPR, unsigned int L = 0)
                : layer(L)
                , sprite(SPR)
                , collidedWithThisFrame()
        {
        }

        void Init(sf::Sprite& SPR, unsigned int L = 0) {
            sprite = SPR;
            layer = L;
            collidedWithThisFrame.clear();
        }

//        virtual ~Collider() {
//
//        }

        sf::Rect<float> GetRect()                   { return sprite.getGlobalBounds();      }
        void SetCollided(unsigned int L)            { collidedWithThisFrame.push_back(L);   }
        void ClearCollided()                        { collidedWithThisFrame.clear();        }
        void SetLayer(unsigned int L)               { layer = L; }
        unsigned int GetLayer()                     { return layer; }

        bool GetCollided(unsigned int L) {
            for ( auto C : collidedWithThisFrame )
                if ( C == L ) return true;

            return false;
        }

    private:
        sf::Sprite&                 sprite;
        unsigned int                layer;
        std::vector<unsigned int>   collidedWithThisFrame;
    };

}

// ----------------------------------------------------------------------
