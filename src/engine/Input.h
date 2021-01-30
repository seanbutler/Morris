//
// Created by sean on 26/06/2020.
//

#ifndef SYNTH_INPUT_H
#define SYNTH_INPUT_H

#include <SFML/Window.hpp>
namespace Engine {

    class Input {
    public:
        static bool buttons(int dir) {
            dir = dir % 3;
            sf::Keyboard::Key key = sf::Keyboard::LShift;
            sf::Keyboard::Key altKey = sf::Keyboard::Z;

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

        static bool stick() {
            return ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                     || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                     || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                     || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                     || sf::Keyboard::isKeyPressed(sf::Keyboard::W)
                     || sf::Keyboard::isKeyPressed(sf::Keyboard::D)
                     || sf::Keyboard::isKeyPressed(sf::Keyboard::S)
                     || sf::Keyboard::isKeyPressed(sf::Keyboard::A) );
        }

        static bool dir(int dir) {
            dir = dir % 3;
            sf::Keyboard::Key key = sf::Keyboard::Up;
            sf::Keyboard::Key altkey = sf::Keyboard::W;

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

            return (sf::Keyboard::isKeyPressed(key) || sf::Keyboard::isKeyPressed(altkey));
        }

    private:
        Input(){}

    };


};


#endif //SYNTH_INPUT_H
