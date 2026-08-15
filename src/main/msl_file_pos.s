; MSL_Common_file_pos.s -- Metrowerks Standard Library, statically linked into the ARM9.
;
; Not Game Freak code.  MSL and the CodeWarrior runtime own roughly 0x0208C000
; to 0x0209D850 of main; these bodies are pret/pokeheartgold's hand-matched
; lib/MSL_C/asm/MSL_Common_file_pos.s, located in Black by tools/scripts/msl_sweep.py, which
; byte-searches every reference module for each MSL function with its
; relocation words masked.  Every function below is an exact hit.  The rest of
; the pret file is present in Black too but a few bytes different in each
; function -- Black links a slightly later build of the same library -- so it is
; deliberately not reproduced here.
;
; Branch targets and pool labels carry Black addresses, not pret's.
; Assemble: python tools/scripts/as.py src/main/msl_file_pos.s

; imports; each address is the relocated word read out of the ROM at the
; call site or literal that references it.
	.public _02153FAC	; errno

	.text
	.arm

	.balign 4, 0
	.global sub_02091CBC
	.type sub_02091CBC, @function
; MSL _ftell
sub_02091CBC:
	ldr r1, [r0, #4]
	mov r1, r1, lsl #0x16
	mov r1, r1, lsr #0x1d
	and r1, r1, #0xff
	add r1, r1, #0xff
	and r1, r1, #0xff
	cmp r1, #1
	bhi _02091CE8
	ldrb r1, [r0, #0xd]
	cmp r1, #0
	beq _02091CFC
_02091CE8:
	ldr r0, _02091D34  ; =errno
	mov r1, #0x28
	str r1, [r0]
	sub r0, r1, #0x29
	bx lr
_02091CFC:
	ldr r1, [r0, #8]
	mov r1, r1, lsl #0x1d
	movs ip, r1, lsr #0x1d
	ldreq r0, [r0, #0x18]
	bxeq lr
	ldr r2, [r0, #0x24]
	ldr r1, [r0, #0x1c]
	ldr r3, [r0, #0x34]
	sub r0, r2, r1
	cmp ip, #3
	add r0, r3, r0
	subhs r1, ip, #2
	subhs r0, r0, r1
	bx lr
	.align 2, 0
_02091D34: .word _02153FAC
	.size sub_02091CBC, . - sub_02091CBC

