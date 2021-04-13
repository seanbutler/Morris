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
            // add me to the static colliers list
//            AllColliders().emplace_back(this);
        }

        Collider(sf::Rect<float> RCT, unsigned int L = 0)
                : Core::Object("Collider"),
                layer(L),
                rect(RCT)
        {
            // add me to the static colliers list
//            AllColliders().emplace_back(this);
        }

        virtual ~Collider() {
            // find and remove me from the static colliders list

//            std::cout << "id = " << id << " " << " sz1 = " << AllColliders().size() << std::endl;
//
//            std::remove_if(AllColliders().begin(), AllColliders().end(),
//                      [this] (Collider* C) -> bool {
//                            if ( C->id == id ){
//                                return true;
//                            }
//                            return false;
//                      });
//
//            std::cout << "sz2 = " << AllColliders().size() << std::endl;

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

//        std::vector<Collider*>&  AllColliders(){
//            static std::vector<Collider*> colliders;
//            return colliders;
//        }

    private:
        sf::Rect<float>             rect;   // set me manually whenever agent moves
        unsigned int                layer;
        std::vector<unsigned int>   collidedWithThisFrame;

    };

}

// ----------------------------------------------------------------------
