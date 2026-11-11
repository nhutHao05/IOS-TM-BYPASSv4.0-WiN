
/workspace/work/tm_bypass_research/extracted/TM-BYPASSv4.0/vendor/irestores.exe:     file format pei-x86-64


Disassembly of section .text:

0000000140134000 <github.com/dnicolson/irestore/backup.Open>:
   140134000:	4c 8d a4 24 d0 fe ff 	lea    -0x130(%rsp),%r12
   140134007:	ff 
   140134008:	4d 3b 66 10          	cmp    0x10(%r14),%r12
   14013400c:	0f 86 0d 03 00 00    	jbe    14013431f <github.com/dnicolson/irestore/backup.Open+0x31f>
   140134012:	55                   	push   %rbp
   140134013:	48 89 e5             	mov    %rsp,%rbp
   140134016:	48 81 ec a8 01 00 00 	sub    $0x1a8,%rsp
   14013401d:	66 44 0f d6 bc 24 a0 	movq   %xmm15,0x1a0(%rsp)
   140134024:	01 00 00 
   140134027:	48 89 9c 24 c0 01 00 	mov    %rbx,0x1c0(%rsp)
   14013402e:	00 
   14013402f:	48 89 84 24 b8 01 00 	mov    %rax,0x1b8(%rsp)
   140134036:	00 
   140134037:	c6 84 24 b7 00 00 00 	movb   $0x0,0xb7(%rsp)
   14013403e:	00 
   14013403f:	48 c7 84 24 c8 00 00 	movq   $0x0,0xc8(%rsp)
   140134046:	00 00 00 00 00 
   14013404b:	44 0f 11 bc 24 b8 00 	movups %xmm15,0xb8(%rsp)
   140134052:	00 00 
   140134054:	48 8d 05 45 20 15 00 	lea    0x152045(%rip),%rax        # 1402860a0 <type:*+0x2d0a0>
   14013405b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
   140134060:	e8 9b b8 ed ff       	call   14000f900 <runtime.newobject>
   140134065:	48 8b 8c 24 c0 01 00 	mov    0x1c0(%rsp),%rcx
   14013406c:	00 
   14013406d:	48 89 48 08          	mov    %rcx,0x8(%rax)
   140134071:	83 3d c8 01 33 00 00 	cmpl   $0x0,0x3301c8(%rip)        # 140464240 <runtime.writeBarrier>
   140134078:	75 0a                	jne    140134084 <github.com/dnicolson/irestore/backup.Open+0x84>
   14013407a:	48 8b 94 24 b8 01 00 	mov    0x1b8(%rsp),%rdx
   140134081:	00 
   140134082:	eb 10                	jmp    140134094 <github.com/dnicolson/irestore/backup.Open+0x94>
   140134084:	e8 b7 7c f3 ff       	call   14006bd40 <runtime.gcWriteBarrier1>
   140134089:	48 8b 94 24 b8 01 00 	mov    0x1b8(%rsp),%rdx
   140134090:	00 
   140134091:	49 89 13             	mov    %rdx,(%r11)
   140134094:	48 89 84 24 98 01 00 	mov    %rax,0x198(%rsp)
   14013409b:	00 
   14013409c:	48 89 10             	mov    %rdx,(%rax)
   14013409f:	44 0f 11 bc 24 78 01 	movups %xmm15,0x178(%rsp)
   1401340a6:	00 00 
   1401340a8:	44 0f 11 bc 24 88 01 	movups %xmm15,0x188(%rsp)
   1401340af:	00 00 
   1401340b1:	48 8b 10             	mov    (%rax),%rdx
   1401340b4:	48 8b 70 08          	mov    0x8(%rax),%rsi
   1401340b8:	48 89 b4 24 80 01 00 	mov    %rsi,0x180(%rsp)
   1401340bf:	00 
   1401340c0:	48 89 94 24 78 01 00 	mov    %rdx,0x178(%rsp)
   1401340c7:	00 
   1401340c8:	48 c7 84 24 90 01 00 	movq   $0xe,0x190(%rsp)
   1401340cf:	00 0e 00 00 00 
   1401340d4:	48 8d 15 0f 2e 16 00 	lea    0x162e0f(%rip),%rdx        # 140296eea <go:string.*+0x1ed2>
   1401340db:	48 89 94 24 88 01 00 	mov    %rdx,0x188(%rsp)
   1401340e2:	00 
   1401340e3:	bb 02 00 00 00       	mov    $0x2,%ebx
   1401340e8:	48 89 d9             	mov    %rbx,%rcx
   1401340eb:	48 8d 84 24 78 01 00 	lea    0x178(%rsp),%rax
   1401340f2:	00 
   1401340f3:	e8 a8 00 f9 ff       	call   1400c41a0 <path.Join>
   1401340f8:	90                   	nop
   1401340f9:	31 c9                	xor    %ecx,%ecx
   1401340fb:	31 ff                	xor    %edi,%edi
   1401340fd:	0f 1f 00             	nopl   (%rax)
   140134100:	e8 fb 64 f9 ff       	call   1400ca600 <os.OpenFile>
   140134105:	48 85 db             	test   %rbx,%rbx
   140134108:	0f 85 be 01 00 00    	jne    1401342cc <github.com/dnicolson/irestore/backup.Open+0x2cc>
   14013410e:	44 0f 11 bc 24 d0 00 	movups %xmm15,0xd0(%rsp)
   140134115:	00 00 
   140134117:	48 8d 15 22 02 00 00 	lea    0x222(%rip),%rdx        # 140134340 <github.com/dnicolson/irestore/backup.Open.deferwrap1>
   14013411e:	48 89 94 24 d0 00 00 	mov    %rdx,0xd0(%rsp)
   140134125:	00 
   140134126:	48 89 84 24 d8 00 00 	mov    %rax,0xd8(%rsp)
   14013412d:	00 
   14013412e:	48 8d 94 24 d0 00 00 	lea    0xd0(%rsp),%rdx
   140134135:	00 
   140134136:	48 89 94 24 a0 01 00 	mov    %rdx,0x1a0(%rsp)
   14013413d:	00 
   14013413e:	c6 84 24 b7 00 00 00 	movb   $0x1,0xb7(%rsp)
   140134145:	01 
   140134146:	48 8b bc 24 98 01 00 	mov    0x198(%rsp),%rdi
   14013414d:	00 
   14013414e:	48 8d 57 10          	lea    0x10(%rdi),%rdx
   140134152:	48 89 c3             	mov    %rax,%rbx
   140134155:	48 8d 0d 04 fb 12 00 	lea    0x12fb04(%rip),%rcx        # 140263c60 <type:*+0xac60>
   14013415c:	48 8d 05 fd 16 1a 00 	lea    0x1a16fd(%rip),%rax        # 1402d5860 <go:itab.*os.File,io.ReadSeeker>
   140134163:	48 89 d7             	mov    %rdx,%rdi
   140134166:	e8 b5 0d fe ff       	call   140114f20 <github.com/dunhamsteve/plist.Unmarshal>
   14013416b:	48 85 c0             	test   %rax,%rax
   14013416e:	0f 85 06 01 00 00    	jne    14013427a <github.com/dnicolson/irestore/backup.Open+0x27a>
   140134174:	48 8b 94 24 98 01 00 	mov    0x198(%rsp),%rdx
   14013417b:	00 
   14013417c:	48 8b 42 10          	mov    0x10(%rdx),%rax
   140134180:	48 8b 5a 18          	mov    0x18(%rdx),%rbx
   140134184:	48 8b 4a 20          	mov    0x20(%rdx),%rcx
   140134188:	e8 93 de fd ff       	call   140112020 <github.com/dnicolson/irestore/keybag.Read>
   14013418d:	48 8b 14 24          	mov    (%rsp),%rdx
   140134191:	48 89 94 24 e0 00 00 	mov    %rdx,0xe0(%rsp)
   140134198:	00 
   140134199:	48 8d bc 24 e8 00 00 	lea    0xe8(%rsp),%rdi
   1401341a0:	00 
   1401341a1:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
   1401341a6:	48 89 6c 24 f0       	mov    %rbp,-0x10(%rsp)
   1401341ab:	48 8d 6c 24 f0       	lea    -0x10(%rsp),%rbp
   1401341b0:	e8 4d 85 f3 ff       	call   14006c702 <runtime.duffcopy+0x302>
   1401341b5:	48 8b 6d 00          	mov    0x0(%rbp),%rbp
   1401341b9:	83 3d 80 00 33 00 00 	cmpl   $0x0,0x330080(%rip)        # 140464240 <runtime.writeBarrier>
   1401341c0:	74 23                	je     1401341e5 <github.com/dnicolson/irestore/backup.Open+0x1e5>
   1401341c2:	48 8b 9c 24 98 01 00 	mov    0x198(%rsp),%rbx
   1401341c9:	00 
   1401341ca:	48 8d 53 78          	lea    0x78(%rbx),%rdx
   1401341ce:	48 8d 05 2b 6f 15 00 	lea    0x156f2b(%rip),%rax        # 14028b100 <type:*+0x32100>
   1401341d5:	48 8d 8c 24 e0 00 00 	lea    0xe0(%rsp),%rcx
   1401341dc:	00 
   1401341dd:	48 89 d3             	mov    %rdx,%rbx
   1401341e0:	e8 db 15 ee ff       	call   1400157c0 <runtime.wbMove>
   1401341e5:	48 8b 84 24 e0 00 00 	mov    0xe0(%rsp),%rax
   1401341ec:	00 
   1401341ed:	48 8b bc 24 98 01 00 	mov    0x198(%rsp),%rdi
   1401341f4:	00 
   1401341f5:	48 89 47 78          	mov    %rax,0x78(%rdi)
   1401341f9:	48 8d 87 80 00 00 00 	lea    0x80(%rdi),%rax
   140134200:	48 8d b4 24 e8 00 00 	lea    0xe8(%rsp),%rsi
   140134207:	00 
   140134208:	48 89 f9             	mov    %rdi,%rcx
   14013420b:	48 89 c7             	mov    %rax,%rdi
   14013420e:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
   140134215:	00 00 
   140134217:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
   14013421e:	00 00 
   140134220:	48 89 6c 24 f0       	mov    %rbp,-0x10(%rsp)
   140134225:	48 8d 6c 24 f0       	lea    -0x10(%rsp),%rbp
   14013422a:	e8 d3 84 f3 ff       	call   14006c702 <runtime.duffcopy+0x302>
   14013422f:	48 8b 6d 00          	mov    0x0(%rbp),%rbp
   140134233:	48 89 8c 24 c8 00 00 	mov    %rcx,0xc8(%rsp)
   14013423a:	00 
   14013423b:	44 0f 11 bc 24 b8 00 	movups %xmm15,0xb8(%rsp)
   140134242:	00 00 
   140134244:	c6 84 24 b7 00 00 00 	movb   $0x0,0xb7(%rsp)
   14013424b:	00 
   14013424c:	48 8b 94 24 a0 01 00 	mov    0x1a0(%rsp),%rdx
   140134253:	00 
   140134254:	48 8b 02             	mov    (%rdx),%rax
   140134257:	ff d0                	call   *%rax
   140134259:	48 8b 9c 24 b8 00 00 	mov    0xb8(%rsp),%rbx
   140134260:	00 
   140134261:	48 8b 84 24 c8 00 00 	mov    0xc8(%rsp),%rax
   140134268:	00 
   140134269:	48 8b 8c 24 c0 00 00 	mov    0xc0(%rsp),%rcx
   140134270:	00 
   140134271:	48 81 c4 a8 01 00 00 	add    $0x1a8,%rsp
   140134278:	5d                   	pop    %rbp
   140134279:	c3                   	ret
   14013427a:	48 c7 84 24 c8 00 00 	movq   $0x0,0xc8(%rsp)
   140134281:	00 00 00 00 00 
   140134286:	48 89 84 24 b8 00 00 	mov    %rax,0xb8(%rsp)
   14013428d:	00 
   14013428e:	48 89 9c 24 c0 00 00 	mov    %rbx,0xc0(%rsp)
   140134295:	00 
   140134296:	c6 84 24 b7 00 00 00 	movb   $0x0,0xb7(%rsp)
   14013429d:	00 
   14013429e:	48 8b 94 24 a0 01 00 	mov    0x1a0(%rsp),%rdx
   1401342a5:	00 
   1401342a6:	48 8b 02             	mov    (%rdx),%rax
   1401342a9:	ff d0                	call   *%rax
   1401342ab:	48 8b 9c 24 b8 00 00 	mov    0xb8(%rsp),%rbx
   1401342b2:	00 
   1401342b3:	48 8b 84 24 c8 00 00 	mov    0xc8(%rsp),%rax
   1401342ba:	00 
   1401342bb:	48 8b 8c 24 c0 00 00 	mov    0xc0(%rsp),%rcx
   1401342c2:	00 
   1401342c3:	48 81 c4 a8 01 00 00 	add    $0x1a8,%rsp
   1401342ca:	5d                   	pop    %rbp
   1401342cb:	c3                   	ret
   1401342cc:	48 c7 84 24 c8 00 00 	movq   $0x0,0xc8(%rsp)
   1401342d3:	00 00 00 00 00 
   1401342d8:	48 89 9c 24 b8 00 00 	mov    %rbx,0xb8(%rsp)
   1401342df:	00 
   1401342e0:	48 89 8c 24 c0 00 00 	mov    %rcx,0xc0(%rsp)
   1401342e7:	00 
   1401342e8:	48 8b 84 24 c8 00 00 	mov    0xc8(%rsp),%rax
   1401342ef:	00 
   1401342f0:	48 81 c4 a8 01 00 00 	add    $0x1a8,%rsp
   1401342f7:	5d                   	pop    %rbp
   1401342f8:	c3                   	ret
   1401342f9:	e8 42 48 f0 ff       	call   140038b40 <runtime.deferreturn>
   1401342fe:	48 8b 84 24 c8 00 00 	mov    0xc8(%rsp),%rax
   140134305:	00 
   140134306:	48 8b 9c 24 b8 00 00 	mov    0xb8(%rsp),%rbx
   14013430d:	00 
   14013430e:	48 8b 8c 24 c0 00 00 	mov    0xc0(%rsp),%rcx
   140134315:	00 
   140134316:	48 81 c4 a8 01 00 00 	add    $0x1a8,%rsp
   14013431d:	5d                   	pop    %rbp
   14013431e:	c3                   	ret
   14013431f:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
   140134324:	48 89 5c 24 10       	mov    %rbx,0x10(%rsp)
   140134329:	e8 d2 5a f3 ff       	call   140069e00 <runtime.morestack_noctxt.abi0>
   14013432e:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
   140134333:	48 8b 5c 24 10       	mov    0x10(%rsp),%rbx
   140134338:	e9 c3 fc ff ff       	jmp    140134000 <github.com/dnicolson/irestore/backup.Open>
   14013433d:	cc                   	int3
   14013433e:	cc                   	int3
   14013433f:	cc                   	int3
