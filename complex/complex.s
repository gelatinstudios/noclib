	.file	"complex.c"
	.text
	.globl	square_root
	.type	square_root, @function
square_root:
.LFB503:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movss	%xmm0, -68(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movss	-68(%rbp), %xmm0
	movss	%xmm0, -52(%rbp)
	movss	-52(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	movss	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	movaps	%xmm0, -32(%rbp)
	movaps	-32(%rbp), %xmm0
	sqrtss	-32(%rbp), %xmm0
	movaps	%xmm0, -48(%rbp)
	movss	-48(%rbp), %xmm0
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE503:
	.size	square_root, .-square_root
	.globl	print_str
	.type	print_str, @function
print_str:
.LFB504:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE504:
	.size	print_str, .-print_str
	.globl	read_float
	.type	read_float, @function
read_float:
.LFB505:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$272, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-272(%rbp), %rdx
	movl	$0, %eax
	movl	$32, %ecx
	movq	%rdx, %rdi
	rep stosq
	leaq	-272(%rbp), %rax
	movl	$256, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read@PLT
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE505:
	.size	read_float, .-read_float
	.section	.rodata
.LC0:
	.string	"y = ax^2 + bx + c\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB506:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$21, %esi
	leaq	.LC0(%rip), %rdi
	call	print_str
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE506:
	.size	main, .-main
	.ident	"GCC: (Gentoo 8.3.0-r1 p1.1) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
