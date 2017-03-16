// written at 16:23 on 11 Mar 2017 
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
const int MAX_N = 300 + 10;
const int MOD = 1000000000;

char s[MAX_N];
int dp[MAX_N][MAX_N];

int DP(int i, int j) {
    if (i == j) return dp[i][j] = 1;
    if (s[i] != s[j]) return 0;
    if (dp[i][j] >= 0) return dp[i][j];
    int res = 0;
    for (int k = i + 2; k <= j; k++)
        if (s[i] == s[k]) res = (res + (ll)DP(i + 1, k - 1) * (ll)DP(k, j)) % MOD;
    return dp[i][j] = res;
}

int main(int argc, char const *argv[])
{
    while (~scanf("%s", s)) {
        int len = strlen(s);
        memset(dp, -1, sizeof dp);
        printf("%d\n", DP(0, len - 1));
    }
    return 0;
}