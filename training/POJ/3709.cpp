// written at 15:01 on 28 Feb 2017 
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
const int MAX_N = 5e5 + 10;

int t, n, k, deq[MAX_N];
ll a[MAX_N], S[MAX_N], dp[MAX_N];

ll f(int j, int x) {
    return -a[j] * x + dp[j] - S[j] + a[j] * j;
}
bool check(int f1, int f2, int f3) {
    ll a1 = -a[f1], b1 = dp[f1] - S[f1] + a[f1] * f1;
    ll a2 = -a[f2], b2 = dp[f2] - S[f2] + a[f2] * f2;
    ll a3 = -a[f3], b3 = dp[f3] - S[f3] + a[f3] * f3;
    return (a2 - a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2);
}
void solve() {
    rep(i, 0, n) S[i + 1] = S[i] + a[i];

    int s = 0, t = 1;
    deq[0] = 0;
    dp[0] = 0;
    for (int i = k; i <= n; ++i) {
        if (i - k >= k) {
            while (s + 1 < t && check(deq[t - 2], deq[t - 1], i - k)) t--;
            deq[t++] = i - k;
        }
        while (s + 1 < t && f(deq[s], i) >= f(deq[s + 1], i)) s++;
        dp[i] = S[i] + f(deq[s], i);
    }
    printf("%lld\n", dp[n]);
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        rep(i, 0, n) scanf("%lld", a + i);
        solve();
    } 
    return 0;
}