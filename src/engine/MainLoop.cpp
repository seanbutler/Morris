//
// Created by sean on 11/06/2020.
//

// ----------------------------------------------------------------------

 #define SCREENSHOTS

// ----------------------------------------------------------------------

#include "MainLoop.h"
#include <iostream>

#ifdef SCREENSHOTS
    #include<sstream>
    #include <iomanip>
#endif

// ----------------------------------------------------------------------

namespace Engine {

#ifdef SCREENSHOTS
    unsigned int screenshot_num = 0;
#endif

    MainLoop::MainLoop(unsigned int W, unsigned int H,
                       unsigned int PS, unsigned int FR,
                       std::string windowTitle)
            :   w(W)
            ,   h(H)
            ,   pixel_scale(PS)
            ,   window(sf::VideoMode(w, h),
                       windowTitle.c_str()
                       , sf::Style::Titlebar
                        | sf::Style::Close
                       )
           ,    entityScheduler()
           ,    deltaTime(0)
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

#ifdef SCREENSHOTS
            sf::Vector2u windowSize = window.getSize();
            sf::Texture texture;
            texture.create(windowSize.x, windowSize.y);
            texture.update(window);
            sf::Image screenshot = texture.copyToImage();

            std::stringstream filename;
            filename << "screenshots/screenshot_" << std::setw(5) << std::setfill('0') << screenshot_num << ".png";
            screenshot.saveToFile( filename.str() );
            screenshot_num++;
#endif
        }
    }

    MainLoop::~MainLoop()
    {
        window.close();
    }

};

// ----------------------------------------------------------------------
