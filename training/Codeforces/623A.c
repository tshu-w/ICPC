#include "stdio.h"
#include "string.h"

int n, m, g[510][510], u, v, f[510], tag[510], tape = 0, fa[5], num[5];
int find(int x)
{
    if ( x != f[x])
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
int main(int argc, char const *argv[])
{
    memset(g, 0, sizeof(g));
    memset(tag, 0, sizeof(tag));
    memset(num, 0, sizeof(num));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u][0]++;
        g[u][g[u][0]] = v;
        g[v][0]++;
        g[v][g[v][0]] = u;
    }
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= n; i++) {
        if(g[i][0] == n - 1) {
            tag[i] = 3;
            num[3]++;
        }
    }
    for (int i = 1; i <= n; i++)
        if (tag[i] != 3)
        {
            for (int j = 1; j <= g[i][0]; j++)
                if (tag[g[i][j]] != 3) {
                    f[i] = find(i);
                    f[g[i][j]] = find(g[i][j]);
                    if (f[i] != f[g[i][j]]) {
                        f[g[i][j]] = f[i];
                    }
                }
        }

    // for (int i = 1; i <= n; i++) {
    //      printf("%d: %d %d\n", i, f[i], find(i));
    // }

    for (int i = 1; i <= n && tape < 3; i++)
        if (tag[i] != 3) {
            int pa = find(i);
            if (tape == 0) {
                tape++;
                fa[tape] = pa;
                tag[i] = tape;
                num[1]++;
            }
            else {
                int flag = 1;
                for (int j = 1; j <= tape; j++)
                    if (pa == fa[j]) {
                        tag[i] = j;
                        if (j == 1) num[1]++;
                            else num[2]++;
                        flag = 0;
                    }
                if (flag) {
                    tape++;
                    fa[tape] = pa;
                    tag[i] = tape;
                    if (tape == 2) num[2]++;
                }
            }
        }

    // for (int i = 1; i <= n ; ++i)
    // {
    //     printf("%d : %d\n", i, tag[i]);
    // }
    // printf("%d %d %d\n", num[1], num[2], num[3]);

    int flag = 1;
    if (num[1] + num[2] + num[3] != n) flag = 0;
    for (int i = 1; i <= n && flag; i++) 
        if (tag[i] == 1) {
            if (n - num[2] - 1!= g[i][0])
                flag = 0;
        }
        else 
            if (tag[i] == 2) {
                if (n - num[1] - 1!= g[i][0])
                    flag = 0;
            }

    if (tape < 3 && flag) {
        puts("Yes");
        for (int i = 1; i <= n; i++)
            switch (tag[i]) {
                case 1 : putchar('a');break;
                case 2 : putchar('c');break;
                case 3 : putchar('b');break;
            }
        printf("\n");
    }
    else
        puts("No");
    return 0;
}