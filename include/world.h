#ifndef WORLD_H
#define WORLD_H

#include "bn_regular_bg_items_overworld.h"
#include "bn_sprite_animate_actions.h"
#include "bn_string.h"
#include "entity.h"
#include <bn_regular_bg_ptr.h>
#include <bn_sprite_ptr.h>

namespace dnd
{
class world
{
private:
    bn::regular_bg_ptr bg;
    player _player; // Renamed to _player
    math& math_ref;

public:
    world(dnd::math& _math);
    void setBackground();
    void update();
};
} // namespace dnd

#endif