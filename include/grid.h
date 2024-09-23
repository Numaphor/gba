#ifndef GRID_H
#define GRID_H

#include "bn_sprite_items_cursor.h"
#include "math.h"
#include <bn_array.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_point.h>
#include <bn_vector.h>

namespace dnd
{
class grid
{
private:
    static const int ARRAY_SIZE = config::TILE_HEIGHT * dnd::config::WORLD_WIDTH;
    bn::optional<bn::sprite_ptr> highlight;
    math& math_ref; // Add a reference to math

public:
    grid(dnd::math _math) : highlight(bn::sprite_items::cursor.create_sprite(0, -4)), math_ref(_math) {};

    void update()
    {
        move();
    };

    void set()
    {
        highlight.get()->set_position(highlight.get()->position());
    }

    void move()
    {

        if (bn::keypad::left_pressed())
        {

            highlight.value().set_position(math_ref.move(highlight.get()->position(), bn::point(-1, 0)));
            set();
        }
        if (bn::keypad::right_pressed())
        {

            highlight.value().set_position(math_ref.move(highlight.get()->position(), bn::point(1, 0)));
            set();
        }
        if (bn::keypad::up_pressed())
        {
            highlight.value().set_position(math_ref.move(highlight.get()->position(), bn::point(0, -1)));
            set();
        }
        if (bn::keypad::down_pressed())
        {
            highlight.value().set_position(math_ref.move(highlight.get()->position(), bn::point(0, 1)));
            set();
        }
    }
};
} // namespace dnd
#endif