// written at 19:59 on 13 Feb 2017 
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
const int MAX_N = 1e3 + 10;
const int MOD = 1e9 + 7;

int N, A[30], l[MAX_N], dp[MAX_N][3];
string s;

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    cin >> s;
    rep(i, 0, 26) scanf("%d", A + i);
    dp[0][0] = 1;
    rep(i, 1, N + 1) {
        dp[i][1] = -INF; dp[i][2] = INF;
        int len = INF;
        irep(j, i, 0) {
            len = min(len, A[s[j] - 'a']);
            if (len < i - j) break;
            dp[i][0] = (dp[i][0] + dp[j][0]) % MOD;
            dp[i][1] = max(dp[i][1], max(i - j, dp[j][1]));
            dp[i][2] = min(dp[i][2], dp[j][2] + 1);
        }
    }
    printf("%d\n%d\n%d\n", dp[N][0], dp[N][1], dp[N][2]);
    return 0;
}
