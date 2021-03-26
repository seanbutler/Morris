//
// Created by sean on 10/02/2021.
//

#include "Agent.h"

// ----------------------------------------------------------------------

void Agent::Spawn(std::string FN, unsigned int x, unsigned int y)
{
    if ( scheduler ) {
        Agent * ag = new Agent(FN);
        ag->SetPosition(x, y);
        scheduler->Spawn(ag);
    }
}


void Agent::Die()
{
    if ( scheduler ) {
        std::remove(scheduler->entities.begin(),scheduler->entities.end(),this);
    }
}


// ----------------------------------------------------------------------
