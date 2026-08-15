; MSL_Common_alloc.s -- Metrowerks Standard Library, statically linked into the ARM9.
;
; Not Game Freak code.  MSL and the CodeWarrior runtime own roughly 0x0208C000
; to 0x0209D850 of main; these bodies are pret/pokeheartgold's hand-matched
; lib/MSL_C/asm/MSL_Common_alloc.s, located in Black by tools/scripts/msl_sweep.py, which
; byte-searches every reference module for each MSL function with its
; relocation words masked.  Every function below is an exact hit.  The rest of
; the pret file is present in Black too but a few bytes different in each
; function -- Black links a slightly later build of the same library -- so it is
; deliberately not reproduced here.
;
; Branch targets and pool labels carry Black addresses, not pret's.
; Assemble: python tools/scripts/as.py src/main/msl_alloc.s

; imports; each address is the relocated word read out of the ROM at the
; call site or literal that references it.
	.public sub_0209138C	; __sys_alloc
	.public sub_020913A4	; __sys_free

	.text
	.arm

	.balign 4, 0
	.global sub_020913D0
	.type sub_020913D0, @function
; MSL malloc
sub_020913D0:
	stmdb sp!, {r3, lr}
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl sub_0209138C
	ldmia sp!, {r3, pc}
	.size sub_020913D0, . - sub_020913D0

	.balign 4, 0
	.global sub_020913E8
	.type sub_020913E8, @function
; MSL free
sub_020913E8:
	stmdb sp!, {r3, lr}
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	bl sub_020913A4
	ldmia sp!, {r3, pc}
	.size sub_020913E8, . - sub_020913E8

