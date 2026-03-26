#ifndef _STDIO_H
#define _STDIO_H

#include <stdarg.h>

int vsprintf(char *buf, const char *fmt, va_list args);
int sprintf(char *buf, const char *fmt, ...);
int printf(const char *fmt, ...);
void pr_init(void (*fun)(const char *buf));
int pr_boot(const char *fmt, ...);

#endif
