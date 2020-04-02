	.file	"a4q2b.c"
	.text
	.p2align 4
	.globl	gcd
	.type	gcd, @function
gcd:
.LFB13:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	movq	%rsi, %r8
	testq	%rsi, %rsi
	jg	.L2
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L8:
	movq	%rdx, %r8
.L2:
	cqto
	idivq	%r8
	movq	%r8, %rax
	testq	%rdx, %rdx
	jg	.L8
	movq	%r8, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L7:
	movq	%rdi, %r8
	movq	%r8, %rax
	ret
	.cfi_endproc
.LFE13:
	.size	gcd, .-gcd
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Enter the two numbers whose gcd you want to find:\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%ld"
.LC2:
	.string	"GCD of %ld, %ld is %ld\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB14:
	.cfi_startproc
	endbr64
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	8(%rsp), %rsi
	leaq	.LC1(%rip), %rdi
	xorl	%eax, %eax
	call	__isoc99_scanf@PLT
	leaq	16(%rsp), %rsi
	leaq	.LC1(%rip), %rdi
	xorl	%eax, %eax
	call	__isoc99_scanf@PLT
	movq	16(%rsp), %rcx
	movq	8(%rsp), %r9
	movq	%rcx, %r8
	movq	%r9, %rax
	testq	%rcx, %rcx
	jg	.L10
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L19:
	movq	%rdx, %r8
.L10:
	cqto
	idivq	%r8
	movq	%r8, %rax
	testq	%rdx, %rdx
	jg	.L19
.L11:
	xorl	%eax, %eax
	movq	%r9, %rdx
	movl	$1, %edi
	leaq	.LC2(%rip), %rsi
	call	__printf_chk@PLT
	movq	24(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L20
	xorl	%eax, %eax
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L18:
	.cfi_restore_state
	movq	%r9, %r8
	jmp	.L11
.L20:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE14:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
