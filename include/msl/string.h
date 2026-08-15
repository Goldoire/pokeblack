#ifndef MSL_STRING_H
#define MSL_STRING_H

/*
 * Minimal <string.h> for the MWCC build. Only the mem*/str* entry points the
 * game actually links (they come from the SDK's own libc replacements) are
 * declared. Do not add anything here that the ROM does not contain.
 */

#include <stddef.h>

void *memcpy(void *dst, const void *src, size_t n);
void *memmove(void *dst, const void *src, size_t n);
void *memset(void *dst, int c, size_t n);
int memcmp(const void *a, const void *b, size_t n);

size_t strlen(const char *s);
char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, size_t n);
int strcmp(const char *a, const char *b);
int strncmp(const char *a, const char *b, size_t n);
char *strcat(char *dst, const char *src);
char *strchr(const char *s, int c);

#endif // MSL_STRING_H
