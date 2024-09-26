#ifndef CONFIG_H
#define CONFIG_H

#include <bn_array.h>
#include <bn_vector.h>
#include <bn_point.h>
#include <bn_core.h>

namespace dnd
{
    class config
    {
    private:
    public:
        static const int TILE_WIDTH = 16;
        static const int TILE_HEIGHT = 16;
        static const int WORLD_HEIGHT = 10;
        static const int WORLD_WIDTH = 10;
    };
} // namespace dnd
#endif