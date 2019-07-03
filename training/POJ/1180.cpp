// written at 17:21 on 1 Mar 2017
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
#include <numeric>
#include <set>

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
const int MAX_N = 1e4 + 10;

int n, S, T[MAX_N], F[MAX_N], deq[MAX_N];
ll sf[MAX_N], st[MAX_N], dp[MAX_N];

int f(int j, int x) {
    return -st[j] * sf[x] + dp[j] + st[j] * sf[n];
}
bool check(int f1, int f2, int f3) {
    ll a1 = -st[f1], b1 = dp[f1] + st[f1] * sf[n];
    ll a2 = -st[f2], b2 = dp[f2] + st[f2] * sf[n];
    ll a3 = -st[f3], b3 = dp[f3] + st[f3] * sf[n];
    return (a2 - a1) * (b3 - b2) <= (b2 - b1) * (a3 - a2);
}

void solve() {
    for (int i = 0; i < n; ++i) {
        sf[i + 1] = sf[i] + F[i];
        st[i + 1] = st[i] + T[i];
    }
    // rep(i, 0, n) dp[i] = INF;
    // dp[n] = 0;
    // for (int i = n - 1; i >= 0; --i) {
    //     int res;
    //     for (int j = i + 1; j - i <= 200 && j <= n; ++j) // j - i <= 200 减枝
    //         if (dp[j] + (st[j] - st[i] + S) * (sf[n] - sf[i]) < dp[i]) {
    //             dp[i] = min(dp[i], dp[j] + (st[j] - st[i] + S) * (sf[n] - sf[i]));
    //             res = j;
    //         }
    // }
    int s = 0, t = 1;
    dp[n] = 0; deq[0] = n;
    for (int i = n - 1; i >= 0; --i) {
        while (s + 1 < t && f(deq[s], i) >= f(deq[s + 1], i)) ++s;
        dp[i] = f(deq[s], i) + (S - st[i]) * (sf[n] - sf[i]);
        while (s + 1 < t && check(deq[t - 2], deq[t - 1], i)) --t;
        deq[t++] = i;
    }
    printf("%d\n", dp[0]);
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &S);
    for (int i = 0; i < n; ++i) scanf("%d%d", T + i, F + i);
    solve();
    return 0;
}
