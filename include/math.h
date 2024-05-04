#ifndef MATH_H
#define MATH_H

#include <bn_array.h>
#include <bn_vector.h>
#include <bn_fixed_point.h>
#include <bn_core.h>
#include "config.h"

namespace dnd
{
    class math
    {
    private:
    public:
        bn::fixed_point isoToCart(bn::fixed_point pos);
        bn::fixed_point cartToIso(bn::fixed_point pos);
        bn::fixed_point move(bn::fixed_point pos, bn::fixed_point loc);
    };
} // namespace dnd
#endif