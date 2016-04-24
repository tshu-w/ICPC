#include "stdio.h"

int work(int n) {
    if (n == 1) return 0;
    int engy = 0;
    if (n % 2) engy = 1;
    return work(n / 2) + work(n - n / 2) + engy;

}
int main (void) {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", work(n));
    }
    return 0;
}