#ifndef BN_SPRITE_ITEMS_SELECTED_H
#define BN_SPRITE_ITEMS_SELECTED_H

#include "bn_sprite_item.h"

//{{BLOCK(selected_bn_gfx)

//======================================================================
//
//	selected_bn_gfx, 16x8@4, 
//	+ palette 16 entries, not compressed
//	+ 2 tiles not compressed
//	Total size: 32 + 64 = 96
//
//	Time-stamp: 2024-04-22, 01:20:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SELECTED_BN_GFX_H
#define GRIT_SELECTED_BN_GFX_H

#define selected_bn_gfxTilesLen 64
extern const bn::tile selected_bn_gfxTiles[2];

#define selected_bn_gfxPalLen 32
extern const bn::color selected_bn_gfxPal[16];

#endif // GRIT_SELECTED_BN_GFX_H

//}}BLOCK(selected_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item selected(sprite_shape_size(sprite_shape::WIDE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(selected_bn_gfxTiles, 2), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(selected_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

