#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, p, k, left ,right;
    scanf("%d%d%d", &n, &p, &k);
    left = p - k;
    right = p + k;
    if (left > 1)
        printf("<<");
    else
        left = 1;
    for (int i = left; i <= right && i <= n; ++i) {
        if (i != 1)
            printf(" ");
        if (i == p)
            printf("(%d)", i);
        else
            printf("%d", i);
    }
    if (right < n)
        printf(" >>");
    else
        right = n;
    printf("\n");
    return 0;
}
