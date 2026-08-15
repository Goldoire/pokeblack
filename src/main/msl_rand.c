/* rand.c -- Metrowerks Standard Library, statically linked into the ARM9.
 *
 * Not Game Freak code.  This is pret/pokeheartgold's lib/MSL_C/src/rand.c, one
 * of only two MSL translation units that survive as C rather than assembly.
 * tools/scripts/msl_sweep.py places it at 0x02094694 in Black's main: rand and
 * srand are byte-identical to pokeheartgold's and sit back to back, and the
 * literal each of them loads points at the same word, which is the file-static
 * `random_next`.
 *
 * The static is spelled as an extern at its real address, per WORKER_GUIDE, so
 * the verifier checks the literal instead of masking it.  In the MSL source it
 * is `static unsigned long random_next = 1;` in this file's .data.
 *
 * Compiler: dsi/1.1, ARM (MSL is built `#pragma thumb off`).
 *   python tools/scripts/cc.py src/main/msl_rand.c
 */
#define SDK_FINALROM

extern unsigned long _020A8A78; /* random_next */

int sub_02094694(void)
{
    _020A8A78 = _020A8A78 * 1103515245 + 12345;
    return (_020A8A78 >> 16) & 0x7fff;
}

void sub_020946C8(unsigned int seed)
{
    _020A8A78 = seed;
}
