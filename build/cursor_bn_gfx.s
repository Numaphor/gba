
@{{BLOCK(cursor_bn_gfx)

@=======================================================================
@
@	cursor_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2024-04-22, 01:20:41
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global cursor_bn_gfxTiles		@ 128 unsigned chars
	.hidden cursor_bn_gfxTiles
cursor_bn_gfxTiles:
	.word 0x44000000,0x11440000,0x00114400,0x00001144,0x00004411,0x00441100,0x44110000,0x11000000
	.word 0x00000044,0x00004411,0x00441100,0x44110000,0x11440000,0x00114400,0x00001144,0x00000011
	.word 0x33000000,0x22330000,0x00223300,0x00002233,0x00003322,0x00332200,0x33220000,0x22000000
	.word 0x00000033,0x00003322,0x00332200,0x33220000,0x22330000,0x00223300,0x00002233,0x00000022

	.section .rodata
	.align	2
	.global cursor_bn_gfxPal		@ 32 unsigned chars
	.hidden cursor_bn_gfxPal
cursor_bn_gfxPal:
	.hword 0x0000,0x1463,0x2D8C,0x3B5F,0x7398,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(cursor_bn_gfx)
