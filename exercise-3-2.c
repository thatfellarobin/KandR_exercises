#include <stdio.h>

/* Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences
 * like \n and \t as it copies the string t to s, using
 * a switch. Write a function for the other direction
 * as well. */

#define MAXLEN 1000

int escape(char s[], char t[]);
int unescape(char tt[], char ss[]);

int main()
{
    int i, len, len2;
    char c, s[MAXLEN], t[MAXLEN];
    char tt[MAXLEN], ss[MAXLEN];

//    printf("enter test string for escape()\n");
//    for (i = 0; (c = getchar()) != EOF && i < MAXLEN; ++i)
//        s[i] = c;
//    s[i] = '\0';
//    len = escape(s, t);
//    printf("%s\n", t);

    printf("enter test string for unescape()\n");
    for (i = 0; (c = getchar()) != EOF && i < MAXLEN; ++i)
        tt[i] = c;
    tt[i] = '\0';
    len2 = unescape(tt, ss);
    printf("%s\n", ss);
    
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

int unescape(char tt[], char ss[])
{
    int i, j = 0;
    char c1, c2;

    for (i = 0; (c1 = tt[i + j]) != '\0' && i + j + 1 < MAXLEN; ++i) {
        switch (c1) {
        case '\\':
            ++j;
            c2 = tt[i + j];
            switch (c2) {
            case 't':
                ss[i] = '\t';
                break;
            case 'n':
                ss[i] = '\n';
                break;
            case '\\': case '\0':
                ss[i] = '\\';
                j--;
                break;
            default:
                ss[i] = c1;
                j--;
                break;
            }
            break;
        default:
            ss[i] = c1;
            break;
        }
    }

    ss[i] = '\0';
    return i + j;
}
