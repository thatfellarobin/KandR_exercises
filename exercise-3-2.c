#include <stdio.h>

/* Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences
 * like \n and \t as it copies the string t to s, using
 * a switch. Write a function for the other direction
 * as well. */

#define MAXLEN 1000

int escape(char s[], char t[]);

int main()
{
    int i, len;
    char c, s[MAXLEN], t[MAXLEN];

    for (i = 0; (c = getchar()) != EOF && i < MAXLEN; ++i)
        s[i] = c;

    len = escape(s, t);

    printf("%s\n", t);
    return 0;
}

int escape(char s[], char t[])
{
    int i, j = 0;
    char c;
    for (i = 0; (c = s[i]) != '\0' && i + j + 1 < MAXLEN; ++i) {
        switch (c) {
        case '\n':
            t[i + j] = '\\';
            ++j;
            t[i + j] = 'n';
            break;
        case '\t':
            t[i + j] = '\\';
            ++j;
            t[i + j] = 't';
            break;
        default:
            t[i + j] = c;
            break;
        }
    }

    t[i + j + 1] = '\0';
    return j;
}

