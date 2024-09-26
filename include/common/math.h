#ifndef MATH_H
#define MATH_H

#include "config.h"
#include <bn_array.h>
#include <bn_core.h>
#include <bn_fixed_point.h>
#include <bn_vector.h>

namespace dnd
{
class math
{
private:
public:
    bn::fixed_point isoToCart(bn::fixed_point pos)
    {
        return bn::fixed_point((pos.x() - pos.y()) * (dnd::config::TILE_WIDTH / 2),
                               (pos.x() + pos.y()) * (dnd::config::TILE_HEIGHT / 4));
    }

    bn::fixed_point cartToIso(bn::fixed_point pos)
    {
        return bn::fixed_point((pos.x() / (dnd::config::TILE_WIDTH / 2) + pos.y() / (dnd::config::TILE_HEIGHT / 4)) / 2,
                               (pos.y() / (dnd::config::TILE_HEIGHT / 4) - pos.x() / (dnd::config::TILE_WIDTH / 2)) /
                                   2);
    }

    bn::fixed_point move(bn::fixed_point position, bn::fixed_point direction)
    {
        bn::fixed_point iso = cartToIso(position);
        return isoToCart(bn::fixed_point(iso.x() + direction.x(), iso.y() + direction.y()));
    }
};
} // namespace dnd
#endif