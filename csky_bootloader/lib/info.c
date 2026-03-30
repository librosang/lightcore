#include <stdio.h>
#include <stdarg.h>

void (*print_func)(const char *buf);

void pr_init(void (*fun)(const char *buf)) {
    print_func = fun;
}

int pr_boot(const char *fmt, ...) {
    char buf[256];
    va_list args;
    va_start(args, fmt);
    int len = vsprintf(buf, fmt, args);
    va_end(args);
    if (print_func)
        print_func(buf);
    return len;
}

void panic(const char *fmt, ...) {
    char buf[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    if (print_func)
        print_func(buf);
    while (1);
}
