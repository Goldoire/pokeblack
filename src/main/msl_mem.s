; MSL_Common_mem.s -- Metrowerks Standard Library, statically linked into the ARM9.
;
; Not Game Freak code.  MSL and the CodeWarrior runtime own roughly 0x0208C000
; to 0x0209D850 of main; these bodies are pret/pokeheartgold's hand-matched
; lib/MSL_C/asm/MSL_Common_mem.s, located in Black by tools/scripts/msl_sweep.py, which
; byte-searches every reference module for each MSL function with its
; relocation words masked.  Every function below is an exact hit.  The rest of
; the pret file is present in Black too but a few bytes different in each
; function -- Black links a slightly later build of the same library -- so it is
; deliberately not reproduced here.
;
; Branch targets and pool labels carry Black addresses, not pret's.
; Assemble: python tools/scripts/as.py src/main/msl_mem.s

; imports; each address is the relocated word read out of the ROM at the
; call site or literal that references it.
	.public sub_02092430	; __fill_mem

	.text
	.arm

	.balign 4, 0
	.global sub_020923B0
	.type sub_020923B0, @function
; MSL memset
sub_020923B0:
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02092430
	mov r0, r4
	ldmia sp!, {r4, pc}
	.size sub_020923B0, . - sub_020923B0

	.balign 4, 0
	.global sub_020923C4
	.type sub_020923C4, @function
; MSL memchr
sub_020923C4:
	cmp r2, #0
	and r3, r1, #0xff
	beq _020923E8
_020923D0:
	ldrb r1, [r0], #1
	cmp r1, r3
	subeq r0, r0, #1
	bxeq lr
	subs r2, r2, #1
	bne _020923D0
_020923E8:
	mov r0, #0
	bx lr
	.size sub_020923C4, . - sub_020923C4

	.balign 4, 0
	.global sub_020923F0
	.type sub_020923F0, @function
; MSL memcmp
sub_020923F0:
	cmp r2, #0
	beq _02092428
_020923F8:
	ldrb ip, [r0], #1
	ldrb r3, [r1], #1
	cmp ip, r3
	beq _02092420
	ldrb r2, [r0, #-1]
	ldrb r0, [r1, #-1]
	cmp r2, r0
	mvnlo r0, #0
	movhs r0, #1
	bx lr
_02092420:
	subs r2, r2, #1
	bne _020923F8
_02092428:
	mov r0, #0
	bx lr
	.size sub_020923F0, . - sub_020923F0

