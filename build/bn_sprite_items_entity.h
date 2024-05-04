#ifndef BN_SPRITE_ITEMS_ENTITY_H
#define BN_SPRITE_ITEMS_ENTITY_H

#include "bn_sprite_item.h"

//{{BLOCK(entity_bn_gfx)

//======================================================================
//
//	entity_bn_gfx, 16x2112@4, 
//	+ palette 16 entries, not compressed
//	+ 528 tiles not compressed
//	Total size: 32 + 16896 = 16928
//
//	Time-stamp: 2024-04-22, 01:20:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ENTITY_BN_GFX_H
#define GRIT_ENTITY_BN_GFX_H

#define entity_bn_gfxTilesLen 16896
extern const bn::tile entity_bn_gfxTiles[528];

#define entity_bn_gfxPalLen 32
extern const bn::color entity_bn_gfxPal[16];

#endif // GRIT_ENTITY_BN_GFX_H

//}}BLOCK(entity_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item entity(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(entity_bn_gfxTiles, 528), bpp_mode::BPP_4, compression_type::NONE, 132), 
            sprite_palette_item(span<const color>(entity_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

