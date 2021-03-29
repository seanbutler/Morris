//
// Created by sean on 10/02/2021.
//

#include "Scheduler.h"
#include "Agent.h"

// ----------------------------------------------------------------------

void Agent::Spawn(std::string FN, unsigned int x, unsigned int y)
{
    scheduler->Spawn(FN, std::pair<unsigned int, unsigned int>(x, y));
}

void Agent::Die()
{
    scheduler->Remove(this);
}


// ----------------------------------------------------------------------
