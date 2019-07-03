// written at 16:47 on 30 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename "C-small-practice-2"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 50 + 10;
int t, n, k;
double u, P[MAX_N], PP[MAX_N];
double dp[MAX_N][MAX_N];
int main(void)
{
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        double ans = 0;
        cin >> n >> k;
        cin >> u;
        for (int i = 0; i < n; i++)
            cin >> P[i];
        sort(P, P + n);
        for (int i = 0; i < n; i++) {
            double lb = 0.0, ub = 1.0;
            for (int it = 0; it < 100; it++) {
                double mid = (lb + ub) / 2.;
                double sum = 0;
                for (int j = i; j < n; j++)
                    sum += max(0.0, mid - P[j]);
                if (sum >= u) ub = mid;
                else lb = mid;
            }

            for (int j = 0; j < n; j++) PP[j] = P[j];
            double has = u, res = (lb + ub) / 2;
            for (int j = n - 1; j >= 0; j--) {
                if (j >= i) {
                    PP[j] = max(res, PP[j]);
                    has -= PP[j] - P[j];
                } else {
                    PP[j] = min(PP[j] + has, 1.0);
                    has -= PP[j] - P[j];
                }
            }

            // for (int j = 0; j < n; j++)
            //     cout << PP[j] << " ";
            // cout << endl;

            memset(dp, 0, sizeof dp);
            dp[0][0] = 1.;
            for (int j = 0; j < n; j++)
                for (int c = 0; c <= n; c++)
                {
                    dp[j + 1][c] = dp[j][c] * (1 - PP[j]);
                    if (c) dp[j + 1][c] += dp[j][c - 1] * PP[j];
                    // cout << j + 1 << " " << c << " = " << dp[j + 1][c] << endl;
                }
            double tmp = 0.0;
            for (int j = k; j <= n; j++)
                tmp += dp[n][j];
            ans = max(ans, tmp);
        }

        printf("Case #%d: %f\n", _ + 1, ans);
    }
    resetfile();
    return 0;
}
