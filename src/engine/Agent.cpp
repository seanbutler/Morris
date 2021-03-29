//
// Created by sean on 10/02/2021.
//

#include "Scheduler.h"

#include "Agent.h"

// ----------------------------------------------------------------------

void Agent::Spawn(std::string FN, unsigned int x, unsigned int y)
{
    scheduler.Spawn(
            std::shared_ptr<Engine::Entity>(
                    new Agent(scheduler, FN, std::pair<unsigned int,unsigned int>(x, y))
                    )
    );
}

void Agent::Die()
{
    scheduler.Remove(std::shared_ptr<Engine::Entity>(this));
}


// ----------------------------------------------------------------------
