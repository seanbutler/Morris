cmake_minimum_required(VERSION 3.0.0)
project(Morris VERSION 0.1.0 LANGUAGES C CXX)
set(PROJECT_NAME Morris)
set(CMAKE_CXX_STANDARD 20)


#
#  We Use Fetch Content To Pull External Lib Sources and Make Them
#
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

#
# stduuid - open source stduuid
#
FetchContent_Declare(
	stduuid
	GIT_REPOSITORY https://github.com/mariusbancila/stduuid
	GIT_PROGRESS TRUE
)

set ( UUID_INCLUDE_DIRS 
	${CMAKE_CURRENT_SOURCE_DIR}/build/_deps/stduuid-src/include/
)        

FetchContent_MakeAvailable(
    stduuid
)

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






include(CTest)
enable_testing()

add_executable(Morris ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(SFML_LIBRARIES "-lsfml-graphics -lsfml-window -lsfml-system")

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${UUID_INCLUDE_DIRS}
    ${SFML_INCLUDE_DIR}
)


target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})



