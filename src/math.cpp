#include "math.h"
#include <bn_array.h>
#include <bn_core.h>
#include <bn_fixed_point.h>
#include <bn_vector.h>

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

bn::fixed_point math::move(bn::fixed_point position, bn::fixed_point direction)
{
    bn::fixed_point isometricPosition = cartToIso(position);
    isometricPosition.set_x(isometricPosition.x() + direction.x());
    isometricPosition.set_y(isometricPosition.y() + direction.y());
    bn::fixed_point destination = isoToCart(isometricPosition);

    return destination;
}

} // namespace dnd