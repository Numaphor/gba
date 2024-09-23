#include <bn_array.h>
#include <bn_core.h>
#include <bn_point.h>
#include <bn_vector.h>

#include "bn_keypad.h"
#include "bn_sprite_items_world.h"
#include "world.h"

namespace dnd
{
world::world(dnd::math& _math)
    : bg(bn::regular_bg_items::overworld.create_bg(0, 0)), player(bn::point(0, 0), bn::random(), _math), grid(_math),
      math_ref(_math)
{
}

void world::setBackground()
{
    bg.set_priority(3);
}

void world::update()
{
    player.update();
    grid.update();
}
} // namespace dnd