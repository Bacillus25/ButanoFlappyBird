#ifndef BN_SPRITE_ITEMS_PIPEDOWN_H
#define BN_SPRITE_ITEMS_PIPEDOWN_H

#include "bn_sprite_item.h"

//{{BLOCK(pipedown_bn_gfx)

//======================================================================
//
//	pipedown_bn_gfx, 32x64@8, 
//	+ palette 32 entries, not compressed
//	+ 32 tiles Metatiled by 4x8 not compressed
//	Total size: 64 + 2048 = 2112
//
//	Time-stamp: 2025-12-19, 17:17:31
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PIPEDOWN_BN_GFX_H
#define GRIT_PIPEDOWN_BN_GFX_H

#define pipedown_bn_gfxTilesLen 2048
extern const bn::tile pipedown_bn_gfxTiles[64];

#define pipedown_bn_gfxPalLen 64
extern const bn::color pipedown_bn_gfxPal[32];

#endif // GRIT_PIPEDOWN_BN_GFX_H

//}}BLOCK(pipedown_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item pipedown(sprite_shape_size(sprite_shape::TALL, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(pipedown_bn_gfxTiles, 64), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(pipedown_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

