; MSL_fp_ansi.s -- Metrowerks Standard Library, statically linked into the ARM9.
;
; Not Game Freak code.  MSL and the CodeWarrior runtime own roughly 0x0208C000
; to 0x0209D850 of main; these bodies are pret/pokeheartgold's hand-matched
; lib/MSL_C/asm/MSL_fp_ansi.s, located in Black by tools/scripts/msl_sweep.py, which
; byte-searches every reference module for each MSL function with its
; relocation words masked.  Every function below is an exact hit.  The rest of
; the pret file is present in Black too but a few bytes different in each
; function -- Black links a slightly later build of the same library -- so it is
; deliberately not reproduced here.
;
; Branch targets and pool labels carry Black addresses, not pret's.
; Assemble: python tools/scripts/as.py src/main/msl_fp_ansi.s

	.text
	.arm

	.balign 4, 0
	.global sub_020965B4
	.type sub_020965B4, @function
; MSL __must_round
sub_020965B4:
	add r3, r0, #5
	ldrb r2, [r3, r1]
	add ip, r3, r1
	cmp r2, #5
	movhi r0, #1
	bxhi lr
	mvnlo r0, #0
	bxlo lr
	ldrb r2, [r0, #4]
	add ip, ip, #1
	add r3, r3, r2
	cmp ip, r3
	bhs _02096604
_020965E8:
	ldrb r2, [ip]
	cmp r2, #0
	movne r0, #1
	bxne lr
	add ip, ip, #1
	cmp ip, r3
	blo _020965E8
_02096604:
	sub r1, r1, #1
	add r0, r0, r1
	ldrb r0, [r0, #5]
	tst r0, #1
	movne r0, #1
	mvneq r0, #0
	bx lr
	.size sub_020965B4, . - sub_020965B4

	.balign 4, 0
	.global sub_02096620
	.type sub_02096620, @function
; MSL __dorounddecup
sub_02096620:
	add r3, r0, #5
	add r1, r3, r1
	sub ip, r1, #1
	mov r1, #0
_02096630:
	ldrb r2, [ip]
	cmp r2, #9
	addlo r0, r2, #1
	strlob r0, [ip]
	bxlo lr
	cmp ip, r3
	bne _02096664
	mov r1, #1
	strb r1, [ip]
	ldrsh r1, [r0, #2]
	add r1, r1, #1
	strh r1, [r0, #2]
	bx lr
_02096664:
	strb r1, [ip], #-1
	b _02096630
	bx lr
	.size sub_02096620, . - sub_02096620

	.balign 4, 0
	.global sub_02096670
	.type sub_02096670, @function
; MSL __rounddec
sub_02096670:
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r1
	mov r5, r0
	cmp r4, #0
	ldmleia sp!, {r3, r4, r5, pc}
	ldrb r2, [r5, #4]
	cmp r4, r2
	ldmgeia sp!, {r3, r4, r5, pc}
	bl sub_020965B4
	strb r4, [r5, #4]
	cmp r0, #0
	ldmltia sp!, {r3, r4, r5, pc}
	mov r0, r5
	mov r1, r4
	bl sub_02096620
	ldmia sp!, {r3, r4, r5, pc}
	.size sub_02096670, . - sub_02096670

	.balign 4, 0
	.global sub_02096DF0
	.type sub_02096DF0, @function
; MSL __less_dec
sub_02096DF0:
	stmdb sp!, {r3, r4, r5, lr}
	ldrb r2, [r0, #5]
	cmp r2, #0
	bne _02096E14
	ldrb r0, [r1, #5]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_02096E14:
	ldrb r2, [r1, #5]
	cmp r2, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldrsh r3, [r1, #2]
	ldrsh r2, [r0, #2]
	cmp r2, r3
	bne _02096EC4
	ldrb r5, [r0, #4]
	ldrb r4, [r1, #4]
	mov ip, #0
	mov lr, r5
	cmp r5, r4
	movgt lr, r4
	cmp lr, #0
	ble _02096E88
_02096E54:
	add r3, r1, ip
	add r2, r0, ip
	ldrb r3, [r3, #5]
	ldrb r2, [r2, #5]
	cmp r2, r3
	movlo r0, #1
	ldmloia sp!, {r3, r4, r5, pc}
	cmp r3, r2
	movlo r0, #0
	ldmloia sp!, {r3, r4, r5, pc}
	add ip, ip, #1
	cmp ip, lr
	blt _02096E54
_02096E88:
	cmp lr, r5
	bne _02096EBC
	cmp ip, r4
	bge _02096EBC
_02096E98:
	add r0, r1, ip
	ldrb r0, [r0, #5]
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r3, r4, r5, pc}
	ldrb r0, [r1, #4]
	add ip, ip, #1
	cmp ip, r0
	blt _02096E98
_02096EBC:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_02096EC4:
	movlt r0, #1
	movge r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.size sub_02096DF0, . - sub_02096DF0

