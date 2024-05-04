#ifndef TILE_H
#define TILE_H

#include <bn_sprite_ptr.h>
#include "bn_string.h"
#include "bn_sprite_animate_actions.h"

namespace dnd
{
    class tile
    {
    public:
        tile(bn::sprite_ptr _sprite);

        bool isSelected() const { return selected; }
        void setSelected(bool value) { selected = value; }

        bool isHighlighted() const { return highlighted; }
        void setHighlighted(bool value) { highlighted = value; }

        void setHighlight(bn::sprite_ptr newHighlight)
        {
            highlight = newHighlight;
        }

        void clearHighlight()
        {
            highlight.reset();
        }

        bn::sprite_ptr getSprite() const { return sprite; }
        bn::optional<bn::sprite_ptr> getHighlight() const { return highlight; }

        void update();

    private:
        bool selected;
        bool highlighted;
        bn::optional<bn::sprite_ptr> highlight;
        bn::sprite_ptr sprite;
    };
} // namespace dnd
#endif