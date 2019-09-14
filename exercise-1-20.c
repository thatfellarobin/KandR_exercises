#include <stdio.h>

/* The goal of this program is to replace tabs with the proper number of blanks to space to the next tab stop */

#define MAXLINE 1000
#define TABSTOP 30

int gettline(char line[], int lim, int tab);
int mod(int n, int m);

int main()
{
    char line[MAXLINE];
    int len;

    while ((len = gettline(line, MAXLINE, TABSTOP)) > 0)
        if (len > 0) // There was a line
            printf("%s\n", line);

    return 0;
}

int gettline(char s[], int lim, int tab)
{
    int c, i, j;

    for (i = 0; (c = getchar()) != EOF &&
                c != '\n' && 
                i < lim - 1; ++i)
    {
        if (c == '\t') // Errors will occur if tab would exceed maxline
        {
            for (j = 0; j < tab - mod(i, tab); ++j)
                s[i+j] = ' ';
            i = i + j - 1;
        }
        else
            s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int mod(int n, int m)
{
    int div;

    div = n / m;

    return n - (div * m);
}

