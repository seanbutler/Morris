//
// Created by sean on 26/06/2020.
//

#pragma once

#include <SFML/Window.hpp>

namespace Engine {

    class Input {

    public:

        static bool GetButton(unsigned int dir=0) {

            dir = dir % 8;
            sf::Keyboard::Key key;
            sf::Keyboard::Key altKey;

            switch (dir) {


                case 1: {
                    key = sf::Keyboard::Up;
                    altKey = sf::Keyboard::W;
                    break;
                }

                case 2: {
                    key = sf::Keyboard::Right;
                    altKey = sf::Keyboard::D;
                    break;
                }

                case 3: {
                    key = sf::Keyboard::Down;
                    altKey = sf::Keyboard::S;
                    break;
                }

                case 4: {
                    key = sf::Keyboard::Left;
                    altKey = sf::Keyboard::A;
                    break;
                }


                case 5: {
                    key = sf::Keyboard::U;
                    altKey = sf::Keyboard::Z;
                    break;
                }

                case 6: {
                    key = sf::Keyboard::I;
                    altKey = sf::Keyboard::X;
                    break;
                }

                case 7: {
                    key = sf::Keyboard::O;
                    altKey = sf::Keyboard::C;
                    break;
                }

                case 8: {
                    key = sf::Keyboard::P;
                    altKey = sf::Keyboard::V;
                    break;
                }

            }

            return ( sf::Keyboard::isKeyPressed(key)  || sf::Keyboard::isKeyPressed(altKey) );
        }

    private:
        Input(){}
    };
};

