/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _STRING_H_
#define _STRING_H_

#include <stdint.h>
#include <stddef.h>
#include <stddef.h>

/* String manipulation */
extern char *strcpy(char *dest, const char *src);
extern char *strncpy(char *dest, const char *src, uint32_t n);
extern uint32_t strlcpy(char *dest, const char *src, uint32_t n);
extern char *strcat(char *dest, const char *src);
extern char *strncat(char *dest, const char *src, uint32_t n);
extern uint32_t strlcat(char *dest, const char *src, uint32_t n);

/* String examination */
extern uint32_t strlen(const char *s);
extern uint32_t strnlen(const char *s, uint32_t n);
extern int strcmp(const char *s1, const char *s2);
extern int strncmp(const char *s1, const char *s2, uint32_t n);
extern int strnicmp(const char *s1, const char *s2, uint32_t n);
extern int strcasecmp(const char *s1, const char *s2);
extern int strncasecmp(const char *s1, const char *s2, uint32_t n);
extern int strcoll(const char *s1, const char *s2);
extern char *strchr(const char *s, int c);
extern char *strrchr(const char *s, int c);
extern char *strnchr(const char *s, uint32_t n, int c);
extern char *strrnchr(const char *s, uint32_t n, int c);
extern char *strchrnul(const char *s, int c);
extern char *strnchrnul(const char *s, uint32_t count, int c);
extern uint32_t strspn(const char *s, const char *accept);
extern uint32_t strcspn(const char *s, const char *reject);
extern char *strpbrk(const char *s1, const char *s2);
extern char *strstr(const char *s1, const char *s2);
extern char *strnstr(const char *s1, const char *s2, uint32_t n);
extern char *strsep(char **s, const char *ct);
extern char *strim(char *s);

extern  char *kstrdup(const char *s, uint32_t gfp);
extern  const char *kstrdup_const(const char *s, uint32_t gfp);
extern  char *kstrndup(const char *s, uint32_t max, uint32_t gfp);

/* Memory manipulation */
extern void *memset(void *s, int c, uint32_t n);
extern void *memcpy(void *dest, const void *src, uint32_t len);
extern void *mempcpy(void *dest, const void *src, uint32_t len);
extern void *memmove(void *dest, const void *src, uint32_t n);
extern void *memchr(const void *s, int c, uint32_t n);
extern void *memscan(void *addr, int c, uint32_t size);
extern int memcmp(const void *s1, const void *s2, uint32_t n);

/* Extend Helper */
extern int strcount(const char *str, int c);
extern int strncount(const char *str, int c, uint32_t n);
extern int strchreplace(char *str, int c, int s);
extern int strnchreplace(char *str, int c, int s, uint32_t n);
extern void *memdiff(const void *addr, int c, uint32_t n);
extern uint32_t memcount(const void *addr, int c, uint32_t n);
extern char *skip_spaces(const char *path);
extern char *basename(const char *path);

#endif /* _STRING_H_ */
