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
    : bg(bn::regular_bg_items::overworld.create_bg(0, 0)), _player(bn::fixed_point(0, 0), bn::random(), _math),
      math_ref(_math)
{
}

void world::setBackground()
{
    bg.set_priority(3);
}

void world::update()
{
    bn::fixed_point direction(0, 0);

    if (bn::keypad::left_held())
    {
        direction.set_x(-1);
        direction.set_y(-0.5); // Move up-right in isometric view
    }
    if (bn::keypad::right_held())
    {
        direction.set_x(1);
        direction.set_y(0.5); // Move down-left in isometric view
    }
    if (bn::keypad::up_held())
    {
        direction.set_x(1);
        direction.set_y(-0.5); // Move down-right in isometric view
    }
    if (bn::keypad::down_held())
    {
        direction.set_x(-1);
        direction.set_y(0.5); // Move up-left in isometric view
    }

    if (direction != bn::fixed_point(0, 0))
    {
        _player.move(direction);
    }

    _player.update();

    bn::fixed_point player_loc = _player.getLocation();

    BN_LOG("Player Location: ", player_loc.x(), ", ", player_loc.y());

    bn::fixed_point player_iso_x = math_ref.cartToIso(bn::fixed_point(player_loc.x(), bn::fixed_t<12>(0)));
    bn::fixed_point player_iso_y = math_ref.cartToIso(bn::fixed_point(player_loc.y(), bn::fixed_t<12>(0)));
}
} // namespace dnd