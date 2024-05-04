#ifndef BN_SPRITE_ITEMS_WORLD_H
#define BN_SPRITE_ITEMS_WORLD_H

#include "bn_sprite_item.h"

//{{BLOCK(world_bn_gfx)

//======================================================================
//
//	world_bn_gfx, 16x3520@4, 
//	+ palette 16 entries, not compressed
//	+ 880 tiles not compressed
//	Total size: 32 + 28160 = 28192
//
//	Time-stamp: 2024-04-22, 01:20:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WORLD_BN_GFX_H
#define GRIT_WORLD_BN_GFX_H

#define world_bn_gfxTilesLen 28160
extern const bn::tile world_bn_gfxTiles[880];

#define world_bn_gfxPalLen 32
extern const bn::color world_bn_gfxPal[16];

#endif // GRIT_WORLD_BN_GFX_H

//}}BLOCK(world_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item world(sprite_shape_size(sprite_shape::TALL, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(world_bn_gfxTiles, 880), bpp_mode::BPP_4, compression_type::NONE, 110), 
            sprite_palette_item(span<const color>(world_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

