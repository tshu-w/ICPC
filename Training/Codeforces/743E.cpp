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
const int MAX_N = 1000 + 10;

int N, A[MAX_N], cur[10], dp[MAX_N][1 << 8];
vector<int> in[MAX_N];

int can(int len) {
    if (!len) {
        int res = 0;
        rep(i, 0, 8) if (in[i].size()) ++res;
        return res;
    }
    rep(i, 0, 8) cur[i] = 0;
    rep(i, 0, N + 1) rep(S, 0, 1 << 8) dp[i][S] = -INF;
    dp[0][0] = 0;
    rep(i, 0, N) {
        rep(S, 0, 1 << 8) if (dp[i][S] != -INF)
            rep(k, 0, 8) if (!(S >> k & 1)) {
                int it = cur[k] + len - 1;
                if (it >= in[k].size())
                    continue;
                dp[in[k][it] + 1][S | (1 << k)] = max(dp[in[k][it] + 1][S | (1 << k)], dp[i][S]);
                it++;
                if (it >= in[k].size())
                    continue;
                dp[in[k][it] + 1][S | (1 << k)] = max(dp[in[k][it] + 1][S | (1 << k)], dp[i][S] + 1);
            }
        ++cur[A[i]];
    }
    int ans = -INF;
    rep(i, 0, N + 1)
    ans = max(ans, dp[i][(1 << 8) - 1]);
    if (ans == -INF) return -1;
    return ans * (len + 1) + (8 - ans) * len;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    rep(i, 0, N) scanf("%d", A + i), --A[i], in[A[i]].push_back(i);
    int lb = 0, ub = N / 8 + 1;
    while (lb + 1 < ub) {
        int mid = (lb + ub) >> 1;
        if (~can(mid)) lb = mid;
        else ub = mid;
    }
    printf("%d\n", can(lb));
    return 0;
}