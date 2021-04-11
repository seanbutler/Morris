//z
// Created by sean on 21/03/2021.
//

#include "Collision.h"

Engine::CollisionManager::CollisionManager() {

}

Engine::Collider * Engine::CollisionManager::GetNewCollider(sf::Sprite& SPR, unsigned int L) {
    Engine::Collider* tmpCollider = new Engine::Collider(SPR, L);
    colliders.push_back(tmpCollider);
    return tmpCollider;
}

// --------------------------------------------------------------------------------



