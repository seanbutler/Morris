cmake_minimum_required(VERSION 3.17)
project(AnotherLang)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        ./src/Tokenizer.cpp ./src/Tokenizer.h
        ./src/Tokens.cpp ./src/Tokens.h
        ./src/Parser.cpp ./src/Parser.h
        main.cpp)

add_executable(AnotherLang ${SOURCE_FILES})

target_include_directories(AnotherLang PUBLIC ${UUID_INCLUDE_DIRS})
target_link_libraries(AnotherLang ${UUID_LIBRARIES})