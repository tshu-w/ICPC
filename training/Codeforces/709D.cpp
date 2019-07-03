// written at 09:22 on 23 Feb 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e6 + 10;

ll a[10];

int solve() {
    if (a[0] + a[1] + a[2] + a[3] == 0) return puts("0"), 0;
    ll n, m;
    if (a[1] || a[2]) n = m = 1; else n = m = 0;
    while (n * (n - 1) < 2 * a[0]) ++n;
    while (m * (m - 1) < 2 * a[3]) ++m;
    if (n * (n - 1) != 2 * a[0] || m * (m - 1) != 2 * a[3] || m * n != a[1] + a[2]) 
        return puts("Impossible"), 0;
    while (a[1] || a[2]) {
        while (a[1] >= m) printf("0"), --n, a[1] -= m; if (!n) break;
        while (a[2] >= n) printf("1"), --m, a[2] -= n; if (!m) break;
    }
    while (n--) printf("0");
    while (m--) printf("1");
    puts("");
    return 0;
}

int main(int argc, char const *argv[])
{
    rep(i, 0, 4) cin >> a[i];
    solve();
    return 0;
}