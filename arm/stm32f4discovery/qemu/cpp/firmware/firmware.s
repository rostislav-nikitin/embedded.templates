	.file	"firmware.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.text
	.globl	main
	.type	main, @function
main:
.LFB1751:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	-1(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4PortIjjLj10EEC1Ev
	leaq	-2(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN13AccessPinTestI3PinIjjLj10ELj0EEE4testEv
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1751:
	.size	main, .-main
	.section	.text._ZN4PortIjjLj10EEC2Ev,"axG",@progbits,_ZN4PortIjjLj10EEC5Ev,comdat
	.align 2
	.weak	_ZN4PortIjjLj10EEC2Ev
	.type	_ZN4PortIjjLj10EEC2Ev, @function
_ZN4PortIjjLj10EEC2Ev:
.LFB1944:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1944:
	.size	_ZN4PortIjjLj10EEC2Ev, .-_ZN4PortIjjLj10EEC2Ev
	.weak	_ZN4PortIjjLj10EEC1Ev
	.set	_ZN4PortIjjLj10EEC1Ev,_ZN4PortIjjLj10EEC2Ev
	.section	.text._ZN13AccessPinTestI3PinIjjLj10ELj0EEE4testEv,"axG",@progbits,_ZN13AccessPinTestI3PinIjjLj10ELj0EEE4testEv,comdat
	.align 2
	.weak	_ZN13AccessPinTestI3PinIjjLj10ELj0EEE4testEv
	.type	_ZN13AccessPinTestI3PinIjjLj10ELj0EEE4testEv, @function
_ZN13AccessPinTestI3PinIjjLj10ELj0EEE4testEv:
.LFB1946:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	call	_ZN3PinIjjLj10ELj0EE3setEv
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1946:
	.size	_ZN13AccessPinTestI3PinIjjLj10ELj0EEE4testEv, .-_ZN13AccessPinTestI3PinIjjLj10ELj0EEE4testEv
	.section	.rodata
	.align 8
.LC0:
	.string	"static void Pin<TAddressType, TValueType, address, bit>::set() [with TAddressType = unsigned int; TValueType = unsigned int; TAddressType address = 10; TValueType bit = 0]"
	.section	.text._ZN3PinIjjLj10ELj0EE3setEv,"axG",@progbits,_ZN3PinIjjLj10ELj0EE3setEv,comdat
	.weak	_ZN3PinIjjLj10ELj0EE3setEv
	.type	_ZN3PinIjjLj10ELj0EE3setEv, @function
_ZN3PinIjjLj10ELj0EE3setEv:
.LFB2004:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2004:
	.size	_ZN3PinIjjLj10ELj0EE3setEv, .-_ZN3PinIjjLj10ELj0EE3setEv
	.ident	"GCC: (GNU) 13.1.1 20230426 (Red Hat 13.1.1-1)"
	.section	.note.GNU-stack,"",@progbits
