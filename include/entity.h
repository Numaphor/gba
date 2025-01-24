#ifndef ENTITY_H
#define ENTITY_H

#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_entity.h"
#include "bn_string.h"
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_log.h>
#include <bn_random.h>
#include <bn_sprite_ptr.h>
#include <random>

#include "math.h"

namespace dnd
{
class entity
{
private:
    bn::fixed_point location;
    bn::random random;
    int animIndex;
    int mapindex;
    bn::vector<bn::sprite_ptr, 32> text_sprites;

public:
    entity(bn::fixed_point _location, bn::random _random, int _animIndex, int _mapindex)
        : location(_location), random(_random), animIndex(_animIndex), mapindex(_mapindex)
    {
    }

    bn::optional<bn::sprite_animate_action<2>> anim;
    bn::optional<bn::sprite_ptr> spr;

    // Getters
    bn::fixed_point getLocation() const
    {
        return location;
    }
    bn::random getRandom() const
    {
        return random;
    }
    int getAnimIndex() const
    {
        return animIndex;
    }
    int getMapIndex() const
    {
        return mapindex;
    }
    bn::vector<bn::sprite_ptr, 32> getTextSprites() const
    {
        return text_sprites;
    }
    bn::sprite_ptr getSpr() const
    {
        return spr.value();
    }

    // Setters
    void setLocation(bn::fixed_point _location)
    {
        location = _location;
    }
    void setRandom(bn::random _random)
    {
        random = _random;
    }
    void setAnimIndex(int _animIndex)
    {
        animIndex = _animIndex;
    }
    void setMapIndex(int _mapindex)
    {
        mapindex = _mapindex;
    }
    void setTextSprites(bn::vector<bn::sprite_ptr, 32> _text_sprites)
    {
        text_sprites = _text_sprites;
    }
    void setSpr(bn::optional<bn::sprite_ptr> _spr)
    {
        spr = _spr;
    }
};

class player : public entity
{
public:
    player(bn::fixed_point _location, bn::random _random, math& _math)
        : entity(_location, _random, 16,
                 ((_location.x() < 0) ? -_location.x() : _location.x()).right_shift_integer() * 10 +
                     ((_location.y() < 0) ? -_location.y() : _location.y()).right_shift_integer())
    {
        setSpr(bn::sprite_items::entity.create_sprite(
            _math.isoToCart(bn::fixed_point(_location.x() - 1, _location.y() - 1)).x(),
            _math.isoToCart(bn::fixed_point(_location.x() - 1, _location.y() - 1)).y()));
        getSpr().set_bg_priority(1);
        anim = bn::create_sprite_animate_action_forever(getSpr(), 30, bn::sprite_items::entity.tiles_item(), 0, 1);
    }

    void update()
    {
        anim.value().update();
        spr.value().set_position(getLocation().x(), getLocation().y() - 8);
    }

    void move(const bn::fixed_point& direction)
    {
        bn::fixed_point new_location = getLocation() + direction;
        setLocation(new_location);
    }
};

// class enemy : public entity
// {
// public:
//     enemy(bn::fixed_point _location, bn::random _random, math &_math)
//         : entity(_location, _random, 40, (((_location.x() < 0) ? -_location.x() : _location.x()) * 10 +
//         ((_location.y() < 0) ? -_location.y() : _location.y())))
//     {
//         // Implementation similar to Player
//     }
// };
} // namespace dnd

#endif