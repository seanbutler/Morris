//
// Created by sean on 12/04/2021.
//

#pragma once

#include <iostream>

namespace Core{

    class Object {

    public:
        Object(std::string N) : id(GetGlobalID()), name(N) {
            std::cout << "Object::Object " << id << " " << name << std::endl;
        }

        virtual ~Object()  {
            std::cout << "Object::~Object " << id << " " << name << std::endl;
        }


    public:
        unsigned int id;
        std::string name;


    private:
        unsigned int GetGlobalID(){
            static unsigned int gID;
            return gID++;
        }

    };

}
