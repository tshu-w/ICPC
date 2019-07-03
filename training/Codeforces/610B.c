#include "stdio.h"

long long a[200010];
int main(int argc, char const *argv[])
{
    long long n, min, i, nmin, max;
    scanf("%I64d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        if (i == 1) {
            min = a[i];
            nmin = i;
        }
        else
            if (a[i] <= min) {
                min = a[i];
                nmin = i;
            }
    }
    long long pre;
    int flag = 1;
    for (i = 1; i <= nmin; i++)
        if (a[i] == min) {
            if (flag) {
                max = i + n - nmin - 1;
                flag = 0;
            }
            if (i - pre - 1 > max) 
                max = i - pre - 1; 
            pre = i;
        }
    long long ans;
    ans = min * n + max;
    printf("%I64d\n", ans);
    return 0;
}