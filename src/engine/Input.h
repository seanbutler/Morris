//
// Created by sean on 26/06/2020.
//

#pragma once

#include <SFML/Window.hpp>

namespace Engine {

    class Input {

    public:

        static bool btn(unsigned int dir) {

            dir = dir % 3;
            sf::Keyboard::Key key;
            sf::Keyboard::Key altKey;

            switch (dir) {
                case 0: {
                    key = sf::Keyboard::U;
                    altKey = sf::Keyboard::Z;
                    break;
                }
                case 1: {
                    key = sf::Keyboard::I;
                    altKey = sf::Keyboard::X;
                    break;
                }
                case 2: {
                    key = sf::Keyboard::O;
                    altKey = sf::Keyboard::C;
                    break;
                }
                case 3: {
                    key = sf::Keyboard::P;
                    altKey = sf::Keyboard::V;
                    break;
                }
            }

            return (sf::Keyboard::isKeyPressed(key) || sf::Keyboard::isKeyPressed(altKey));
        }

        static bool dir(int dir) {

            dir = dir % 3;
            sf::Keyboard::Key key;
            sf::Keyboard::Key altkey;

            switch (dir) {
                case 0: {
                    key = sf::Keyboard::Up;
                    altkey = sf::Keyboard::W;
                    break;
                }
                case 1: {
                    key = sf::Keyboard::Right;
                    altkey = sf::Keyboard::D;
                    break;
                }
                case 2: {
                    key = sf::Keyboard::Down;
                    altkey = sf::Keyboard::S;
                    break;
                }
                case 3: {
                    key = sf::Keyboard::Left;
                    altkey = sf::Keyboard::A;
                    break;
                }
            }

            return ( sf::Keyboard::isKeyPressed(key)  || sf::Keyboard::isKeyPressed(altkey) );
        }

    private:
        Input(){}
    };
};

