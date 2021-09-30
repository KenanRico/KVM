
run:     file format elf64-x86-64


Disassembly of section .text:

0000000000401000 <_start>:
  401000:	48 31 c0             	xor    %rax,%rax
  401003:	31 c0                	xor    %eax,%eax
  401005:	48 31 c8             	xor    %rcx,%rax
  401008:	48 31 d0             	xor    %rdx,%rax
  40100b:	48 31 c5             	xor    %rax,%rbp
  40100e:	48 31 cd             	xor    %rcx,%rbp
  401011:	48 31 d5             	xor    %rdx,%rbp
  401014:	48 c7 c0 00 00 00 00 	mov    $0x0,%rax
  40101b:	48 c7 c0 01 00 00 00 	mov    $0x1,%rax
  401022:	48 c7 c3 00 00 00 00 	mov    $0x0,%rbx
  401029:	48 c7 c3 01 00 00 00 	mov    $0x1,%rbx
  401030:	cd 80                	int    $0x80


11 000 000
11 001 000
