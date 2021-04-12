

#include "Scheduler.h"

#include "Agent.h"

// ----------------------------------------------------------------------

namespace Engine {

    void Scheduler::Spawn(std::string FN, std::pair<unsigned int, unsigned int> POS) {
        embryos.push_back(new Agent(*this, collisionManager, FN, POS));
    }

    void Scheduler::Remove(Agent* E) {
        E->state = Agent::CORPSE;
    }

    void Scheduler::Update(float deltaTime)
    {
        for (auto EXE : executing ) {
            if ( EXE->IsAlive() ) {
                EXE->Update(deltaTime);
            }
        }

        for (auto EMB : embryos ) {
            executing.push_back(std::move(EMB));
        }
        embryos.clear();

        for (auto EXE : executing ) {
            if (EXE->state == Agent::CORPSE) {
                graveyard.push_back(EXE);
                delete(EXE);
                std::erase(executing, EXE);
            }
        }
        graveyard.clear();
    }

    // TODO - this should be a part of a component not the entity
    void Scheduler::Render(sf::RenderWindow *W)
    {
//            std::cout << "Render Entities = " << executing.size() << std::endl;

        for (auto EXE : executing ) {
            EXE->Render(W);
        }
    }

};

