#ifndef BN_REGULAR_BG_ITEMS_OVERWORLD_H
#define BN_REGULAR_BG_ITEMS_OVERWORLD_H

#include "bn_regular_bg_item.h"

//{{BLOCK(overworld_bn_gfx)

//======================================================================
//
//	overworld_bn_gfx, 512x256@8, 
//	+ palette 256 entries, not compressed
//	+ 849 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 54336 + 4096 = 58944
//
//	Time-stamp: 2024-04-22, 01:20:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_OVERWORLD_BN_GFX_H
#define GRIT_OVERWORLD_BN_GFX_H

#define overworld_bn_gfxTilesLen 54336
extern const bn::tile overworld_bn_gfxTiles[1698];

#define overworld_bn_gfxMapLen 4096
extern const bn::regular_bg_map_cell overworld_bn_gfxMap[2048];

#define overworld_bn_gfxPalLen 512
extern const bn::color overworld_bn_gfxPal[256];

#endif // GRIT_OVERWORLD_BN_GFX_H

//}}BLOCK(overworld_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item overworld(
            regular_bg_tiles_item(span<const tile>(overworld_bn_gfxTiles, 1698), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(overworld_bn_gfxPal, 256), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(overworld_bn_gfxMap[0], size(64, 32), compression_type::NONE, 1, false));
}

#endif

