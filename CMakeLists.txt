cmake_minimum_required(VERSION 3.17)
project(Morris)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        main.cpp
        src/compiler/Tokenizer.cpp src/compiler/Tokenizer.h
        src/compiler/Tokens.cpp src/compiler/Tokens.h
        src/compiler/Parser.cpp src/compiler/Parser.h
        src/compiler/InstructionASTVisitor.cpp src/compiler/InstructionASTVisitor.h
        src/compiler/SymbolTable.cpp src/compiler/SymbolTable.h
        src/runtime/VirtualMachine.cpp src/runtime/VirtualMachine.h
        src/compiler/Instructions.cpp src/compiler/Instructions.h
        src/compiler/compiler.cpp src/compiler/compiler.h
        src/engine/Collision.cpp src/engine/Collision.h
        src/engine/Input.h
        src/engine/MainLoop.cpp src/engine/MainLoop.h
        src/engine/Scheduler.cpp src/engine/Scheduler.h
        src/engine/Agent.cpp src/engine/Agent.h
        src/engine/Font.cpp src/engine/Font.h src/core/Object.cpp src/core/Object.h)

add_executable(Morris ${SOURCE_FILES})




find_package(SFML REQUIRED COMPONENTS system graphics window network audio)

set(SFML_LIBRARIES "-lsfml-graphics -lsfml-window -lsfml-system")

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

target_include_directories(Morris PUBLIC ${UUID_INCLUDE_DIRS})
target_link_libraries(Morris ${UUID_LIBRARIES})



