	.arch armv7-m
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"test_bis.c"
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	sub	sp, sp, #16
	str	r0, [sp, #4]
	str	r1, [sp]
	movs	r3, #12
	str	r3, [sp, #8]
	movs	r3, #3
	str	r3, [sp, #12]
	ldr	r2, [sp, #8]
	ldr	r3, [sp, #12]
	add	r3, r3, r2
	str	r3, [sp, #8]
	movs	r3, #0
	mov	r0, r3
	add	sp, sp, #16
	@ sp needed
	bx	lr
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",%progbits
