//
// Created by sean on 10/02/2021.
//

#include "Agent.h"
#include "../engine/Scheduler.h"

// ----------------------------------------------------------------------

void Agent::Spawn(std::string FN)
{
    if ( scheduler ) {
        scheduler->Spawn(new Agent(FN));
    }
}

// ----------------------------------------------------------------------
