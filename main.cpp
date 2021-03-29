
#include <string>

// ---------------------------------------------------------------------------

#include "src/engine/MainLoop.h"
#include "src/engine/Textures.h"
#include "src/engine/CollisionManager.h"
#include "src/engine/Agent.h"

// ---------------------------------------------------------------------------

Engine::MainLoop loop(256, 192, 4, 30, "Window");

Engine::Textures textures;
Engine::CollisionManager collision_manager;

// ---------------------------------------------------------------------------

int main(int argc, char**argv) {

//    textures.LoadAtlas("./assets/textures/kenney/pformer/monochrome_tilemap_transparent_packed.png", 16);
//    textures.LoadAtlas("./assets/textures/kenney/rpg/large/monochrome_packed.png", 16);

    textures.LoadAtlas("./assets/textures/sean/Untitled.png", 16);

//    loop.entityScheduler.Spawn(std::unique_ptr<Engine::Entity>(new Agent("./assets/code/main.src")));
    loop.entityScheduler.Spawn("./assets/code/main.src", std::pair<unsigned int, unsigned int>(0, 0));
    loop.Update();

    return 0;
}

// ---------------------------------------------------------------------------
