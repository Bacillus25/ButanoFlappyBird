#ifndef BN_SPRITE_ITEMS_BIRD_H
#define BN_SPRITE_ITEMS_BIRD_H

#include "bn_sprite_item.h"

//{{BLOCK(bird_bn_gfx)

//======================================================================
//
//	bird_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2026-01-13, 11:49:09
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BIRD_BN_GFX_H
#define GRIT_BIRD_BN_GFX_H

#define bird_bn_gfxTilesLen 128
extern const bn::tile bird_bn_gfxTiles[4];

#define bird_bn_gfxPalLen 32
extern const bn::color bird_bn_gfxPal[16];

#endif // GRIT_BIRD_BN_GFX_H

//}}BLOCK(bird_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item bird(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(bird_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(bird_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

