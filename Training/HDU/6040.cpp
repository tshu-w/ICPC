// written at 19:47 on 25 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<unsigned, int> Pui;

const int MAX_N = 1e7 + 10;
const int MAX_M = 1e2 + 10;

int n, m;
unsigned x, y, z, A[MAX_N], B[MAX_M], C[MAX_M];

unsigned rng61() {
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

int main() {
    int t = 0;
    while (~scanf("%d%d%d%d%d", &n, &m, &x, &y, &z)) {
        printf("Case #%d:", ++t);
        for (int i = 0; i < n; i++)
            A[i] = rng61();
        for (int i = 0; i < m; i++) {
            scanf("%d", B + i);
            C[i] = B[i];
        }
        sort(B, B + m);
        int r = n;
        for (int i = m - 1; i >= 0; i--) {
            nth_element(A, A + B[i], A + r);
            r = B[i];
        }
        for (int i = 0; i < m; i++)
            printf(" %u", A[C[i]]);
        printf("\n");
    }
    return 0;
}
