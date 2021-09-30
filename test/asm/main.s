.section .data

.section .text
.global _start

_start:
	xor %rax, %rax
	xor %eax, %eax
	xor %rcx, %rax
	xor %rdx, %rax
	xor %rax, %rbp
	xor %rcx, %rbp
	xor %rdx, %rbp
	mov $0, %rax
	mov $1, %rax
	mov $0, %rbx
	mov $1, %rbx
	int $0x80
