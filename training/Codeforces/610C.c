#include "stdio.h"

int main(int argc, char const *argv[])
{
    int vt[1<<9][1<<9];
    int n;
    scanf("%d", &n);
    vt[0][0] = 1;
    for (int i = 0; i < 9; i++) {
        int k = 1 << i;
        for (int r = 0; r < k; r++)
            for (int c = 0; c < k; c++) {
                vt[r][c + k] = vt[r + k][c] = vt[r][c];
                vt[r+k][c+k] = !vt[r][c];
            }
    }
    n = 1 << n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            putchar( (vt[i][j])? '+' : '*');
        puts("");
    }
    return 0;
}