; MSL_Common_printf.s -- Metrowerks Standard Library, statically linked into the ARM9.
;
; Not Game Freak code.  MSL and the CodeWarrior runtime own roughly 0x0208C000
; to 0x0209D850 of main; these bodies are pret/pokeheartgold's hand-matched
; lib/MSL_C/asm/MSL_Common_printf.s, located in Black by tools/scripts/msl_sweep.py, which
; byte-searches every reference module for each MSL function with its
; relocation words masked.  Every function below is an exact hit.  The rest of
; the pret file is present in Black too but a few bytes different in each
; function -- Black links a slightly later build of the same library -- so it is
; deliberately not reproduced here.
;
; Branch targets and pool labels carry Black addresses, not pret's.
; Assemble: python tools/scripts/as.py src/main/msl_printf.s

; imports; each address is the relocated word read out of the ROM at the
; call site or literal that references it.
	.public sub_02092344	; memcpy

	.text
	.arm

	.balign 4, 0
	.global sub_02094488
	.type sub_02094488, @function
; MSL __StringWrite
sub_02094488:
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r3, [r4, #8]
	mov r5, r2
	ldr r2, [r4, #4]
	add r0, r3, r5
	cmp r0, r2
	ldr r0, [r4]
	subhi r5, r2, r3
	mov r2, r5
	add r0, r0, r3
	bl sub_02092344
	ldr r1, [r4, #8]
	mov r0, #1
	add r1, r1, r5
	str r1, [r4, #8]
	ldmia sp!, {r3, r4, r5, pc}
	.size sub_02094488, . - sub_02094488

