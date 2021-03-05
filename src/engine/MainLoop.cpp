//
// Created by sean on 11/06/2020.
//

// ----------------------------------------------------------------------

#include "MainLoop.h"

// ----------------------------------------------------------------------

namespace Engine {

    MainLoop::MainLoop(unsigned int W, unsigned int H,
                       unsigned int PS, unsigned int FR,
                       std::string windowTitle)
            :   w(W)
            ,   h(H)
            ,   pixel_scale(PS)
            ,   window(sf::VideoMode(w, h),
                       windowTitle.c_str(),
                       sf::Style::Titlebar | sf::Style::Close )
    {
        window.setSize(sf::Vector2u(w*pixel_scale,h*pixel_scale));
        window.setFramerateLimit(FR);
    }

    void MainLoop::Update()
    {
        while (window.isOpen())
        {
            deltaTime = clock.getElapsedTime().asSeconds();
            clock.restart();

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            entityScheduler.Update(deltaTime);
            window.clear(clearColour);
            entityScheduler.Render(&window);
            window.display();
        }
    }

    MainLoop::~MainLoop()
    {
        window.close();
    }

};

// ----------------------------------------------------------------------
