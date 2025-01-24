#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "world.h"
#include <bn_core.h>

namespace dnd
{
class GameEngine
{
public:
    GameEngine();
    void run();

private:
    void process_input();
    void update();
    void render();

    dnd::math _math;
    dnd::world _world;
    bool _running;
};
} // namespace dnd

#endif
