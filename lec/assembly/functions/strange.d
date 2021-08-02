
strange:     file format elf32-i386


Disassembly of section .init:

00001000 <_init>:
    1000:	f3 0f 1e fb          	endbr32 
    1004:	53                   	push   %ebx
    1005:	83 ec 08             	sub    $0x8,%esp
    1008:	e8 c3 00 00 00       	call   10d0 <__x86.get_pc_thunk.bx>
    100d:	81 c3 cb 2f 00 00    	add    $0x2fcb,%ebx
    1013:	8b 83 1c 00 00 00    	mov    0x1c(%ebx),%eax
    1019:	85 c0                	test   %eax,%eax
    101b:	74 02                	je     101f <_init+0x1f>
    101d:	ff d0                	call   *%eax
    101f:	83 c4 08             	add    $0x8,%esp
    1022:	5b                   	pop    %ebx
    1023:	c3                   	ret    

Disassembly of section .plt:

00001030 <.plt>:
    1030:	ff b3 04 00 00 00    	pushl  0x4(%ebx)
    1036:	ff a3 08 00 00 00    	jmp    *0x8(%ebx)
    103c:	0f 1f 40 00          	nopl   0x0(%eax)
    1040:	f3 0f 1e fb          	endbr32 
    1044:	68 00 00 00 00       	push   $0x0
    1049:	e9 e2 ff ff ff       	jmp    1030 <.plt>
    104e:	66 90                	xchg   %ax,%ax
    1050:	f3 0f 1e fb          	endbr32 
    1054:	68 08 00 00 00       	push   $0x8
    1059:	e9 d2 ff ff ff       	jmp    1030 <.plt>
    105e:	66 90                	xchg   %ax,%ax

Disassembly of section .plt.got:

00001060 <__cxa_finalize@plt>:
    1060:	f3 0f 1e fb          	endbr32 
    1064:	ff a3 18 00 00 00    	jmp    *0x18(%ebx)
    106a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

Disassembly of section .plt.sec:

00001070 <__stack_chk_fail@plt>:
    1070:	f3 0f 1e fb          	endbr32 
    1074:	ff a3 0c 00 00 00    	jmp    *0xc(%ebx)
    107a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

00001080 <__libc_start_main@plt>:
    1080:	f3 0f 1e fb          	endbr32 
    1084:	ff a3 10 00 00 00    	jmp    *0x10(%ebx)
    108a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

Disassembly of section .text:

00001090 <_start>:
    1090:	f3 0f 1e fb          	endbr32 
    1094:	31 ed                	xor    %ebp,%ebp
    1096:	5e                   	pop    %esi
    1097:	89 e1                	mov    %esp,%ecx
    1099:	83 e4 f0             	and    $0xfffffff0,%esp
    109c:	50                   	push   %eax
    109d:	54                   	push   %esp
    109e:	52                   	push   %edx
    109f:	e8 22 00 00 00       	call   10c6 <_start+0x36>
    10a4:	81 c3 34 2f 00 00    	add    $0x2f34,%ebx
    10aa:	8d 83 08 d3 ff ff    	lea    -0x2cf8(%ebx),%eax
    10b0:	50                   	push   %eax
    10b1:	8d 83 98 d2 ff ff    	lea    -0x2d68(%ebx),%eax
    10b7:	50                   	push   %eax
    10b8:	51                   	push   %ecx
    10b9:	56                   	push   %esi
    10ba:	ff b3 20 00 00 00    	pushl  0x20(%ebx)
    10c0:	e8 bb ff ff ff       	call   1080 <__libc_start_main@plt>
    10c5:	f4                   	hlt    
    10c6:	8b 1c 24             	mov    (%esp),%ebx
    10c9:	c3                   	ret    
    10ca:	66 90                	xchg   %ax,%ax
    10cc:	66 90                	xchg   %ax,%ax
    10ce:	66 90                	xchg   %ax,%ax

000010d0 <__x86.get_pc_thunk.bx>:
    10d0:	8b 1c 24             	mov    (%esp),%ebx
    10d3:	c3                   	ret    
    10d4:	66 90                	xchg   %ax,%ax
    10d6:	66 90                	xchg   %ax,%ax
    10d8:	66 90                	xchg   %ax,%ax
    10da:	66 90                	xchg   %ax,%ax
    10dc:	66 90                	xchg   %ax,%ax
    10de:	66 90                	xchg   %ax,%ax

000010e0 <deregister_tm_clones>:
    10e0:	e8 e4 00 00 00       	call   11c9 <__x86.get_pc_thunk.dx>
    10e5:	81 c2 f3 2e 00 00    	add    $0x2ef3,%edx
    10eb:	8d 8a 30 00 00 00    	lea    0x30(%edx),%ecx
    10f1:	8d 82 30 00 00 00    	lea    0x30(%edx),%eax
    10f7:	39 c8                	cmp    %ecx,%eax
    10f9:	74 1d                	je     1118 <deregister_tm_clones+0x38>
    10fb:	8b 82 14 00 00 00    	mov    0x14(%edx),%eax
    1101:	85 c0                	test   %eax,%eax
    1103:	74 13                	je     1118 <deregister_tm_clones+0x38>
    1105:	55                   	push   %ebp
    1106:	89 e5                	mov    %esp,%ebp
    1108:	83 ec 14             	sub    $0x14,%esp
    110b:	51                   	push   %ecx
    110c:	ff d0                	call   *%eax
    110e:	83 c4 10             	add    $0x10,%esp
    1111:	c9                   	leave  
    1112:	c3                   	ret    
    1113:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1117:	90                   	nop
    1118:	c3                   	ret    
    1119:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

00001120 <register_tm_clones>:
    1120:	e8 a4 00 00 00       	call   11c9 <__x86.get_pc_thunk.dx>
    1125:	81 c2 b3 2e 00 00    	add    $0x2eb3,%edx
    112b:	55                   	push   %ebp
    112c:	89 e5                	mov    %esp,%ebp
    112e:	53                   	push   %ebx
    112f:	8d 8a 30 00 00 00    	lea    0x30(%edx),%ecx
    1135:	8d 82 30 00 00 00    	lea    0x30(%edx),%eax
    113b:	83 ec 04             	sub    $0x4,%esp
    113e:	29 c8                	sub    %ecx,%eax
    1140:	89 c3                	mov    %eax,%ebx
    1142:	c1 e8 1f             	shr    $0x1f,%eax
    1145:	c1 fb 02             	sar    $0x2,%ebx
    1148:	01 d8                	add    %ebx,%eax
    114a:	d1 f8                	sar    %eax
    114c:	74 14                	je     1162 <register_tm_clones+0x42>
    114e:	8b 92 24 00 00 00    	mov    0x24(%edx),%edx
    1154:	85 d2                	test   %edx,%edx
    1156:	74 0a                	je     1162 <register_tm_clones+0x42>
    1158:	83 ec 08             	sub    $0x8,%esp
    115b:	50                   	push   %eax
    115c:	51                   	push   %ecx
    115d:	ff d2                	call   *%edx
    115f:	83 c4 10             	add    $0x10,%esp
    1162:	8b 5d fc             	mov    -0x4(%ebp),%ebx
    1165:	c9                   	leave  
    1166:	c3                   	ret    
    1167:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
    116e:	66 90                	xchg   %ax,%ax

00001170 <__do_global_dtors_aux>:
    1170:	f3 0f 1e fb          	endbr32 
    1174:	55                   	push   %ebp
    1175:	89 e5                	mov    %esp,%ebp
    1177:	53                   	push   %ebx
    1178:	e8 53 ff ff ff       	call   10d0 <__x86.get_pc_thunk.bx>
    117d:	81 c3 5b 2e 00 00    	add    $0x2e5b,%ebx
    1183:	83 ec 04             	sub    $0x4,%esp
    1186:	80 bb 30 00 00 00 00 	cmpb   $0x0,0x30(%ebx)
    118d:	75 27                	jne    11b6 <__do_global_dtors_aux+0x46>
    118f:	8b 83 18 00 00 00    	mov    0x18(%ebx),%eax
    1195:	85 c0                	test   %eax,%eax
    1197:	74 11                	je     11aa <__do_global_dtors_aux+0x3a>
    1199:	83 ec 0c             	sub    $0xc,%esp
    119c:	ff b3 2c 00 00 00    	pushl  0x2c(%ebx)
    11a2:	e8 b9 fe ff ff       	call   1060 <__cxa_finalize@plt>
    11a7:	83 c4 10             	add    $0x10,%esp
    11aa:	e8 31 ff ff ff       	call   10e0 <deregister_tm_clones>
    11af:	c6 83 30 00 00 00 01 	movb   $0x1,0x30(%ebx)
    11b6:	8b 5d fc             	mov    -0x4(%ebp),%ebx
    11b9:	c9                   	leave  
    11ba:	c3                   	ret    
    11bb:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    11bf:	90                   	nop

000011c0 <frame_dummy>:
    11c0:	f3 0f 1e fb          	endbr32 
    11c4:	e9 57 ff ff ff       	jmp    1120 <register_tm_clones>

000011c9 <__x86.get_pc_thunk.dx>:
    11c9:	8b 14 24             	mov    (%esp),%edx
    11cc:	c3                   	ret    

000011cd <strange>:
    11cd:	f3 0f 1e fb          	endbr32 
    11d1:	55                   	push   %ebp
    11d2:	89 e5                	mov    %esp,%ebp
    11d4:	83 ec 10             	sub    $0x10,%esp
    11d7:	e8 8f 00 00 00       	call   126b <__x86.get_pc_thunk.ax>
    11dc:	05 fc 2d 00 00       	add    $0x2dfc,%eax
    11e1:	8b 45 08             	mov    0x8(%ebp),%eax
    11e4:	8b 00                	mov    (%eax),%eax
    11e6:	8b 55 0c             	mov    0xc(%ebp),%edx
    11e9:	0f af c2             	imul   %edx,%eax
    11ec:	89 45 fc             	mov    %eax,-0x4(%ebp)
    11ef:	8b 45 08             	mov    0x8(%ebp),%eax
    11f2:	8b 10                	mov    (%eax),%edx
    11f4:	8b 45 0c             	mov    0xc(%ebp),%eax
    11f7:	01 c2                	add    %eax,%edx
    11f9:	8b 45 08             	mov    0x8(%ebp),%eax
    11fc:	89 10                	mov    %edx,(%eax)
    11fe:	8b 45 fc             	mov    -0x4(%ebp),%eax
    1201:	c9                   	leave  
    1202:	c3                   	ret    

00001203 <main>:
    1203:	f3 0f 1e fb          	endbr32 
    1207:	8d 4c 24 04          	lea    0x4(%esp),%ecx
    120b:	83 e4 f0             	and    $0xfffffff0,%esp
    120e:	ff 71 fc             	pushl  -0x4(%ecx)
    1211:	55                   	push   %ebp
    1212:	89 e5                	mov    %esp,%ebp
    1214:	51                   	push   %ecx
    1215:	83 ec 14             	sub    $0x14,%esp
    1218:	e8 4e 00 00 00       	call   126b <__x86.get_pc_thunk.ax>
    121d:	05 bb 2d 00 00       	add    $0x2dbb,%eax
    1222:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
    1228:	89 45 f4             	mov    %eax,-0xc(%ebp)
    122b:	31 c0                	xor    %eax,%eax
    122d:	c7 45 e8 03 00 00 00 	movl   $0x3,-0x18(%ebp)
    1234:	c7 45 ec 04 00 00 00 	movl   $0x4,-0x14(%ebp)
    123b:	ff 75 ec             	pushl  -0x14(%ebp)
    123e:	8d 45 e8             	lea    -0x18(%ebp),%eax
    1241:	50                   	push   %eax
    1242:	e8 86 ff ff ff       	call   11cd <strange>
    1247:	83 c4 08             	add    $0x8,%esp
    124a:	89 45 f0             	mov    %eax,-0x10(%ebp)
    124d:	b8 00 00 00 00       	mov    $0x0,%eax
    1252:	8b 55 f4             	mov    -0xc(%ebp),%edx
    1255:	65 33 15 14 00 00 00 	xor    %gs:0x14,%edx
    125c:	74 05                	je     1263 <main+0x60>
    125e:	e8 8d 00 00 00       	call   12f0 <__stack_chk_fail_local>
    1263:	8b 4d fc             	mov    -0x4(%ebp),%ecx
    1266:	c9                   	leave  
    1267:	8d 61 fc             	lea    -0x4(%ecx),%esp
    126a:	c3                   	ret    

0000126b <__x86.get_pc_thunk.ax>:
    126b:	8b 04 24             	mov    (%esp),%eax
    126e:	c3                   	ret    
    126f:	90                   	nop

00001270 <__libc_csu_init>:
    1270:	f3 0f 1e fb          	endbr32 
    1274:	55                   	push   %ebp
    1275:	e8 6b 00 00 00       	call   12e5 <__x86.get_pc_thunk.bp>
    127a:	81 c5 5e 2d 00 00    	add    $0x2d5e,%ebp
    1280:	57                   	push   %edi
    1281:	56                   	push   %esi
    1282:	53                   	push   %ebx
    1283:	83 ec 0c             	sub    $0xc,%esp
    1286:	89 eb                	mov    %ebp,%ebx
    1288:	8b 7c 24 28          	mov    0x28(%esp),%edi
    128c:	e8 6f fd ff ff       	call   1000 <_init>
    1291:	8d 9d 04 ff ff ff    	lea    -0xfc(%ebp),%ebx
    1297:	8d 85 00 ff ff ff    	lea    -0x100(%ebp),%eax
    129d:	29 c3                	sub    %eax,%ebx
    129f:	c1 fb 02             	sar    $0x2,%ebx
    12a2:	74 29                	je     12cd <__libc_csu_init+0x5d>
    12a4:	31 f6                	xor    %esi,%esi
    12a6:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
    12ad:	8d 76 00             	lea    0x0(%esi),%esi
    12b0:	83 ec 04             	sub    $0x4,%esp
    12b3:	57                   	push   %edi
    12b4:	ff 74 24 2c          	pushl  0x2c(%esp)
    12b8:	ff 74 24 2c          	pushl  0x2c(%esp)
    12bc:	ff 94 b5 00 ff ff ff 	call   *-0x100(%ebp,%esi,4)
    12c3:	83 c6 01             	add    $0x1,%esi
    12c6:	83 c4 10             	add    $0x10,%esp
    12c9:	39 f3                	cmp    %esi,%ebx
    12cb:	75 e3                	jne    12b0 <__libc_csu_init+0x40>
    12cd:	83 c4 0c             	add    $0xc,%esp
    12d0:	5b                   	pop    %ebx
    12d1:	5e                   	pop    %esi
    12d2:	5f                   	pop    %edi
    12d3:	5d                   	pop    %ebp
    12d4:	c3                   	ret    
    12d5:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
    12dc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

000012e0 <__libc_csu_fini>:
    12e0:	f3 0f 1e fb          	endbr32 
    12e4:	c3                   	ret    

000012e5 <__x86.get_pc_thunk.bp>:
    12e5:	8b 2c 24             	mov    (%esp),%ebp
    12e8:	c3                   	ret    
    12e9:	66 90                	xchg   %ax,%ax
    12eb:	66 90                	xchg   %ax,%ax
    12ed:	66 90                	xchg   %ax,%ax
    12ef:	90                   	nop

000012f0 <__stack_chk_fail_local>:
    12f0:	f3 0f 1e fb          	endbr32 
    12f4:	53                   	push   %ebx
    12f5:	e8 d6 fd ff ff       	call   10d0 <__x86.get_pc_thunk.bx>
    12fa:	81 c3 de 2c 00 00    	add    $0x2cde,%ebx
    1300:	83 ec 08             	sub    $0x8,%esp
    1303:	e8 68 fd ff ff       	call   1070 <__stack_chk_fail@plt>

Disassembly of section .fini:

00001308 <_fini>:
    1308:	f3 0f 1e fb          	endbr32 
    130c:	53                   	push   %ebx
    130d:	83 ec 08             	sub    $0x8,%esp
    1310:	e8 bb fd ff ff       	call   10d0 <__x86.get_pc_thunk.bx>
    1315:	81 c3 c3 2c 00 00    	add    $0x2cc3,%ebx
    131b:	83 c4 08             	add    $0x8,%esp
    131e:	5b                   	pop    %ebx
    131f:	c3                   	ret    
