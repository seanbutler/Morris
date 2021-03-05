//
// Created by sean on 11/06/2020.
//

#pragma once

// ----------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <memory>

// ----------------------------------------------------------------------

#include "Entity.h"

namespace Engine {

    class Textures {

    public:
        Textures() {
            if (!texture.loadFromFile("./assets/textures/monochrome_packed.png"))
            {
                std::cout << "Texture Load Error" << std::endl;
            }
        }

        virtual ~Textures() {
        }

        virtual void SetSprite(unsigned int x, unsigned int y, sf::Sprite & sprite) {
            unsigned int size = 16;
            unsigned int gap = 0;
            sprite.setTexture(texture);
            sprite.setTextureRect(sf::IntRect(x*(size+gap), y*(size+gap), size, size));
        }

    private:
        sf::Texture texture;
    };

};

// ----------------------------------------------------------------------
