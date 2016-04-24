#include <stdio.h>
#include <string.h>
#define MAXN 100005

int main(int argc, const char * argv[]) {
    int ans[MAXN];
    int t, n;

    memset(ans, 0, sizeof(ans));
    for (int i = 1; i < MAXN; i++){
        int x = i, y = i;
        while (x > 0){
            y += x % 10;
            x = x / 10;
        }
        if (ans[y] == 0) ans[y] = i;
    }
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    
    return 0;
}