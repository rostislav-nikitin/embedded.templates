.thumb
.syntax unified

.global _startup

_startup:
	ldr sp, =stack_top
	bl init
	bl main
	b .
