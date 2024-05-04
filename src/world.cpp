#include <bn_array.h>
#include <bn_vector.h>
#include <bn_point.h>
#include <bn_core.h>

#include "bn_sprite_items_world.h"
#include "world.h"
#include "bn_keypad.h"

namespace dnd
{
    world::world(dnd::math &_math) : bg(bn::regular_bg_items::overworld.create_bg(0, 0)), player(bn::point(0, 0), bn::random(), _math), grid(_math), math_ref(_math)
    {

        // for (int y = 0; y < _math.getworldHeight(); y++)
        // {
        //     for (int x = 0; x < _math.getworldWidth(); x++)
        //     {
        //         bn::point cart = _math.isoToCart(bn::point(x, y));
        //         dnd::Tile tile(bn::sprite_items::world.create_sprite(cart.x(), cart.y() - 1));
        //         tile.getSprite().set_visible(false);
        //         _math.getTiles().push_back(tile);
        //     }
        // }
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
}