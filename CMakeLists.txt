cmake_minimum_required(VERSION 3.17)
project(Morris)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        ./src/Tokenizer.cpp ./src/Tokenizer.h
        ./src/Tokens.cpp ./src/Tokens.h
        ./src/Parser.cpp ./src/Parser.h
        src/Emitter.cpp src/Emitter.h src/Generator.cpp src/Generator.h)

add_executable(Morris ${SOURCE_FILES})

target_include_directories(Morris PUBLIC ${UUID_INCLUDE_DIRS})
target_link_libraries(Morris ${UUID_LIBRARIES})