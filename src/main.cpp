#include "bn_core.h"
#include "bn_sprite_text_generator.h"
#include "game_engine.h"
#include "math.h"
#include "world.h"

#include "common_variable_8x16_sprite_font.h"

int main()
{
    bn::core::init();
    dnd::GameEngine game_engine;
    game_engine.run();
}
