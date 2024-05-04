#include "select.h"
#include <math.h>

namespace dnd
{
    Select::Select(Grid *_grid, Math *_math) : grid(*_grid), math(*_math), selected(false), location(0, 0), plr(location, bn::random(), *_math) {}

    void Select::toggleSelection()
    {
        auto &tile = grid.getTile(location);
        const auto &sprite = tile.getSprite();

        // Check sprite position against player position
        if (sprite.x().integer() == plr.getSpr().x() && sprite.y().integer() == plr.getSpr().y() + 8)
        {
            selected = !selected;

            // Toggle tile highlight
            tile.getHighlight().value().set_tiles(bn::sprite_items::cursor.tiles_item(), selected ? 1 : 0);
        }

        // Loop through offsets to update surrounding tiles
        for (int i = 0; i < 12; i++)
        {
            bn::point _location = location;
            _location.set_x(_location.x() + offset[i][0]);
            _location.set_y(_location.y() + offset[i][1]);

            // Validate tile location
            if (_location.x() >= 0 && _location.x() < Config::WORLD_HEIGHT && _location.y() >= 0 && _location.y() < Config::WORLD_HEIGHT)
            {
                auto &_tile = grid.getTile(_location);

                // Check if highlight needs to be updated to avoid unnecessary sprite creation
                if (selected && !_tile.getHighlight().has_value())
                {
                    _tile.setHighlight(bn::sprite_items::selected.create_sprite(math.isoToCart((_location)).x(), math.isoToCart(_location).y() - 3));
                    _tile.getHighlight().value().set_blending_enabled(true);
                    bn::blending::set_transparency_alpha(0.5);
                }
                else if (!selected)
                {
                    _tile.clearHighlight();
                }
            }
        }
    }

    void Select::setSelector()
    {

        auto &tile = grid.getTile(location);
        const auto &sprite = tile.getSprite();
        tile.setHighlight(bn::sprite_items::cursor.create_sprite(sprite.x().integer(), sprite.y().integer() - 3));
    }

    void Select::onMovement()
    {
        if (bn::keypad::left_pressed() || bn::keypad::right_pressed() || bn::keypad::up_pressed() || bn::keypad::down_pressed())
        {

            // selected = false;
            // for (int i = 0; i < grid.getWorldWidth(); i++)
            // {
            //     for (int j = 0; j < grid.getWorldHeight(); j++)
            //     {
            //         // if the anim is "selected" then clear it
            //         if (true)
            //         {
            //             grid.getTile(bn::point(i, j)).clearHighlight();
            //         }
            //     }
            // }

            if (bn::keypad::left_pressed())
            {
                if (location.x() > 0)
                {

                    location.set_x(location.x() - 1);
                }
            }
            if (bn::keypad::right_pressed())
            {
                if (location.x() < Config::WORLD_WIDTH - 1)
                {
                    location.set_x(location.x() + 1);
                }
            }
            if (bn::keypad::up_pressed())
            {
                if (location.y() > 0)
                {
                    location.set_y(location.y() - 1);
                }
            }
            if (bn::keypad::down_pressed())
            {
                if (location.y() < Config::WORLD_HEIGHT - 1)
                {
                    location.set_y(location.y() + 1);
                }
            }
            setSelector();
        }
    }

    void Select::update()
    {
        plr.update();
        if (bn::keypad::a_pressed())
        {
            toggleSelection();
        }

        onMovement();
    }
} // namespace dnd