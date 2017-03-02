// written at 17:08 on 27 Feb 2017 
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
const int MAX_N = 1e5 + 10;

int N, w[MAX_N], h[MAX_N], l[MAX_N], r[MAX_N], st[MAX_N], sum[MAX_N];

void solve() {
    int t = 0;
    rep(i, 0, N) {
        while (t > 0 && h[st[t - 1]] >= h[i]) --t;
        l[i] = t? st[t - 1] + 1 : 0;
        st[t++] = i;
    }
    t = 0;
    irep(i, N, 0) {
        while (t > 0 && h[st[t - 1]] >= h[i]) --t;
        r[i] = t? st[t - 1] : N;
        st[t++] = i;
    }
    int ans = 0;
    rep(i, 0, N) ans = max(ans, h[i] * (sum[r[i]] - sum[l[i]]));
    printf("%d\n", ans);
}

int main(int argc, char const *argv[])
{
    while (scanf("%d", &N), N + 1) {
        rep(i, 0, N) scanf("%d%d", w + i, h + i);
        sum[0] = 0;
        rep(i, 0, N) sum[i + 1] = sum[i] + w[i];
        solve();
    } 
    return 0;
}