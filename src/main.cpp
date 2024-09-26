#include "bn_core.h"
#include "bn_sprite_text_generator.h"
#include "math.h"
#include "world.h"

#include "common_variable_8x16_sprite_font.h"

int main()
{
    bn::core::init();

    bn::sprite_text_generator text = bn::sprite_text_generator(common::variable_8x16_sprite_font);

    dnd::math math;
    dnd::world world(math);

    while (true)
    {
        bn::core::update();
        world.update();
    }
}
