// written at 22:32 on 19 Jan 2017 
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
const ll INF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

ll n, dp[60], a[60][10];
string s;

int main(int argc, char const *argv[])
{
    cin >> n >> s;
    memset(a, -1, sizeof a);
    rep(i, 0, 60) dp[i] = INF;
    rep(i, 0, s.size()) {
        a[i][1] = s[i] - '0';
        if (i) rep(j, 2, 10)
                if (a[i - 1][j - 1] > 0) a[i][j] = a[i - 1][j - 1] * 10 + a[i][1];
        rep(j, 1, 10)
            if (a[i][j] != -1 && a[i][j] < n) {
                if (j == i + 1) dp[i] = a[i][j];
                else if (dp[i - j] <= INF / n) dp[i] = min(dp[i], dp[i - j] * n + a[i][j]);
            }
    }
    cout << dp[s.size() - 1] << endl;
    return 0;
}