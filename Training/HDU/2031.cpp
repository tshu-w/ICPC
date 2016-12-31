#include "stdio.h"

char s[]="0123456789ABCDEF";
void Hex_Con(long n, long b) {
    char p[100];
    int cases = 0;
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (!n) putchar('0');
    while (n) {
        p[cases++] = s[n % b];
        n /= b;
    }
    for (int i = cases - 1; i >= 0; i --)
        putchar(p[i]);
    putchar('\n');
}
int main(int argc, char const *argv[])
{
    long n, r;
    while (~scanf("%ld%ld", &n, &r))
        Hex_Con( n, r);
    return 0;
}