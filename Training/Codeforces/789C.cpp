// written at 23:51 on 29 Mar 2017
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
const int MAX_N = 1e5 + 10;

int n, A[MAX_N];
ll dp[MAX_N][2], ans, B[MAX_N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", A + i);
    for (int i = 0; i + 1 < n; i++) 
        B[i] = abs(A[i + 1] - A[i]);
    n--;
    dp[0][0] = B[0]; dp[0][1] = -B[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1] + B[i], B[i]);
        dp[i][1] = max(dp[i - 1][0] - B[i], -B[i]);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}