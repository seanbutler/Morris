
#include <string>

// ---------------------------------------------------------------------------

#include "src/engine/MainLoop.h"
#include "src/engine/Textures.h"
#include "src/engine/Font.h"
#include "src/engine/CollisionManager.h"
#include "src/engine/Agent.h"

// ---------------------------------------------------------------------------

Engine::MainLoop loop(256, 192, 4, 15, "Morris");

Engine::Textures textures;

Engine::Fonts font_manager("./assets/fonts/Computerfont.ttf");
Engine::CollisionManager collision_manager;

// ---------------------------------------------------------------------------

int main(int argc, char**argv) {
    textures.LoadAtlas("./assets/textures/sean/Untitled.png", 16);
    loop.entityScheduler.Spawn("./assets/code/main.src", std::pair<unsigned int, unsigned int>(0, 0));
    loop.Update();

    return 0;
}

// ---------------------------------------------------------------------------
