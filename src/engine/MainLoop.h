//
// Created by sean on 11/06/2020.
//

#pragma once

// ----------------------------------------------------------------------

#include <memory>
#include <vector>
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "Scheduler.h"

// ----------------------------------------------------------------------

namespace Engine {

    class MainLoop {
    public:
        MainLoop(unsigned int W = 32, unsigned int H = 24,
                 unsigned int PS = 32, unsigned int FR = 60);

        virtual ~MainLoop();

        unsigned int w, h, pixel_scale;

        sf::RenderWindow window;

        float deltaTime;
        sf::Clock clock;
        std::shared_ptr<sf::View> view;

        virtual void Update();
        Scheduler entityScheduler;
    };

};

// ----------------------------------------------------------------------


