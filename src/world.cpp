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
    : bg(bn::regular_bg_items::overworld.create_bg(0, 0)), _grid(_math),
      _player(bn::fixed_point(0, 0), bn::random(), _math), math_ref(_math)
{
}

void world::setBackground()
{
    bg.set_priority(3);
}

void world::update()
{
    _player.update();
    _grid.update();

    bn::fixed_point player_loc = _player.getLocation();
    bn::fixed_point highlight_loc = _grid.getHighlight().value().position();

    BN_LOG("Player Location: ", player_loc.x(), ", ", player_loc.y());
    BN_LOG("Highlight Location: ", highlight_loc.x(), ", ", highlight_loc.y() + 4);

    bn::fixed_point player_iso_x = math_ref.cartToIso(bn::fixed_point(player_loc.x(), bn::fixed_t<12>(0)));
    bn::fixed_point player_iso_y = math_ref.cartToIso(bn::fixed_point(player_loc.y(), bn::fixed_t<12>(0)));
    bn::fixed_point highlight_iso_x = math_ref.cartToIso(bn::fixed_point(highlight_loc.x(), bn::fixed_t<12>(0)));
    bn::fixed_point highlight_iso_y =
        math_ref.cartToIso(bn::fixed_point(highlight_loc.y() + bn::fixed_t<12>(4), bn::fixed_t<12>(0)));

    if (player_iso_x == highlight_iso_x && player_iso_y == highlight_iso_y && bn::keypad::a_pressed())
    {
        _grid.getHighlight().value().set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(1));
    }
    if (bn::keypad::b_pressed())
    {
        _grid.getHighlight().value().set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(0));
        bn::fixed_point new_location(_grid.getHighlight().value().position().x(),
                                     _grid.getHighlight().value().position().y() + 4);
        _player.setLocation(new_location);
    }
}
} // namespace dnd