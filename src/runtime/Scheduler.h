//
// Created by sean on 28/01/2021.
//


#pragma once

// ----------------------------------------------------------------------

#include <vector>
#include "VirtualMachine.h"

// ----------------------------------------------------------------------

namespace Runtime {

    class Scheduler {

    public:
        Scheduler() {}

        virtual ~Scheduler() {}

        void Add(VM *M) {
            virtualMachineList.push_back(M);
        }

        void Update(unsigned int S = 16) {
            for (auto M : virtualMachineList)
                M->Execute(S);
        }

    protected:
        std::vector<VM *> virtualMachineList;

    };


}
// ----------------------------------------------------------------------

