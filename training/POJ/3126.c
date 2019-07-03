#include <stdio.h>
#include <string.h>

const int num[] = {1, 10, 100, 1000};
int prime[2000], t, n, m, l[2000][2], len_prm, vis[10000];
int main(int argc, char const *argv[])
{
    len_prm = 0;
    for (int i = 1000; i < 10000; i++) {
        int flag = 1;
        for (int j = 2; j * j < i; j++)
            if (i % j == 0) {
                flag = 0;
                break;
            }
        if (flag)
            prime[len_prm++] = i;
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < len_prm; i++)
            vis[prime[i]] = 1;

        int head = 0, tail = 1, flag = 1;
        l[head][0] = n;
        l[head][1] = 0;
        vis[n] = 0;
        while (head < tail) {
            //printf("%d\n", l[head][0]);
            if (l[head][0] == m) {
                flag = 0;
                printf("%d\n", l[head][1]);
            }
            for (int i = 0; i < 4; i++) {
                int cur, k;
                cur = l[head][0];
                k = cur / num[i] % 10;
                while (k > 0) {
                    cur -= num[i];
                    if (vis[cur]) {
                        l[tail][0] = cur;
                        l[tail][1] = l[head][1] + 1;
                        vis[cur] = 0;
                        tail++;
                    }
                    k--;
                }
                cur = l[head][0];
                k = cur / num[i] % 10;
                while (k < 9) {
                    cur += num[i];
                    if (vis[cur]) {
                        l[tail][0] = cur;
                        l[tail][1] = l[head][1] + 1;
                        vis[cur] = 0;
                        tail++;
                    }
                    k++;
                }
            }
            head++;
        }
        if (flag) 
            printf("Impossible\n");
    }
    return 0;
}