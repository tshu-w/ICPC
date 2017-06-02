// written at 21:25 on 01 Jun 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 1e5 + 10;

int n, s, P[MAX_N];
ll A[MAX_N];

int C(int k) {
    for (int i = 0; i < n; i++)
        A[i] = P[i] + (ll)(i + 1) * k;
    sort(A, A + n);
    ll sum = 0;
    for (int i = 0; i < k; i++)
        sum += A[i];
    if (sum > s) return -1;
    else return sum;
}

int main(void) {
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", P + i);
    }
    int lb = 0, ub = n + 1;
    while (lb + 1 < ub) {
        int mid = (lb + ub) / 2;
        if (C(mid) != -1) lb = mid;
        else ub = mid;
    }
    printf("%d %d", lb, C(lb));
    return 0;
}
