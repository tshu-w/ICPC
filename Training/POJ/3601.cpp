#include <iostream>
using namespace std;
const int MAX_N = 10000 + 10;

int t, n, m, A[MAX_N], B[MAX_N], C[MAX_N];// B[] 最底反向， C[] 最底正向

int main(void) {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; i++)
            scanf("%d", A + i);

        B[0] = A[0] % m;
        C[0] = (2 * A[0] - 1 + m) % m;
        for (int i = 1; i < n; i++) {
            B[i] = (B[i - 1] * 2 + A[i]) % m;
            if (A[i] == 1)
                C[i] = B[i];
            else C[i] = (C[i - 1] + A[i] * 2 + B[i - 1] * 2) % m;
        }
        printf("%d\n", C[n - 1]);
    }
    return 0;
}