// written at 18:11 on 26 Dec 2016 
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

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
const ll INF = LLONG_MAX / 3;
const int MAX_N = 1 << 17;

struct COW
{
    int s, t, c;    
    const bool operator < (const COW &a) const {
        return s < a.s;
    }
}C[MAX_N];

int N, n, S, T, m;
ll dat[2 * MAX_N - 1], dp[MAX_N];

void init(int _n) {
    n = 1 << (32 - __builtin_clz(_n));
    rep(i, 0, 2 * n - 1) dat[i] = INF;
}
void update(int k, ll a) {
    k += n - 1;
    dat[k] = a;
    while (k) {
        k = (k - 1) / 2;
        dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }
}
// query [a, b), index k in [l, r)
// query(a, b, 0, 0, n)
ll query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat[k];
    ll v1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
    ll v2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(v1, v2);
}
void solve() {
    N = T - S + 2;
    fill(dp, dp + N, INF); dp[0] = 0;
    init(N); update(0, 0);
    rep(i, 0, m) {
        scanf("%d%d%d", &C[i].s, &C[i].t, &C[i].c);
        C[i].s -= S, C[i].t -= S; ++C[i].t;
    }
    sort(C, C + m);
    rep(i, 0, m) {
        dp[C[i].t] = min(dp[C[i].t], query(C[i].s, C[i].t + 1, 0, 0, n) + C[i].c);
        update(C[i].t, dp[C[i].t]);
    }
    if (dp[N - 1] == INF) printf("-1\n"); else printf("%lld\n", dp[N - 1]);
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &m, &S, &T);
    solve();
    return 0;
}