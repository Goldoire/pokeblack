; MSL_Common_mbstring.s -- Metrowerks Standard Library, statically linked into the ARM9.
;
; Not Game Freak code.  MSL and the CodeWarrior runtime own roughly 0x0208C000
; to 0x0209D850 of main; these bodies are pret/pokeheartgold's hand-matched
; lib/MSL_C/asm/MSL_Common_mbstring.s, located in Black by tools/scripts/msl_sweep.py, which
; byte-searches every reference module for each MSL function with its
; relocation words masked.  Every function below is an exact hit.  The rest of
; the pret file is present in Black too but a few bytes different in each
; function -- Black links a slightly later build of the same library -- so it is
; deliberately not reproduced here.
;
; Branch targets and pool labels carry Black addresses, not pret's.
; Assemble: python tools/scripts/as.py src/main/msl_mbstring.s

; imports; each address is the relocated word read out of the ROM at the
; call site or literal that references it.
	.public _020A8878	; _current_locale

	.text
	.arm

	.balign 4, 0
	.global sub_0209229C
	.type sub_0209229C, @function
; MSL __wctomb_noconv
sub_0209229C:
	cmp r0, #0
	moveq r0, #0
	strneb r1, [r0]
	movne r0, #1
	bx lr
	.size sub_0209229C, . - sub_0209229C

	.balign 4, 0
	.global sub_020922B0
	.type sub_020922B0, @function
; MSL wctomb
sub_020922B0:
	stmdb sp!, {r3, lr}
	ldr r2, _020922C8  ; =_current_locale
	ldr r2, [r2, #8]
	ldr r2, [r2, #4]
	blx r2
	ldmia sp!, {r3, pc}
	.align 2, 0
_020922C8: .word _020A8878
	.size sub_020922B0, . - sub_020922B0

