; MSL_math.s -- Metrowerks Standard Library, statically linked into the ARM9.
;
; Not Game Freak code.  MSL and the CodeWarrior runtime own roughly 0x0208C000
; to 0x0209D850 of main; these bodies are pret/pokeheartgold's hand-matched
; lib/MSL_C/asm/MSL_math.s, located in Black by tools/scripts/msl_sweep.py, which
; byte-searches every reference module for each MSL function with its
; relocation words masked.  Every function below is an exact hit.  The rest of
; the pret file is present in Black too but a few bytes different in each
; function -- Black links a slightly later build of the same library -- so it is
; deliberately not reproduced here.
;
; Branch targets and pool labels carry Black addresses, not pret's.
; Assemble: python tools/scripts/as.py src/main/msl_math.s

; imports; each address is the relocated word read out of the ROM at the
; call site or literal that references it.
	.public sub_0209A6E8	; frexp
	.public sub_0209A7A8	; ldexp

	.text
	.arm

	.balign 4, 0
	.global sub_02092144
	.type sub_02092144, @function
; MSL __msl_generic_count_bits64
sub_02092144:
	mov r3, r0, lsr #1
	ldr r2, _020921CC  ; =0x55555555
	orr r3, r3, r1, lsl #31
	and r3, r3, r2
	subs ip, r0, r3
	and r2, r2, r1, lsr #1
	ldr r0, _020921D0  ; =0x33333333
	sbc r3, r1, r2
	mov r1, ip, lsr #2
	orr r1, r1, r3, lsl #30
	and r2, ip, r0
	and r1, r1, r0
	adds r2, r2, r1
	and r1, r3, r0
	and r0, r0, r3, lsr #2
	adc r1, r1, r0
	mov r0, r2, lsr #4
	orr r0, r0, r1, lsl #28
	adds r2, r2, r0
	ldr r0, _020921D4  ; =0x0F0F0F0F
	adc r1, r1, r1, lsr #4
	and r3, r2, r0
	and r2, r1, r0
	mov r0, r3, lsr #8
	orr r0, r0, r2, lsl #24
	adds r1, r3, r0
	adc r2, r2, r2, lsr #8
	mov r0, r1, lsr #0x10
	orr r0, r0, r2, lsl #16
	adds r1, r1, r0
	adc r0, r2, r2, lsr #16
	adds r0, r1, r0
	and r0, r0, #0xff
	bx lr
	.align 2, 0
_020921CC: .word 0x55555555
_020921D0: .word 0x33333333
_020921D4: .word 0x0F0F0F0F
	.size sub_02092144, . - sub_02092144

	.balign 4, 0
	.global sub_020921F4
	.type sub_020921F4, @function
; MSL __fpclassifyd
sub_020921F4:
	stmdb sp!, {r0, r1, r2, r3}
	ldr r2, [sp, #4]
	ldr r0, _0209225C  ; =0x7FF00000
	ands r1, r2, r0
	beq _02092230
	cmp r1, r0
	bne _02092250
	ldr r0, _02092260  ; =0x000FFFFF
	tst r2, r0
	ldreq r0, [sp]
	add sp, sp, #0x10
	cmpeq r0, #0
	movne r0, #1
	moveq r0, #2
	bx lr
_02092230:
	ldr r0, _02092260  ; =0x000FFFFF
	tst r2, r0
	ldreq r0, [sp]
	add sp, sp, #0x10
	cmpeq r0, #0
	movne r0, #5
	moveq r0, #3
	bx lr
_02092250:
	mov r0, #4
	add sp, sp, #0x10
	bx lr
	.align 2, 0
_0209225C: .word 0x7FF00000
_02092260: .word 0x000FFFFF
	.size sub_020921F4, . - sub_020921F4

	.balign 4, 0
	.global sub_02097990
	.type sub_02097990, @function
; MSL scalbn
sub_02097990:
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r2
	add r2, sp, #0
	bl sub_0209A6E8
	ldr r2, [sp]
	add r2, r2, r4
	str r2, [sp]
	bl sub_0209A7A8
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.size sub_02097990, . - sub_02097990

