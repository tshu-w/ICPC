#include "stdio.h"
#include "math.h"

int main(int argc, char const *argv[])
{
    double n, ans;
    int m;
    while (~scanf("%lf%d", &n, &m)) {
        ans = 0;
        for (int i = 0; i < m; i ++) {
            ans += n;
            n = sqrt(n);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}