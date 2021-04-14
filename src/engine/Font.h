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

            ((sf::Texture&)font.getTexture(12)).setSmooth(false);
            ((sf::Texture&)font.getTexture(16)).setSmooth(false);
            ((sf::Texture&)font.getTexture(24)).setSmooth(false);
            ((sf::Texture&)font.getTexture(32)).setSmooth(false);
            ((sf::Texture&)font.getTexture(48)).setSmooth(false);
            ((sf::Texture&)font.getTexture(64)).setSmooth(false);
        };

        sf::Font font;
    };

}

