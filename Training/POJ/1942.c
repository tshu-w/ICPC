#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    unsigned long long n, m, i;
    double ans;
    while (scanf("%lld%lld", &n, &m) && m + n) {
        ans = 1.0;
        if (n < m) 
            for (i = 1; i <= n; i++) 
                ans *= (double)(m + i) / (double)i;
        else 
            for (i = 1; i <= m; i++)
                ans *= (double)(n + i) / (double)i;
        printf("%.0f\n", ans); 
    }
    return 0;
}