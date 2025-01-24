#include "game_engine.h"
#include "bn_keypad.h"

namespace dnd
{
GameEngine::GameEngine() : _math(), _world(_math), _running(true)
{
}

void GameEngine::run()
{
    while (_running)
    {
        process_input();
        update();
        render();
        bn::core::update();
    }
}

void GameEngine::process_input()
{
    if (bn::keypad::start_pressed())
    {
        _running = false; // Exit the game loop
    }
    // ... handle other inputs ...
}

void GameEngine::update()
{
    _world.update();
}

void GameEngine::render()
{
    // Rendering is handled by Butano in the update method
}
} // namespace dnd
