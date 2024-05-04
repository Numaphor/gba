#ifndef SELECT_H
#define SELECT_H

#include <bn_log.h>
#include <random>
#include "bn_sprite_items_selected.h"
#include "math.h"
#include "grid.h"

#include <bn_keypad.h>
#include "entity.h"
#include "common_variable_8x16_sprite_font.h"
#include <bn_sprite_text_generator.h>
#include "bn_sprite_items_cursor.h"
#include "bn_blending_actions.h"

namespace dnd
{
    class Select
    {
    private:
        bn::point iso;
        bn::point cart;
        Player plr;

        bool selected = false;
        int offset[12][2] = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, -2}, {0, 2}, {-2, 0}, {2, 0}};
        int coordss[12][2];

        bn::optional<bn::sprite_animate_action<2>> anim;
        Grid &grid;
        Math &math_ref;
        // int index = 13;
        bn::point location;
        int animIndex;
        int mapindex;
        bn::vector<bn::sprite_ptr, 32> text_sprites;
        bn::vector<bn::sprite_ptr, 13> range;

    public:
        Select(Grid *_grid, Math *_math);
        bn::optional<bn::sprite_animate_action<2>> getAnim() const { return anim; }

        bn::point getIso() const { return iso; }
        void setIso(const bn::point &newIso) { iso = newIso; }

        bn::point getCart() const { return cart; }
        void setCart(const bn::point &newCart) { cart = newCart; }

        bool isSelected() const { return selected; }
        void setSelected(bool newSelected) { selected = newSelected; }

        // int getIndex() const { return index; }
        // void setIndex(int newIndex) { index = newIndex; }

        int getAnimIndex() const { return animIndex; }
        void setAnimIndex(int newAnimIndex) { animIndex = newAnimIndex; }

        int getMapIndex() const { return mapindex; }
        void setMapIndex(int newMapIndex) { mapindex = newMapIndex; }

        void setSelector();
        void onMovement();
        void update();

        void clearHighlight(Math math, bn::point location);
        void toggleSelection();
    };
} // namespace dnd

#endif