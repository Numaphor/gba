#include <bn_array.h>
#include <bn_vector.h>
#include <bn_fixed_point.h>
#include <bn_core.h>
#include "math.h"

namespace dnd
{
    bn::fixed_point math::isoToCart(bn::fixed_point pos)
    {
        bn::fixed_point cart;

        cart.set_x(((pos.x() * dnd::config::TILE_WIDTH) / 2) - ((pos.y() * dnd::config::TILE_WIDTH) / 2));
        cart.set_y(((pos.x() * dnd::config::TILE_HEIGHT) / 4) + ((pos.y() * dnd::config::TILE_HEIGHT) / 4));

        return cart;
    }

    bn::fixed_point math::cartToIso(bn::fixed_point pos)
    {
        bn::fixed_point iso;
        pos.set_y(pos.y());

        iso.set_x((pos.x() / (dnd::config::TILE_WIDTH / 2) + pos.y() / (dnd::config::TILE_HEIGHT / 4)) / 2);
        iso.set_y((pos.y() / (dnd::config::TILE_HEIGHT / 4) - pos.x() / (dnd::config::TILE_WIDTH / 2)) / 2);

        return iso;
    }
    // make functions that take the pos + how many tiles to move and return the new pos relative to the grid

    bn::fixed_point math::move(bn::fixed_point pos, bn::fixed_point loc)
    {
        //  cart to iso
        bn::fixed_point iso;

        iso.set_x(isoToCart(pos).x());
        iso.set_y(isoToCart(pos).y());

        //  move

        iso.set_x(iso.x() + loc.x());
        iso.set_y(iso.y() + loc.y());

        //  iso to cart
        bn::fixed_point cart;

        cart.set_x(cartToIso(iso).x());
        cart.set_y(cartToIso(iso).y());

        return cart;
    }

} // namespace dnd