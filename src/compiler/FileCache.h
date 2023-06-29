#pragma once

#include <iostream>
#include <map>
#include <string>

class SimpleFileCache {
    public:

    const std::string & Get(const std::string & filename) 
    {
        if (auto search = map_.find(filename); search != map_.end()) {
            std::cout << "Found " << search->first << '\n';
            return search->second;
        }   
        else {
            std::cout << "Not Found so load it " << filename << '\n';

            std::ifstream t(filename);
            std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
            t.close();

            map_[filename] = str;
    
            return map_.find(filename)->second;
        }
    }


    std::map<std::string, std::string> map_;
};




