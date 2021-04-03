//z
// Created by sean on 21/03/2021.
//

#include "Agent.h"
#include "CollisionManager.h"

void Engine::CollisionManager::Update() {
    for(auto EES : collidees) {
        for(auto ERS : colliders) {
            if ( EES->GetGlobalBounds().intersects(ERS->GetGlobalBounds())) {
                ERS->OnCollision(EES);
                EES->OnCollision(ERS);
            }
        }
    }
}
