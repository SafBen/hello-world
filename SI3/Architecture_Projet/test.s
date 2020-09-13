	.file	"test.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$2, -12(%rbp)
	movl	$10, -8(%rbp)
	movl	$1, -20(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L2
.L3:
	movl	-20(%rbp), %eax
	imull	-12(%rbp), %eax
	movl	%eax, -20(%rbp)
	addl	$1, -16(%rbp)
.L2:
	movl	-16(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L3
	movl	$1, -4(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, -4(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jne	.L4
	movl	$0, %eax
	jmp	.L5
.L4:
	movl	$-1, %eax
.L5:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
