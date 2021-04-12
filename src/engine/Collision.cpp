//z
// Created by sean on 21/03/2021.
//

#include "Collision.h"

Engine::CollisionManager::CollisionManager(unsigned int n) {
    colliders.reserve(n);
}

Engine::CollisionManager::~CollisionManager() {
    colliders.clear();
}

Engine::Collider * Engine::CollisionManager::GetNewCollider(sf::Sprite& SPR, unsigned int L) {
    Engine::Collider* tmpCollider = new Engine::Collider(SPR, L);
    colliders.push_back(tmpCollider);
    return tmpCollider;
}

void Engine::CollisionManager::Update() {
    for(auto C1 : colliders){
        for(auto C2 : colliders) {
            if (C1->GetLayer() != C2->GetLayer()) {
                if (C1->GetRect().intersects(C2->GetRect())) {
                    C2->SetCollided(C1->GetLayer());
                    C1->SetCollided(C2->GetLayer());
                }
            }
        }
    }
}


// --------------------------------------------------------------------------------



