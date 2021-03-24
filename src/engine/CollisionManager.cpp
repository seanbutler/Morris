//
// Created by sean on 21/03/2021.
//

#include "Agent.h"
#include "CollisionManager.h"

void Engine::CollisionManager::ResolveCollisions() {
    for(auto AP : others) {
        if ( player->GetSprite()->getGlobalBounds().intersects(AP->GetSprite()->getGlobalBounds())) {
            player->OnCollision(AP);
            AP->OnCollision(player);
        }
    }
}
