#include <stddef.h>
/* SPDX-License-Identifier: GPL-2.0-or-later */
#include <ctype.h>
#include <ascii.h>
#include <export.h>

const unsigned short ctype_table[256] = {
    [ASCII_NUL] = CTYPE_CNTRL,
    [ASCII_SOH] = CTYPE_CNTRL,
    [ASCII_STX] = CTYPE_CNTRL,
    [ASCII_ETX] = CTYPE_CNTRL,
    [ASCII_EOT] = CTYPE_CNTRL,
    [ASCII_ENQ] = CTYPE_CNTRL,
    [ASCII_ACK] = CTYPE_CNTRL,
    [ASCII_BEL] = CTYPE_CNTRL,
    [ASCII_BS ] = CTYPE_CNTRL,
    [ASCII_HT ] = CTYPE_CNTRL | CTYPE_SPACE,
    [ASCII_LF ] = CTYPE_CNTRL | CTYPE_SPACE,
    [ASCII_VT ] = CTYPE_CNTRL | CTYPE_SPACE | CTYPE_BLANK,
    [ASCII_FF ] = CTYPE_CNTRL | CTYPE_SPACE,
    [ASCII_CR ] = CTYPE_CNTRL | CTYPE_SPACE,
    [ASCII_SO ] = CTYPE_CNTRL,
    [ASCII_SI ] = CTYPE_CNTRL,
    [ASCII_DLE] = CTYPE_CNTRL,
    [ASCII_DC1] = CTYPE_CNTRL,
    [ASCII_DC2] = CTYPE_CNTRL,
    [ASCII_DC3] = CTYPE_CNTRL,
    [ASCII_DC4] = CTYPE_CNTRL,
    [ASCII_NAK] = CTYPE_CNTRL,
    [ASCII_SYN] = CTYPE_CNTRL,
    [ASCII_ETB] = CTYPE_CNTRL,
    [ASCII_CAN] = CTYPE_CNTRL,
    [ASCII_EM ] = CTYPE_CNTRL,
    [ASCII_SUB] = CTYPE_CNTRL,
    [ASCII_ESC] = CTYPE_CNTRL,
    [ASCII_FS ] = CTYPE_CNTRL,
    [ASCII_GS ] = CTYPE_CNTRL,
    [ASCII_RS ] = CTYPE_CNTRL,
    [ASCII_US ] = CTYPE_CNTRL,

    [' ' ] = CTYPE_SPACE | CTYPE_HDSPA | CTYPE_BLANK,
    ['!' ] = CTYPE_PUNCT,
    ['"' ] = CTYPE_PUNCT,
    ['#' ] = CTYPE_PUNCT,
    ['$' ] = CTYPE_PUNCT,
    ['%' ] = CTYPE_PUNCT,
    ['&' ] = CTYPE_PUNCT,
    ['\''] = CTYPE_PUNCT,
    ['(' ] = CTYPE_PUNCT,
    [')' ] = CTYPE_PUNCT,
    ['*' ] = CTYPE_PUNCT,
    ['+' ] = CTYPE_PUNCT,
    [',' ] = CTYPE_PUNCT,
    ['-' ] = CTYPE_PUNCT,
    ['.' ] = CTYPE_PUNCT,
    ['/' ] = CTYPE_PUNCT,

    ['0'] = CTYPE_DIGIT,
    ['1'] = CTYPE_DIGIT,
    ['2'] = CTYPE_DIGIT,
    ['3'] = CTYPE_DIGIT,
    ['4'] = CTYPE_DIGIT,
    ['5'] = CTYPE_DIGIT,
    ['6'] = CTYPE_DIGIT,
    ['7'] = CTYPE_DIGIT,
    ['8'] = CTYPE_DIGIT,
    ['9'] = CTYPE_DIGIT,

    [':'] = CTYPE_PUNCT,
    [';'] = CTYPE_PUNCT,
    ['<'] = CTYPE_PUNCT,
    ['='] = CTYPE_PUNCT,
    ['>'] = CTYPE_PUNCT,
    ['?'] = CTYPE_PUNCT,
    ['@'] = CTYPE_PUNCT,

    ['A'] = CTYPE_UPPER | CTYPE_HEXDG,
    ['B'] = CTYPE_UPPER | CTYPE_HEXDG,
    ['C'] = CTYPE_UPPER | CTYPE_HEXDG,
    ['D'] = CTYPE_UPPER | CTYPE_HEXDG,
    ['E'] = CTYPE_UPPER | CTYPE_HEXDG,
    ['F'] = CTYPE_UPPER | CTYPE_HEXDG,
    ['G'] = CTYPE_UPPER,
    ['H'] = CTYPE_UPPER,
    ['I'] = CTYPE_UPPER,
    ['J'] = CTYPE_UPPER,
    ['K'] = CTYPE_UPPER,
    ['L'] = CTYPE_UPPER,
    ['M'] = CTYPE_UPPER,
    ['N'] = CTYPE_UPPER,
    ['O'] = CTYPE_UPPER,
    ['P'] = CTYPE_UPPER,
    ['Q'] = CTYPE_UPPER,
    ['R'] = CTYPE_UPPER,
    ['S'] = CTYPE_UPPER,
    ['T'] = CTYPE_UPPER,
    ['U'] = CTYPE_UPPER,
    ['V'] = CTYPE_UPPER,
    ['W'] = CTYPE_UPPER,
    ['X'] = CTYPE_UPPER,
    ['Y'] = CTYPE_UPPER,
    ['Z'] = CTYPE_UPPER,

    ['[' ] = CTYPE_PUNCT,
    ['\\'] = CTYPE_PUNCT,
    [']' ] = CTYPE_PUNCT,
    ['^' ] = CTYPE_PUNCT,
    ['_' ] = CTYPE_PUNCT,
    ['`' ] = CTYPE_PUNCT,

    ['a'] = CTYPE_LOWER | CTYPE_HEXDG,
    ['b'] = CTYPE_LOWER | CTYPE_HEXDG,
    ['c'] = CTYPE_LOWER | CTYPE_HEXDG,
    ['d'] = CTYPE_LOWER | CTYPE_HEXDG,
    ['e'] = CTYPE_LOWER | CTYPE_HEXDG,
    ['f'] = CTYPE_LOWER | CTYPE_HEXDG,
    ['g'] = CTYPE_LOWER,
    ['h'] = CTYPE_LOWER,
    ['i'] = CTYPE_LOWER,
    ['j'] = CTYPE_LOWER,
    ['k'] = CTYPE_LOWER,
    ['l'] = CTYPE_LOWER,
    ['m'] = CTYPE_LOWER,
    ['n'] = CTYPE_LOWER,
    ['o'] = CTYPE_LOWER,
    ['p'] = CTYPE_LOWER,
    ['q'] = CTYPE_LOWER,
    ['r'] = CTYPE_LOWER,
    ['s'] = CTYPE_LOWER,
    ['t'] = CTYPE_LOWER,
    ['u'] = CTYPE_LOWER,
    ['v'] = CTYPE_LOWER,
    ['w'] = CTYPE_LOWER,
    ['x'] = CTYPE_LOWER,
    ['y'] = CTYPE_LOWER,
    ['z'] = CTYPE_LOWER,

    ['{'] = CTYPE_PUNCT,
    ['|'] = CTYPE_PUNCT,
    ['}'] = CTYPE_PUNCT,
    ['~'] = CTYPE_PUNCT,
    [127] = CTYPE_CNTRL,
};

/* SPDX-License-Identifier: GPL-2.0-or-later */
#include <string.h>
#include <ctype.h>
#include <export.h>

/*
 * String manipulation
 */

 char *strcpy(char *dest, const char *src)
{
    char *tmp = dest;
    while ((*tmp++ = *src++) != '\0');
    return dest;
}


 char *strncpy(char *dest, const char *src, uint32_t n)
{
    char *tmp = dest;

    while (n) {
        if ((*tmp = *src) != 0)
            src++;
        tmp++;
        n--;
    }

    return dest;
}


 uint32_t strlcpy(char *dest, const char *src, uint32_t n)
{
    uint32_t len;
    uint32_t ret = strlen(src);

    if (n) {
        len = (ret >= n) ? n - 1 : ret;
        memcpy(dest, src, len);
        dest[len] = '\0';
    }

    return ret;
}


 char *strcat(char *dest, const char *src)
{
    char *tmp = dest;

    while (*dest)
        dest++;
    while ((*dest++ = *src++) != '\0');

    return tmp;
}


 char *strncat(char *dest, const char *src, uint32_t n)
{
    char *tmp = dest;

    if (n) {
        while (*dest)
            dest++;
        while ((*dest++ = *src++) != 0) {
            if (--n == 0) {
                *dest = '\0';
                break;
            }
        }
    }

    return tmp;
}


 uint32_t strlcat(char *dest, const char *src, uint32_t n)
{
    uint32_t dsize = strlen(dest);
    uint32_t len = strlen(src);
    uint32_t res = dsize + len;

    dest += dsize;
    n -= dsize;

    if (len >= n)
        len = n-1;

    memcpy(dest, src, len);
    dest[len] = 0;

    return res;
}


 int strcoll(const char *s1, const char *s2)
{
    return strcmp(s1, s2);
}


/*
 * String examination
 */
 uint32_t strlen(const char *s)
{
    const char *len;
    for (len = s; *len != '\0'; len++);
    return len - s;
}


 uint32_t strnlen(const char *s, uint32_t n)
{
    const char *sc;
    for (sc = s; n-- && *sc != '\0'; ++sc);
    return sc - s;
}


 int strcmp(const char *s1, const char *s2)
{
    int cp = 0;
    while ((!(cp = *s1++ - *s2++)) && (*s1 != '\0'));
    return cp;
}


 int strncmp(const char *s1, const char *s2, uint32_t n)
{
    int __res = 0;

    while (n) {
        if ((__res = *s1 - *s2++) != 0 || !*s1++)
            break;
        n--;
    }

    return __res;
}


 int strnicmp(const char *s1, const char *s2, uint32_t n)
{
    unsigned char c1 = 0, c2 = 0;

    if (n) {
        do {
            c1 = *s1;
            c2 = *s2;
            s1++;
            s2++;
            if (!c1)
                break;
            if (!c2)
                break;
            if (c1 == c2)
                continue;
            c1 = tolower(c1);
            c2 = tolower(c2);
            if (c1 != c2)
                break;
        } while (--n);
    }

    return (int)c1 - (int)c2;
}


 int strcasecmp(const char *s1, const char *s2)
{
    int c1, c2;

    do {
        c1 = tolower(*s1++);
        c2 = tolower(*s2++);
    } while (c1 == c2 && c1 != 0);

    return c1 - c2;
}


 int strncasecmp(const char *s1, const char *s2, uint32_t n)
{
    int c1, c2;

    do {
        c1 = tolower(*s1++);
        c2 = tolower(*s2++);
    } while ((--n > 0) && c1 == c2 && c1 != 0);

    return c1 - c2;
}


 char *strchr(const char *s, int c)
{
    for (; *s != (char)c; ++s) {
        if (*s == '\0')
            return 0;
    }

    return (char *)s;
}


 char *strrchr(const char *s, int c)
{
    const char *p = s + strlen(s);

    do {
        if (*p == (char)c)
            return (char *)p;
    } while (p-- > s);

    return 0;
}


 char *strnchr(const char *s, uint32_t n, int c)
{
    for (; n-- && *s != '\0'; ++s) {
        if (*s == (char)c)
            return (char *)s;
    }

    return 0;
}


 char *strrnchr(const char *s, uint32_t n, int c)
{
    const char *p = s + strnlen(s, n);

    do {
        if (*p == (char)c)
            return (char *)p;
    } while (p-- > s);

    return 0;
}


 char *strchrnul(const char *s, int c)
{
    while (*s && *s != (char)c)
        s++;

    return (char *)s;
}


 char *strnchrnul(const char *s, uint32_t count, int c)
{
    while (count-- && *s && *s != (char)c)
        s++;

    return (char *)s;
}


 uint32_t strspn(const char *s, const char *accept)
{
    const char *p;
    const char *a;
    uint32_t count = 0;

    for (p = s; *p != '\0'; ++p) {
        for (a = accept; *a != '\0'; ++a) {
            if (*p == *a)
                break;
        }
        if (*a == '\0')
            return count;
        ++count;
    }

    return count;
}


 uint32_t strcspn(const char *s, const char *reject)
{
    const char *p;
    const char *r;
    uint32_t count = 0;

    for (p = s; *p != '\0'; ++p) {
        for (r = reject; *r != '\0'; ++r) {
            if (*p == *r)
                return count;
        }
        ++count;
    }

    return count;
}


 char *strpbrk(const char *s1, const char *s2)
{
    const char *sc1, *sc2;

    for (sc1 = s1; *sc1 != '\0'; ++sc1) {
        for (sc2 = s2; *sc2 != '\0'; ++sc2) {
            if (*sc1 == *sc2)
                return (char *)sc1;
        }
    }

    return 0;
}


 char *strstr(const char *s1, const char *s2)
{
    uint32_t l1, l2;

    l2 = strlen(s2);
    if (!l2)
        return (char *)s1;

    l1 = strlen(s1);
    while (l1 >= l2) {
        l1--;
        if (!memcmp(s1, s2, l2))
            return (char *)s1;
        s1++;
    }

    return 0;
}


 char *strnstr(const char *s1, const char *s2, uint32_t n)
{
    uint32_t l2;

    l2 = strlen(s2);
    if (!l2)
        return (char *)s1;

    while (n >= l2) {
        n--;
        if (!memcmp(s1, s2, l2))
            return (char *)s1;
        s1++;
    }

    return 0;
}



 char *strsep(char **s, const char *ct)
{
    char *sbegin = *s;
    char *end;

    if (sbegin == 0)
        return 0;

    end = strpbrk(sbegin, ct);
    if (end)
        *end++ = '\0';
    *s = end;

    return sbegin;
}


 char *strim(char *s)
{
    char *e;

    if (s) {
        while (isspace(*s))
            s++;
        if (*s == 0)
            return s;
        e = s + strlen(s) - 1;
        while ((e > s) && isspace(*e))
            e--;
        *(e + 1) = 0;
    }

    return s;
}


/*
 * Memory manipulation
 */

 void *memset(void *s, int c, uint32_t n)
{
    char *xs = s;

    while (n--)
        *xs++ = c;

    return s;
}


 void *memcpy(void *dest, const void *src, uint32_t len)
{
    uint8_t * restrict ndest = dest;
    const uint8_t * restrict nsrc = src;

    while (len--)
        *ndest++ = *nsrc++;

    return dest;
}


 void *mempcpy(void *dest, const void *src, uint32_t len)
{
    uint8_t * restrict ndest = dest;
    const uint8_t * restrict nsrc = src;

    while (len--)
        *ndest++ = *nsrc++;

    return ndest;
}


 void *memmove(void *dest, const void *src, uint32_t n)
{
    char *tmp;
    const char *s;

    if (dest <= src) {
        tmp = dest;
        s = src;
        while (n--)
            *tmp++ = *s++;
    } else {
        tmp = dest;
        tmp += n;
        s = src;
        s += n;
        while (n--)
            *--tmp = *--s;
    }

    return dest;
}


 void *memchr(const void *s, int c, uint32_t n)
{
    char *str = (char *)s;

    while (n-- != 0) {
        if (c == *str++)
            return str - 1;
    }

    return 0;
}


 void *memscan(void *addr, int c, uint32_t size)
{
    unsigned char *p = addr;

    while (size) {
        if (*p == c)
            return (void *)p;
        p++;
        size--;
    }

    return (void *)p;
}


 int memcmp(const void *s1, const void *s2, uint32_t n)
{
    const unsigned char *su1, *su2;
    int res = 0;

    for (su1 = s1, su2 = s2; 0 < n; ++su1, ++su2, n--) {
        if ((res = *su1 - *su2) != 0)
            break;
    }

    return res;
}


/*
 * Extend Helper
 */

 int strcount(const char *str, int c)
{
    int count = 0;

    while (*str) {
        if (*str++ == (char)c)
            count++;
    }

    return count;
}


 int strncount(const char *str, int c, uint32_t n)
{
    int count = 0;

    while (*str && n--) {
        if (*str++ == c)
            count++;
    }

    return count;
}


 int strchreplace(char *str, int c, int s)
{
    int count = 0;

    for (; *str; str++) {
        if (*str == (char)s) {
            *str = c;
            count++;
        }
    }

    return count;
}


 int strnchreplace(char *str, int c, int s, uint32_t n)
{
    int count = 0;

    for (; *str && n--; str++) {
        if (*str == (char)s) {
            *str = c;
            count++;
        }
    }

    return count;
}


 void *memdiff(const void *addr, int c, uint32_t size)
{
    const unsigned char *p = addr;

    while (size) {
        if (*p != (char)c)
            return (void *)p;
        p++;
        size--;
    }

    return 0;
}


 uint32_t memcount(const void *addr, int c, uint32_t n)
{
    const char *p = addr;
    uint32_t count = 0;

    while (n--) {
        if (*p++ == (char)c)
            count++;
    }

    return count;
}


 char *skip_spaces(const char *str)
{
	while (isspace(*str))
		++str;
	return (char *)str;
}


 char *basename(const char *path)
{
    const char *c = strrchr(path, '/');
    return (char *)(c ? c + 1 : path);
}
