
/workspace/work/tm_bypass_research/extracted/TM-BYPASSv4.0/vendor/irestores.exe:     file format pei-x86-64


Disassembly of section .text:

0000000140134400 <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase>:
   140134400:	4c 8d 64 24 d8       	lea    -0x28(%rsp),%r12
   140134405:	4d 3b 66 10          	cmp    0x10(%r14),%r12
   140134409:	0f 86 a8 02 00 00    	jbe    1401346b7 <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x2b7>
   14013440f:	55                   	push   %rbp
   140134410:	48 89 e5             	mov    %rsp,%rbp
   140134413:	48 81 ec a0 00 00 00 	sub    $0xa0,%rsp
   14013441a:	48 89 9c 24 b8 00 00 	mov    %rbx,0xb8(%rsp)
   140134421:	00 
   140134422:	48 89 bc 24 c8 00 00 	mov    %rdi,0xc8(%rsp)
   140134429:	00 
   14013442a:	90                   	nop
   14013442b:	48 83 fe 03          	cmp    $0x3,%rsi
   14013442f:	0f 86 74 02 00 00    	jbe    1401346a9 <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x2a9>
   140134435:	8b 17                	mov    (%rdi),%edx
   140134437:	4c 8b 88 f8 00 00 00 	mov    0xf8(%rax),%r9
   14013443e:	4c 8b 90 00 01 00 00 	mov    0x100(%rax),%r10
   140134445:	31 c0                	xor    %eax,%eax
   140134447:	eb 03                	jmp    14013444c <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x4c>
   140134449:	48 ff c0             	inc    %rax
   14013444c:	4c 39 d0             	cmp    %r10,%rax
   14013444f:	7d 18                	jge    140134469 <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x69>
   140134451:	4d 8b 1c c1          	mov    (%r9,%rax,8),%r11
   140134455:	41 39 53 18          	cmp    %edx,0x18(%r11)
   140134459:	75 ee                	jne    140134449 <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x49>
   14013445b:	4d 8b 4b 48          	mov    0x48(%r11),%r9
   14013445f:	4d 8b 53 50          	mov    0x50(%r11),%r10
   140134463:	4d 8b 5b 40          	mov    0x40(%r11),%r11
   140134467:	eb 09                	jmp    140134472 <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x72>
   140134469:	45 31 db             	xor    %r11d,%r11d
   14013446c:	45 31 d2             	xor    %r10d,%r10d
   14013446f:	45 31 c9             	xor    %r9d,%r9d
   140134472:	4d 85 db             	test   %r11,%r11
   140134475:	0f 84 d3 01 00 00    	je     14013464e <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x24e>
   14013447b:	48 89 8c 24 c0 00 00 	mov    %rcx,0xc0(%rsp)
   140134482:	00 
   140134483:	48 89 9c 24 b8 00 00 	mov    %rbx,0xb8(%rsp)
   14013448a:	00 
   14013448b:	49 83 c0 fc          	add    $0xfffffffffffffffc,%r8
   14013448f:	4c 89 c2             	mov    %r8,%rdx
   140134492:	48 f7 da             	neg    %rdx
   140134495:	48 c1 fa 3f          	sar    $0x3f,%rdx
   140134499:	83 e2 04             	and    $0x4,%edx
   14013449c:	48 01 d7             	add    %rdx,%rdi
   14013449f:	48 83 c6 fc          	add    $0xfffffffffffffffc,%rsi
   1401344a3:	4c 89 d8             	mov    %r11,%rax
   1401344a6:	4c 89 cb             	mov    %r9,%rbx
   1401344a9:	4c 89 d1             	mov    %r10,%rcx
   1401344ac:	e8 cf 7e fd ff       	call   14010c380 <github.com/dnicolson/irestore/crypto/aeswrap.Unwrap>
   1401344b1:	48 89 44 24 60       	mov    %rax,0x60(%rsp)
   1401344b6:	48 89 5c 24 48       	mov    %rbx,0x48(%rsp)
   1401344bb:	48 89 4c 24 50       	mov    %rcx,0x50(%rsp)
   1401344c0:	44 0f 11 7c 24 70    	movups %xmm15,0x70(%rsp)
   1401344c6:	44 0f 11 bc 24 80 00 	movups %xmm15,0x80(%rsp)
   1401344cd:	00 00 
   1401344cf:	48 8d 15 8a 44 13 00 	lea    0x13448a(%rip),%rdx        # 140268960 <type:*+0xf960>
   1401344d6:	48 89 54 24 70       	mov    %rdx,0x70(%rsp)
   1401344db:	48 8d 15 de 04 1a 00 	lea    0x1a04de(%rip),%rdx        # 1402d49c0 <github.com/dnicolson/irestore/backup..stmp_9>
   1401344e2:	48 89 54 24 78       	mov    %rdx,0x78(%rsp)
   1401344e7:	e8 94 85 ed ff       	call   14000ca80 <runtime.convTslice>
   1401344ec:	48 8d 15 2d 2f 13 00 	lea    0x132f2d(%rip),%rdx        # 140267420 <type:*+0xe420>
   1401344f3:	48 89 94 24 80 00 00 	mov    %rdx,0x80(%rsp)
   1401344fa:	00 
   1401344fb:	48 89 84 24 88 00 00 	mov    %rax,0x88(%rsp)
   140134502:	00 
   140134503:	48 8b 1d ae 9b 2a 00 	mov    0x2a9bae(%rip),%rbx        # 1403de0b8 <os.Stdout>
   14013450a:	48 8d 05 2f 0e 1a 00 	lea    0x1a0e2f(%rip),%rax        # 1402d5340 <go:itab.*os.File,io.Writer>
   140134511:	48 8d 4c 24 70       	lea    0x70(%rsp),%rcx
   140134516:	bf 02 00 00 00       	mov    $0x2,%edi
   14013451b:	48 89 fe             	mov    %rdi,%rsi
   14013451e:	66 90                	xchg   %ax,%ax
   140134520:	e8 bb d4 f9 ff       	call   1400d19e0 <fmt.Fprintln>
   140134525:	90                   	nop
   140134526:	48 8b 84 24 b8 00 00 	mov    0xb8(%rsp),%rax
   14013452d:	00 
   14013452e:	48 8b 9c 24 c0 00 00 	mov    0xc0(%rsp),%rbx
   140134535:	00 
   140134536:	e8 a5 63 f9 ff       	call   1400ca8e0 <os.ReadFile>
   14013453b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
   140134540:	48 85 ff             	test   %rdi,%rdi
   140134543:	0f 85 f2 00 00 00    	jne    14013463b <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x23b>
   140134549:	48 89 4c 24 40       	mov    %rcx,0x40(%rsp)
   14013454e:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
   140134553:	48 89 5c 24 38       	mov    %rbx,0x38(%rsp)
   140134558:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
   14013455d:	48 8b 5c 24 48       	mov    0x48(%rsp),%rbx
   140134562:	48 8b 4c 24 50       	mov    0x50(%rsp),%rcx
   140134567:	e8 34 53 fc ff       	call   1400f98a0 <crypto/aes.NewCipher>
   14013456c:	48 85 c9             	test   %rcx,%rcx
   14013456f:	0f 85 b9 00 00 00    	jne    14013462e <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x22e>
   140134575:	48 8b 0d 14 92 11 00 	mov    0x119214(%rip),%rcx        # 14024d790 <github.com/dnicolson/irestore/backup.zeroiv>
   14013457c:	48 8b 3d 15 92 11 00 	mov    0x119215(%rip),%rdi        # 14024d798 <github.com/dnicolson/irestore/backup.zeroiv+0x8>
   140134583:	48 8b 35 16 92 11 00 	mov    0x119216(%rip),%rsi        # 14024d7a0 <github.com/dnicolson/irestore/backup.zeroiv+0x10>
   14013458a:	e8 31 3c fc ff       	call   1400f81c0 <crypto/cipher.NewCBCDecrypter>
   14013458f:	48 8b 50 20          	mov    0x20(%rax),%rdx
   140134593:	48 89 d8             	mov    %rbx,%rax
   140134596:	48 8b 5c 24 58       	mov    0x58(%rsp),%rbx
   14013459b:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
   1401345a0:	48 8b 7c 24 40       	mov    0x40(%rsp),%rdi
   1401345a5:	48 89 de             	mov    %rbx,%rsi
   1401345a8:	49 89 c8             	mov    %rcx,%r8
   1401345ab:	49 89 f9             	mov    %rdi,%r9
   1401345ae:	ff d2                	call   *%rdx
   1401345b0:	90                   	nop
   1401345b1:	31 c0                	xor    %eax,%eax
   1401345b3:	31 db                	xor    %ebx,%ebx
   1401345b5:	48 8d 0d 82 0a 16 00 	lea    0x160a82(%rip),%rcx        # 14029503e <go:string.*+0x26>
   1401345bc:	bf 02 00 00 00       	mov    $0x2,%edi
   1401345c1:	e8 3a 8a f9 ff       	call   1400cd000 <os.CreateTemp>
   1401345c6:	48 85 db             	test   %rbx,%rbx
   1401345c9:	75 50                	jne    14013461b <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x21b>
   1401345cb:	48 89 44 24 68       	mov    %rax,0x68(%rsp)
   1401345d0:	48 8b 5c 24 58       	mov    0x58(%rsp),%rbx
   1401345d5:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
   1401345da:	48 8b 7c 24 40       	mov    0x40(%rsp),%rdi
   1401345df:	90                   	nop
   1401345e0:	e8 1b 5b f9 ff       	call   1400ca100 <os.(*File).Write>
   1401345e5:	90                   	nop
   1401345e6:	48 8b 54 24 68       	mov    0x68(%rsp),%rdx
   1401345eb:	48 85 d2             	test   %rdx,%rdx
   1401345ee:	74 0d                	je     1401345fd <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase+0x1fd>
   1401345f0:	48 8b 02             	mov    (%rdx),%rax
   1401345f3:	e8 a8 6c f9 ff       	call   1400cb2a0 <os.(*file).close>
   1401345f8:	48 8b 54 24 68       	mov    0x68(%rsp),%rdx
   1401345fd:	48 8b 12             	mov    (%rdx),%rdx
   140134600:	48 8b 82 28 02 00 00 	mov    0x228(%rdx),%rax
   140134607:	48 8b 9a 30 02 00 00 	mov    0x230(%rdx),%rbx
   14013460e:	31 c9                	xor    %ecx,%ecx
   140134610:	31 ff                	xor    %edi,%edi
   140134612:	48 81 c4 a0 00 00 00 	add    $0xa0,%rsp
   140134619:	5d                   	pop    %rbp
   14013461a:	c3                   	ret
   14013461b:	31 c0                	xor    %eax,%eax
   14013461d:	48 89 cf             	mov    %rcx,%rdi
   140134620:	48 89 d9             	mov    %rbx,%rcx
   140134623:	31 db                	xor    %ebx,%ebx
   140134625:	48 81 c4 a0 00 00 00 	add    $0xa0,%rsp
   14013462c:	5d                   	pop    %rbp
   14013462d:	c3                   	ret
   14013462e:	31 c0                	xor    %eax,%eax
   140134630:	31 db                	xor    %ebx,%ebx
   140134632:	48 81 c4 a0 00 00 00 	add    $0xa0,%rsp
   140134639:	5d                   	pop    %rbp
   14013463a:	c3                   	ret
   14013463b:	31 c0                	xor    %eax,%eax
   14013463d:	31 db                	xor    %ebx,%ebx
   14013463f:	48 89 f9             	mov    %rdi,%rcx
   140134642:	48 89 f7             	mov    %rsi,%rdi
   140134645:	48 81 c4 a0 00 00 00 	add    $0xa0,%rsp
   14013464c:	5d                   	pop    %rbp
   14013464d:	c3                   	ret
   14013464e:	44 0f 11 bc 24 90 00 	movups %xmm15,0x90(%rsp)
   140134655:	00 00 
   140134657:	89 d0                	mov    %edx,%eax
   140134659:	e8 a2 82 ed ff       	call   14000c900 <runtime.convT32>
   14013465e:	48 8d 0d 7b 44 13 00 	lea    0x13447b(%rip),%rcx        # 140268ae0 <type:*+0xfae0>
   140134665:	48 89 8c 24 90 00 00 	mov    %rcx,0x90(%rsp)
   14013466c:	00 
   14013466d:	48 89 84 24 98 00 00 	mov    %rax,0x98(%rsp)
   140134674:	00 
   140134675:	48 8d 05 82 76 16 00 	lea    0x167682(%rip),%rax        # 14029bcfe <go:string.*+0x6ce6>
   14013467c:	bb 1c 00 00 00       	mov    $0x1c,%ebx
   140134681:	48 8d 8c 24 90 00 00 	lea    0x90(%rsp),%rcx
   140134688:	00 
   140134689:	bf 01 00 00 00       	mov    $0x1,%edi
   14013468e:	48 89 fe             	mov    %rdi,%rsi
   140134691:	e8 8a a2 f9 ff       	call   1400ce920 <fmt.Errorf>
   140134696:	48 89 c1             	mov    %rax,%rcx
   140134699:	48 89 df             	mov    %rbx,%rdi
   14013469c:	31 c0                	xor    %eax,%eax
   14013469e:	31 db                	xor    %ebx,%ebx
   1401346a0:	48 81 c4 a0 00 00 00 	add    $0xa0,%rsp
   1401346a7:	5d                   	pop    %rbp
   1401346a8:	c3                   	ret
   1401346a9:	b8 03 00 00 00       	mov    $0x3,%eax
   1401346ae:	48 89 f1             	mov    %rsi,%rcx
   1401346b1:	e8 4a 7a f3 ff       	call   14006c100 <runtime.panicIndex>
   1401346b6:	90                   	nop
   1401346b7:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
   1401346bc:	48 89 5c 24 10       	mov    %rbx,0x10(%rsp)
   1401346c1:	48 89 4c 24 18       	mov    %rcx,0x18(%rsp)
   1401346c6:	48 89 7c 24 20       	mov    %rdi,0x20(%rsp)
   1401346cb:	48 89 74 24 28       	mov    %rsi,0x28(%rsp)
   1401346d0:	4c 89 44 24 30       	mov    %r8,0x30(%rsp)
   1401346d5:	e8 26 57 f3 ff       	call   140069e00 <runtime.morestack_noctxt.abi0>
   1401346da:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
   1401346df:	48 8b 5c 24 10       	mov    0x10(%rsp),%rbx
   1401346e4:	48 8b 4c 24 18       	mov    0x18(%rsp),%rcx
   1401346e9:	48 8b 7c 24 20       	mov    0x20(%rsp),%rdi
   1401346ee:	48 8b 74 24 28       	mov    0x28(%rsp),%rsi
   1401346f3:	4c 8b 44 24 30       	mov    0x30(%rsp),%r8
   1401346f8:	e9 03 fd ff ff       	jmp    140134400 <github.com/dnicolson/irestore/backup.(*MobileBackup).decryptDatabase>
   1401346fd:	cc                   	int3
   1401346fe:	cc                   	int3
   1401346ff:	cc                   	int3
