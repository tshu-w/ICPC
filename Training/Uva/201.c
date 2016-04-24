#include <stdio.h>
#include <string.h>

int H[10][10];
int V[10][10];

int main(int argc, const char * argv[]) {
    int n, m, x, y,cases = 0;
    char ch[5];
    
    while (~scanf("%d%d", &n, &m)) {
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        for (int i = 0; i < m; i++) {
            scanf("%s%d%d", ch, &x, &y);
            if (ch[0] == 'H') H[x][y] = 1;
            else V[y][x] = 1;
        }
        if (cases++) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", cases);
        int sum = 0;
        for (int l = 1; l <= n;l++) {
            int count = 0, flag = 0;
            for (int i = 1; i + l <= n; i++)
                for (int j = 1; j + l <= n; j++) {
                    flag = 1;
                    for (int r = i; r < i+l && flag; r++)
                        if (!V[r][j] || !V[r][j+l]) flag = 0;
                    for (int c = j; c < j+l && flag; c++)
                        if (!H[i][c] || !H[i+l][c]) flag = 0;
                    count += flag;
                }
            sum += count;
            if (count) printf("%d square (s) of size %d\n", count, l);
        }
        if (!sum) puts("No completed squares can be found.");
    }

    return 0;
}