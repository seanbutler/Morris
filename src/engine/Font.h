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
    };

}

