
run:     file format elf64-x86-64


Disassembly of section .init:

0000000000401000 <_init>:
  401000:	f3 0f 1e fa          	endbr64 
  401004:	48 83 ec 08          	sub    $0x8,%rsp
  401008:	48 8b 05 e9 2f 00 00 	mov    0x2fe9(%rip),%rax        # 403ff8 <__gmon_start__>
  40100f:	48 85 c0             	test   %rax,%rax
  401012:	74 02                	je     401016 <_init+0x16>
  401014:	ff d0                	callq  *%rax
  401016:	48 83 c4 08          	add    $0x8,%rsp
  40101a:	c3                   	retq   

Disassembly of section .text:

0000000000401020 <_start>:
  401020:	f3 0f 1e fa          	endbr64 
  401024:	31 ed                	xor    %ebp,%ebp
  401026:	49 89 d1             	mov    %rdx,%r9
  401029:	5e                   	pop    %rsi
  40102a:	48 89 e2             	mov    %rsp,%rdx
  40102d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  401031:	50                   	push   %rax
  401032:	54                   	push   %rsp
  401033:	49 c7 c0 a0 11 40 00 	mov    $0x4011a0,%r8
  40103a:	48 c7 c1 30 11 40 00 	mov    $0x401130,%rcx
  401041:	48 c7 c7 06 11 40 00 	mov    $0x401106,%rdi
  401048:	ff 15 a2 2f 00 00    	callq  *0x2fa2(%rip)        # 403ff0 <__libc_start_main@GLIBC_2.2.5>
  40104e:	f4                   	hlt    
  40104f:	90                   	nop

0000000000401050 <_dl_relocate_static_pie>:
  401050:	f3 0f 1e fa          	endbr64 
  401054:	c3                   	retq   
  401055:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40105c:	00 00 00 
  40105f:	90                   	nop

0000000000401060 <deregister_tm_clones>:
  401060:	b8 28 40 40 00       	mov    $0x404028,%eax
  401065:	48 3d 28 40 40 00    	cmp    $0x404028,%rax
  40106b:	74 13                	je     401080 <deregister_tm_clones+0x20>
  40106d:	b8 00 00 00 00       	mov    $0x0,%eax
  401072:	48 85 c0             	test   %rax,%rax
  401075:	74 09                	je     401080 <deregister_tm_clones+0x20>
  401077:	bf 28 40 40 00       	mov    $0x404028,%edi
  40107c:	ff e0                	jmpq   *%rax
  40107e:	66 90                	xchg   %ax,%ax
  401080:	c3                   	retq   
  401081:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  401088:	00 00 00 00 
  40108c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401090 <register_tm_clones>:
  401090:	be 28 40 40 00       	mov    $0x404028,%esi
  401095:	48 81 ee 28 40 40 00 	sub    $0x404028,%rsi
  40109c:	48 89 f0             	mov    %rsi,%rax
  40109f:	48 c1 ee 3f          	shr    $0x3f,%rsi
  4010a3:	48 c1 f8 03          	sar    $0x3,%rax
  4010a7:	48 01 c6             	add    %rax,%rsi
  4010aa:	48 d1 fe             	sar    %rsi
  4010ad:	74 11                	je     4010c0 <register_tm_clones+0x30>
  4010af:	b8 00 00 00 00       	mov    $0x0,%eax
  4010b4:	48 85 c0             	test   %rax,%rax
  4010b7:	74 07                	je     4010c0 <register_tm_clones+0x30>
  4010b9:	bf 28 40 40 00       	mov    $0x404028,%edi
  4010be:	ff e0                	jmpq   *%rax
  4010c0:	c3                   	retq   
  4010c1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4010c8:	00 00 00 00 
  4010cc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004010d0 <__do_global_dtors_aux>:
  4010d0:	f3 0f 1e fa          	endbr64 
  4010d4:	80 3d 4d 2f 00 00 00 	cmpb   $0x0,0x2f4d(%rip)        # 404028 <__TMC_END__>
  4010db:	75 13                	jne    4010f0 <__do_global_dtors_aux+0x20>
  4010dd:	55                   	push   %rbp
  4010de:	48 89 e5             	mov    %rsp,%rbp
  4010e1:	e8 7a ff ff ff       	callq  401060 <deregister_tm_clones>
  4010e6:	c6 05 3b 2f 00 00 01 	movb   $0x1,0x2f3b(%rip)        # 404028 <__TMC_END__>
  4010ed:	5d                   	pop    %rbp
  4010ee:	c3                   	retq   
  4010ef:	90                   	nop
  4010f0:	c3                   	retq   
  4010f1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4010f8:	00 00 00 00 
  4010fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401100 <frame_dummy>:
  401100:	f3 0f 1e fa          	endbr64 
  401104:	eb 8a                	jmp    401090 <register_tm_clones>

0000000000401106 <main>:
  401106:	f3 0f 1e fa          	endbr64 
  40110a:	55                   	push   %rbp
  40110b:	48 89 e5             	mov    %rsp,%rbp
  40110e:	c7 45 f4 0a 00 00 00 	movl   $0xa,-0xc(%rbp)
  401115:	c7 45 f8 05 00 00 00 	movl   $0x5,-0x8(%rbp)
  40111c:	8b 55 f4             	mov    -0xc(%rbp),%edx
  40111f:	8b 45 f8             	mov    -0x8(%rbp),%eax
  401122:	01 d0                	add    %edx,%eax
  401124:	89 45 fc             	mov    %eax,-0x4(%rbp)
  401127:	83 6d fc 01          	subl   $0x1,-0x4(%rbp)
  40112b:	8b 45 fc             	mov    -0x4(%rbp),%eax
  40112e:	5d                   	pop    %rbp
  40112f:	c3                   	retq   

0000000000401130 <__libc_csu_init>:
  401130:	f3 0f 1e fa          	endbr64 
  401134:	41 57                	push   %r15
  401136:	4c 8d 3d 13 2d 00 00 	lea    0x2d13(%rip),%r15        # 403e50 <__frame_dummy_init_array_entry>
  40113d:	41 56                	push   %r14
  40113f:	49 89 d6             	mov    %rdx,%r14
  401142:	41 55                	push   %r13
  401144:	49 89 f5             	mov    %rsi,%r13
  401147:	41 54                	push   %r12
  401149:	41 89 fc             	mov    %edi,%r12d
  40114c:	55                   	push   %rbp
  40114d:	48 8d 2d 04 2d 00 00 	lea    0x2d04(%rip),%rbp        # 403e58 <__do_global_dtors_aux_fini_array_entry>
  401154:	53                   	push   %rbx
  401155:	4c 29 fd             	sub    %r15,%rbp
  401158:	48 83 ec 08          	sub    $0x8,%rsp
  40115c:	e8 9f fe ff ff       	callq  401000 <_init>
  401161:	48 c1 fd 03          	sar    $0x3,%rbp
  401165:	74 1f                	je     401186 <__libc_csu_init+0x56>
  401167:	31 db                	xor    %ebx,%ebx
  401169:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  401170:	4c 89 f2             	mov    %r14,%rdx
  401173:	4c 89 ee             	mov    %r13,%rsi
  401176:	44 89 e7             	mov    %r12d,%edi
  401179:	41 ff 14 df          	callq  *(%r15,%rbx,8)
  40117d:	48 83 c3 01          	add    $0x1,%rbx
  401181:	48 39 dd             	cmp    %rbx,%rbp
  401184:	75 ea                	jne    401170 <__libc_csu_init+0x40>
  401186:	48 83 c4 08          	add    $0x8,%rsp
  40118a:	5b                   	pop    %rbx
  40118b:	5d                   	pop    %rbp
  40118c:	41 5c                	pop    %r12
  40118e:	41 5d                	pop    %r13
  401190:	41 5e                	pop    %r14
  401192:	41 5f                	pop    %r15
  401194:	c3                   	retq   
  401195:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  40119c:	00 00 00 00 

00000000004011a0 <__libc_csu_fini>:
  4011a0:	f3 0f 1e fa          	endbr64 
  4011a4:	c3                   	retq   

Disassembly of section .fini:

00000000004011a8 <_fini>:
  4011a8:	f3 0f 1e fa          	endbr64 
  4011ac:	48 83 ec 08          	sub    $0x8,%rsp
  4011b0:	48 83 c4 08          	add    $0x8,%rsp
  4011b4:	c3                   	retq   
