	.cpu cortex-m4
	.arch armv7e-m
	.fpu fpv4-sp-d16
	.eabi_attribute 27, 1
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"hello_world.cpp"
	.text
	.align	1
	.syntax unified
	.thumb
	.thumb_func
	.type	_ZL20__gthread_key_deletei, %function
_ZL20__gthread_key_deletei:
	.fnstart
.LFB178:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	str	r0, [r7, #4]
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	ldr	r7, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_ZL20__gthread_key_deletei, .-_ZL20__gthread_key_deletei
	.bss
	.align	2
_ZStL8__ioinit:
	.space	1
	.size	_ZStL8__ioinit, 1
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Hello world!\000"
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
	.fnstart
.LFB1730:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.save {r7, lr}
	.pad #8
	sub	sp, sp, #8
	.setfp r7, sp, #0
	add	r7, sp, #0
	ldr	r1, .L5
	ldr	r0, .L5+4
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	r3, r0
	ldr	r1, .L5+8
	mov	r0, r3
	bl	_ZNSolsEPFRSoS_E
	bl	_Z4testIiLi10EET_v
	movs	r0, #20
	bl	_ZN5test2ILi20EE7test2FnIjEET_S2_
	movs	r3, #10
	str	r3, [r7, #4]
	ldr	r3, [r7, #4]
	mul	r3, r3, r3
	str	r3, [r7]
	ldr	r3, [r7]
	mov	r0, r3
	adds	r7, r7, #8
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L6:
	.align	2
.L5:
	.word	.LC0
	.word	_ZSt4cout
	.word	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.fnend
	.size	main, .-main
	.section	.text._Z4testIiLi10EET_v,"axG",%progbits,_Z4testIiLi10EET_v,comdat
	.align	1
	.weak	_Z4testIiLi10EET_v
	.syntax unified
	.thumb
	.thumb_func
	.type	_Z4testIiLi10EET_v, %function
_Z4testIiLi10EET_v:
	.fnstart
.LFB1997:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.save {r7, lr}
	.setfp r7, sp, #0
	add	r7, sp, #0
	movs	r1, #10
	ldr	r0, .L9
	bl	_ZNSolsEi
	mov	r3, r0
	ldr	r1, .L9+4
	mov	r0, r3
	bl	_ZNSolsEPFRSoS_E
	movs	r3, #0
	mov	r0, r3
	pop	{r7, pc}
.L10:
	.align	2
.L9:
	.word	_ZSt4cout
	.word	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.fnend
	.size	_Z4testIiLi10EET_v, .-_Z4testIiLi10EET_v
	.section	.text._ZN5test2ILi20EE7test2FnIjEET_S2_,"axG",%progbits,_ZN5test2ILi20EE7test2FnIjEET_S2_,comdat
	.align	1
	.weak	_ZN5test2ILi20EE7test2FnIjEET_S2_
	.syntax unified
	.thumb
	.thumb_func
	.type	_ZN5test2ILi20EE7test2FnIjEET_S2_, %function
_ZN5test2ILi20EE7test2FnIjEET_S2_:
	.fnstart
.LFB1998:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.save {r7, lr}
	.pad #8
	sub	sp, sp, #8
	.setfp r7, sp, #0
	add	r7, sp, #0
	str	r0, [r7, #4]
	movs	r1, #20
	ldr	r0, .L13
	bl	_ZNSolsEi
	mov	r3, r0
	ldr	r1, .L13+4
	mov	r0, r3
	bl	_ZNSolsEPFRSoS_E
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #8
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L14:
	.align	2
.L13:
	.word	_ZSt4cout
	.word	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.fnend
	.size	_ZN5test2ILi20EE7test2FnIjEET_S2_, .-_ZN5test2ILi20EE7test2FnIjEET_S2_
	.text
	.align	1
	.syntax unified
	.thumb
	.thumb_func
	.type	_Z41__static_initialization_and_destruction_0ii, %function
_Z41__static_initialization_and_destruction_0ii:
	.fnstart
.LFB2264:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	ldr	r3, [r7, #4]
	cmp	r3, #1
	bne	.L17
	ldr	r3, [r7]
	movw	r2, #65535
	cmp	r3, r2
	bne	.L17
	ldr	r0, .L18
	bl	_ZNSt8ios_base4InitC1Ev
	ldr	r2, .L18+4
	ldr	r1, .L18+8
	ldr	r0, .L18
	bl	__aeabi_atexit
.L17:
	nop
	adds	r7, r7, #8
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L19:
	.align	2
.L18:
	.word	_ZStL8__ioinit
	.word	__dso_handle
	.word	_ZNSt8ios_base4InitD1Ev
	.cantunwind
	.fnend
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.align	1
	.syntax unified
	.thumb
	.thumb_func
	.type	_GLOBAL__sub_I_main, %function
_GLOBAL__sub_I_main:
	.fnstart
.LFB2265:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	movw	r1, #65535
	movs	r0, #1
	bl	_Z41__static_initialization_and_destruction_0ii
	pop	{r7, pc}
	.cantunwind
	.fnend
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw",%init_array
	.align	2
	.word	_GLOBAL__sub_I_main(target1)
	.hidden	__dso_handle
	.ident	"GCC: (Arm GNU Toolchain 12.2.MPACBTI-Rel1 (Build arm-12-mpacbti.34)) 12.2.1 20230214"
