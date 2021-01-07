cmake_minimum_required(VERSION 3.17)
project(Morris)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        src/compiler/Tokenizer.cpp src/compiler/Tokenizer.h
        src/compiler/Tokens.cpp src/compiler/Tokens.h
        src/compiler/Parser.cpp src/compiler/Parser.h
        src/compiler/InstructionASTVisitor.cpp src/compiler/InstructionASTVisitor.h
        src/compiler/SymbolTable.cpp src/compiler/SymbolTable.h
        src/compiler/Runtime.cpp src/compiler/Runtime.h src/compiler/Instructions.h)

add_executable(Morris ${SOURCE_FILES})

target_include_directories(Morris PUBLIC ${UUID_INCLUDE_DIRS})
target_link_libraries(Morris ${UUID_LIBRARIES})