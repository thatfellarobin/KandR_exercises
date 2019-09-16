#include <stdio.h>

/* The goal of this program is to create
 * a function htoi(s) that converts a
 * string of hex digits (including an
 * optional 0x or 0X) into its equivalent
 * integer value. The allowable digits
 * are 0 through 9, a through f, and A
 * through F */

/* I'm going to assume that the
 * character set has a through f
 * ordered sequentially, likewise
 * for A through F */

#define MAXSTRING 1000

int htoi(char s[]); 
int char_htoi(char c);

int main()
{
    char c, s[MAXSTRING]; 
    int i, result;

    for (i = 0; i < MAXSTRING &&
            (c = getchar()) != EOF &&
            c != '\n'; ++i)
        s[i] = c;

    if (i < MAXSTRING)
        s[i] = '\0';
    result = htoi(s);
    printf("%d\n", result);

    return 0;
}

int htoi(char s[])
{
    int i, value;
    value = 0;
    
    for (i = 0; i < MAXSTRING && s[i] != '\0'; ++i)
        value = value * 16 + char_htoi(s[i]);

    return value;
}

int char_htoi(char c)
{
    int val;

    if (c >= '0' && c <= '9')
        val = c - '0';
    else if (c >= 'a' && c <= 'f') 
        val = c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        val = c - 'A' + 10;
    else
        return -1;

    return val;
}
