#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, x, y, ans;
    int mark[2020][2];
    for (int i = 0; i < 2020; i++)
        for (int j = 0; j < 2; j++)
            mark[i][j] = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        mark[y - x + 1000][0]++;
        y = 1000 - y + 1;
        mark[y - x + 1000][1]++;
    }
    for (int i = 0; i < 2020; i++)
        for (int j = 0; j < 2; j++)
            if (mark[i][j] > 1)
                ans += mark[i][j] * (mark[i][j] - 1) / 2;
    printf("%d\n", ans);
    return 0;
}