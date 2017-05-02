#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 10000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int dp[10][MAX_N], t, A, B, cases = 0, d[10];

int dfs(int len, int m, bool flag) {
    if (len < 0) return m >= 0;
    if (m < 0) return 0;
    if (!flag && ~dp[len][m]) return dp[len][m];
    int end = flag? d[len] : 9, res = 0;
    for (int i = 0; i <= end; ++i) {
        res += dfs(len - 1, m - i * (1 << len), flag && i == end);
    }    
    if (!flag) dp[len][m] = res;
    return res;
}

int f(int x) {
    int res = 0, k = 1;
    while (x) {
        res += x % 10 * k;
        k <<= 1;
        x /= 10;
    }    
    return res;
}

void solve() {
    int len = 0;
    while (B) {
        d[len++] = B % 10;
        B /= 10; 
    }
    printf("Case #%d: %d\n", ++cases, dfs(len - 1, f(A), true));
}

int main(int argc, char const *argv[])
{
    memset(dp, -1, sizeof dp);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &A, &B);
        solve();
    }
    return 0;
}