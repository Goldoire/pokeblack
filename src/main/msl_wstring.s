; MSL_Common_wstring.s -- Metrowerks Standard Library, statically linked into the ARM9.
;
; Not Game Freak code.  MSL and the CodeWarrior runtime own roughly 0x0208C000
; to 0x0209D850 of main; these bodies are pret/pokeheartgold's hand-matched
; lib/MSL_C/asm/MSL_Common_wstring.s, located in Black by tools/scripts/msl_sweep.py, which
; byte-searches every reference module for each MSL function with its
; relocation words masked.  Every function below is an exact hit.  The rest of
; the pret file is present in Black too but a few bytes different in each
; function -- Black links a slightly later build of the same library -- so it is
; deliberately not reproduced here.
;
; Branch targets and pool labels carry Black addresses, not pret's.
; Assemble: python tools/scripts/as.py src/main/msl_wstring.s

	.text
	.arm

	.balign 4, 0
	.global sub_02096578
	.type sub_02096578, @function
; MSL wcslen
sub_02096578:
	mvn r2, #0
_0209657C:
	ldrh r1, [r0], #2
	add r2, r2, #1
	cmp r1, #0
	bne _0209657C
	mov r0, r2
	bx lr
	.size sub_02096578, . - sub_02096578

	.balign 4, 0
	.global sub_02096594
	.type sub_02096594, @function
; MSL wcscpy
sub_02096594:
	mov r3, r0
_02096598:
	ldrh r2, [r1], #2
	mov ip, r3
	strh r2, [r3], #2
	ldrh r2, [ip]
	cmp r2, #0
	bne _02096598
	bx lr
	.size sub_02096594, . - sub_02096594

