

#include "Scheduler.h"

#include "Agent.h"

// ----------------------------------------------------------------------

namespace Engine {

    void Scheduler::Spawn(std::string FN, std::pair<unsigned int, unsigned int> POS = {0, 0}) {
        embryos.push_back(new Agent(this, FN, POS));
    }

}

// ----------------------------------------------------------------------

