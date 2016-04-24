#include <stdio.h>
#include <string.h>

typedef unsigned long long ULL;
ULL n, ans;
int dfs(ULL num, int k) {
    //printf("%lld\n", num);
    if (num % n == 0) {
        ans = num;
        return 1;
    }
    if (k == 19) return 0;
    if ( dfs(num * 10, k + 1)) return 1;
    if ( dfs(num * 10 + 1, k + 1)) return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
    while (~scanf("%llu", &n) && n) {
        dfs(1, 0);
        printf("%llu\n", ans);
    }
    return 0;
}