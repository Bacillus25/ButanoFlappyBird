
@{{BLOCK(bird_bn_gfx)

@=======================================================================
@
@	bird_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-01-13, 11:49:09
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bird_bn_gfxTiles		@ 128 unsigned chars
	.hidden bird_bn_gfxTiles
bird_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x55500000,0x22250000,0x23325000,0x33555555,0x35111115
	.word 0x00000000,0x00000000,0x00000000,0x00005555,0x00051115,0x00515115,0x00515125,0x00511253
	.word 0x35125555,0x35222250,0x33555500,0x33350000,0x55500000,0x00000000,0x00000000,0x00000000
	.word 0x05555533,0x51122253,0x05555235,0x05222353,0x00555505,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global bird_bn_gfxPal		@ 32 unsigned chars
	.hidden bird_bn_gfxPal
bird_bn_gfxPal:
	.hword 0x03E0,0x67FC,0x371F,0x29BD,0x7FFF,0x0007,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(bird_bn_gfx)
