

#include "Scheduler.h"

#include "Agent.h"

// ----------------------------------------------------------------------

namespace Engine {


    Scheduler::~Scheduler() {

        for(Agent * E : embryos){
            delete E;
        }
        embryos.clear();

        for(auto E : executing){
            delete E;
        }
        executing.clear();

        for(auto E : graveyard){
            delete E;
        }
        graveyard.clear();
    }

    void Scheduler::Spawn(std::string FN, std::pair<unsigned int, unsigned int> POS) {
        embryos.push_back(new Agent(*this, FN, POS));
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
            executing.push_back(EMB);
        }
        embryos.clear();

        for (auto EXE : executing ) {
            if (EXE->state == Agent::CORPSE) {
                graveyard.push_back(std::move(EXE));
                std::erase(executing, EXE);
            }
        }
        graveyard.clear();
    }

    // TODO - this should be a part of a service or system not the scheduler
    void Scheduler::Render(sf::RenderWindow *W)
    {
//            std::cout << "Render Entities = " << executing.size() << std::endl;

        for (auto EXE : executing ) {
            EXE->Render(W);
        }
    }

};

