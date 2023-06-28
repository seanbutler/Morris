
#include <string>

// ---------------------------------------------------------------------------

#include "src/engine/MainLoop.h"
#include "src/engine/Textures.h"
#include "src/engine/Font.h"
#include "src/engine/Collision.h"
#include "src/engine/Agent.h"

// ---------------------------------------------------------------------------

Engine::Textures textures("./assets/textures/sean/Untitled.png", 16);
Engine::Fonts font_manager("./assets/fonts/Computerfont.ttf");
Engine::MainLoop loop(256, 192, 6, 30, "Morris");

// ---------------------------------------------------------------------------

int main(int argc, char**argv) {

    loop.entityScheduler.Spawn("./assets/code/main.src", std::pair<unsigned int, unsigned int>(0, 0));
    loop.Update();

    return 0;
}

// ---------------------------------------------------------------------------
