cmake_minimum_required(VERSION 3.17)
project(Morris)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        src/Compiler/Tokenizer.cpp src/Compiler/Tokenizer.h
        src/Compiler/Tokens.cpp src/Compiler/Tokens.h
        src/Compiler/Parser.cpp src/Compiler/Parser.h
        src/Compiler/InstructionASTVisitor.cpp src/Compiler/InstructionASTVisitor.h
        src/Compiler/SymbolTable.cpp src/Compiler/SymbolTable.h
        src/runtime/VirtualMachine.cpp src/runtime/VirtualMachine.h
        src/common/Instructions.cpp src/common/Instructions.h
        src/runtime/Scheduler.cpp src/runtime/Scheduler.h
        src/Compiler/compiler.cpp src/Compiler/compiler.h
        src/engine/MainLoop.cpp src/engine/MainLoop.h
        src/engine/Entity.h
        src/engine/Input.h
        src/engine/Scheduler.h
        src/Simulation/Agent.cpp src/Simulation/Agent.h)

add_executable(Morris ${SOURCE_FILES})




find_package(SFML REQUIRED COMPONENTS system graphics window network audio)

set(SFML_LIBRARIES "-lsfml-graphics -lsfml-window -lsfml-system")

#TARGET_LINK_LIBRARIES(Glynth pthread)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

target_include_directories(Morris PUBLIC ${UUID_INCLUDE_DIRS})
target_link_libraries(Morris ${UUID_LIBRARIES})



