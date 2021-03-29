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
        Textures()
        : texture()
        , sprite_size(16)
        , dimx(0)
        , dimy(0)
        {
        }

        virtual ~Textures() {}

        virtual void LoadAtlas(std::string FN, unsigned int S=16) {
            sprite_size=S;
            if (texture.loadFromFile(FN)) {
                dimx = texture.getSize().x / sprite_size;
                dimy = texture.getSize().y / sprite_size;
                maxcap = dimx * dimy;
            }
            else
            {
                std::cerr << "Texture Load Error" << std::endl;
            }
        }

        virtual void SetSprite(unsigned int n, sf::Sprite & sprite) {
            n = n % maxcap;
            unsigned int x = n % dimx;
            unsigned int y = n / dimx;

            sprite.setTexture(texture);
            sprite.setTextureRect(sf::IntRect(x * sprite_size, y * sprite_size, sprite_size, sprite_size));
        }

    private:
        sf::Texture texture;
        unsigned int sprite_size;
        unsigned int dimx, dimy, maxcap;
    };
};

// ----------------------------------------------------------------------
