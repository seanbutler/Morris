//z
// Created by sean on 21/03/2021.
//

#include "Collision.h"
#include "Scheduler.h"
#include "Agent.h"

// TO DO - move my function into a more immediate is collided this frame function

void Engine::Collider::HandleCollisions(Engine::Scheduler & SCH) {

    ClearCollided();

    // TODO optimise this...
    for(auto AGT : SCH.GetExecutingAgents()) {
        if ( ( GetLayer() != 0) && ( AGT->collider.GetLayer() != 0 ) ) {
            if (GetLayer() != AGT->collider.GetLayer()) {
                if (GetRect().intersects(AGT->collider.GetRect())) {
                    SetCollided(AGT->collider.GetLayer());
                    AGT->collider.SetCollided(GetLayer());
                }
            }
        }
    }
}


// --------------------------------------------------------------------------------



