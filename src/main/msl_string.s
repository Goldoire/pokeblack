; MSL_Common_string.s -- Metrowerks Standard Library, statically linked into the ARM9.
;
; Not Game Freak code.  MSL and the CodeWarrior runtime own roughly 0x0208C000
; to 0x0209D850 of main; these bodies are pret/pokeheartgold's hand-matched
; lib/MSL_C/asm/MSL_Common_string.s, located in Black by tools/scripts/msl_sweep.py, which
; byte-searches every reference module for each MSL function with its
; relocation words masked.  Every function below is an exact hit.  The rest of
; the pret file is present in Black too but a few bytes different in each
; function -- Black links a slightly later build of the same library -- so it is
; deliberately not reproduced here.
;
; Branch targets and pool labels carry Black addresses, not pret's.
; Assemble: python tools/scripts/as.py src/main/msl_string.s

	.text
	.arm

	.balign 4, 0
	.global sub_020948E0
	.type sub_020948E0, @function
; MSL strcmp
sub_020948E0:
	stmdb sp!, {r4, lr}
	ldrb r2, [r0]
	ldrb r3, [r1]
	subs r3, r2, r3
	movne r0, r3
	ldmneia sp!, {r4, pc}
	and r4, r0, #3
	and r3, r1, #3
	cmp r3, r4
	bne _020949BC
	cmp r4, #0
	beq _02094954
	cmp r2, #0
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	rsbs r4, r4, #3
	beq _0209494C
_02094924:
	ldrb r3, [r0, #1]!
	ldrb r2, [r1, #1]!
	subs r2, r3, r2
	movne r0, r2
	ldmneia sp!, {r4, pc}
	cmp r3, #0
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	subs r4, r4, #1
	bne _02094924
_0209494C:
	add r0, r0, #1
	add r1, r1, #1
_02094954:
	ldr r2, [r0]
	ldr r3, _020949EC  ; =0xFEFEFEFF
	mvn r4, r2
	add lr, r2, r3
	ldr ip, _020949F0  ; =0x80808080
	and r4, lr, r4
	tst r4, ip
	ldr r4, [r1]
	bne _020949A8
	cmp r2, r4
	bne _0209499C
_02094980:
	ldr r2, [r0, #4]!
	ldr r4, [r1, #4]!
	add lr, r2, r3
	tst lr, ip
	bne _020949A8
	cmp r2, r4
	beq _02094980
_0209499C:
	sub r0, r0, #1
	sub r1, r1, #1
	b _020949BC
_020949A8:
	ldrb r2, [r0]
	ldrb r3, [r1]
	subs r3, r2, r3
	movne r0, r3
	ldmneia sp!, {r4, pc}
_020949BC:
	cmp r2, #0
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
_020949C8:
	ldrb r3, [r0, #1]!
	ldrb r2, [r1, #1]!
	subs r2, r3, r2
	movne r0, r2
	ldmneia sp!, {r4, pc}
	cmp r3, #0
	bne _020949C8
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_020949EC: .word 0xFEFEFEFF
_020949F0: .word 0x80808080
	.size sub_020948E0, . - sub_020948E0

	.balign 4, 0
	.global sub_020949F4
	.type sub_020949F4, @function
; MSL strncmp
sub_020949F4:
	cmp r2, #0
	beq _02094A20
_020949FC:
	ldrb ip, [r1], #1
	ldrb r3, [r0], #1
	cmp r3, ip
	subne r0, r3, ip
	bxne lr
	cmp r3, #0
	beq _02094A20
	subs r2, r2, #1
	bne _020949FC
_02094A20:
	mov r0, #0
	bx lr
	.size sub_020949F4, . - sub_020949F4

	.balign 4, 0
	.global sub_02094B20
	.type sub_02094B20, @function
; MSL strstr
sub_02094B20:
	stmdb sp!, {r4, lr}
	cmp r1, #0
	ldrneb r2, [r1]
	cmpne r2, #0
	ldmeqia sp!, {r4, pc}
	ldrb r3, [r0]
	add r4, r0, #1
	cmp r3, #0
	beq _02094B84
_02094B44:
	cmp r3, r2
	bne _02094B78
	mov lr, r4
	add ip, r1, #1
_02094B54:
	ldrb r3, [ip], #1
	ldrb r0, [lr], #1
	cmp r0, r3
	bne _02094B6C
	cmp r0, #0
	bne _02094B54
_02094B6C:
	cmp r3, #0
	subeq r0, r4, #1
	ldmeqia sp!, {r4, pc}
_02094B78:
	ldrb r3, [r4], #1
	cmp r3, #0
	bne _02094B44
_02094B84:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.size sub_02094B20, . - sub_02094B20

