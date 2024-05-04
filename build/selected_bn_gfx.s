
@{{BLOCK(selected_bn_gfx)

@=======================================================================
@
@	selected_bn_gfx, 16x8@4, 
@	+ palette 16 entries, not compressed
@	+ 2 tiles not compressed
@	Total size: 32 + 64 = 96
@
@	Time-stamp: 2024-04-22, 01:20:41
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global selected_bn_gfxTiles		@ 64 unsigned chars
	.hidden selected_bn_gfxTiles
selected_bn_gfxTiles:
	.word 0x11000000,0x11110000,0x11111100,0x11111111,0x11111111,0x11111100,0x11110000,0x11000000
	.word 0x00000011,0x00001111,0x00111111,0x11111111,0x11111111,0x00111111,0x00001111,0x00000011

	.section .rodata
	.align	2
	.global selected_bn_gfxPal		@ 32 unsigned chars
	.hidden selected_bn_gfxPal
selected_bn_gfxPal:
	.hword 0x0000,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(selected_bn_gfx)
