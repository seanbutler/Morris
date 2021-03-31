//
// Created by sean on 30/03/2021.
//

#pragma once

#include <SFML/Graphics/Font.hpp>

#include <iostream>
#include <string>

namespace Engine {

    class Fonts {

    public:
        Fonts(std::string filename="font.ttf") {
            if (!font.loadFromFile(filename)) {
                std::cerr << "ERROR Font::Font() could not find file " << filename << std::endl;
            }

        };

        sf::Font font;

        std::string strings[9] = {
                "Press X To Start",
                "WASD to Move",
                "Game Over",
                "Play Again",
                "Lives",
                "Level",
                "Wave",
                "Health",
                "Score"
        };
    };

}
