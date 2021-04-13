//
// Created by sean on 11/06/2020.
//

#pragma once

// ----------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <memory>


#include <SFML/Graphics.hpp>

// ----------------------------------------------------------------------

namespace Engine {

    class Textures {

    public:
        Textures(std::string FN, unsigned int S=16)
        : texture()
        , sprite_size(S)
        , dimx(0)
        , dimy(0)
        {
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

        virtual ~Textures() {}


        virtual void SetSprite(unsigned int n, sf::Sprite * sprite) {

            if (!sprite) sprite = new sf::Sprite();

            n = n % maxcap;
            unsigned int x = n % dimx;
            unsigned int y = n / dimx;

            sprite->setTexture(texture);
            sprite->setTextureRect(sf::IntRect(x * sprite_size, y * sprite_size, sprite_size, sprite_size));
        }

    private:
        sf::Texture texture;
        unsigned int sprite_size;
        unsigned int dimx, dimy, maxcap;
    };
};

// ----------------------------------------------------------------------
