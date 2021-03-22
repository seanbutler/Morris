
#include <string>

// ---------------------------------------------------------------------------

#include "src/engine/MainLoop.h"
#include "src/engine/Textures.h"
#include "src/Simulation/Agent.h"

// ---------------------------------------------------------------------------

Engine::MainLoop loop(256, 192, 3, 30, "Oi!");
Engine::Textures textures;

// ---------------------------------------------------------------------------

int main(int argc, char**argv) {

//    textures.LoadAtlas("./assets/textures/kenney/pformer/monochrome_tilemap_transparent_packed.png", 16);
//    textures.LoadAtlas("./assets/textures/sean/Untitled.png", 16);
    textures.LoadAtlas("./assets/textures/kenney/rpg/large/monochrome_packed.png", 16);

    loop.entityScheduler.Spawn(new Agent("./assets/code/main.src"));
    loop.Update();

    return 0;
}

// ---------------------------------------------------------------------------
