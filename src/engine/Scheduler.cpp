

#include "Scheduler.h"

#include "Agent.h"

// ----------------------------------------------------------------------

namespace Engine {

    void Scheduler::Spawn(std::string FN) {
        executing.push_back(std::shared_ptr<Engine::Entity>(new Agent(*this, FN)));
    }

    void Scheduler::Spawn(std::shared_ptr<Engine::Entity> E) {
        executing.push_back(E);
    }
}

// ----------------------------------------------------------------------

