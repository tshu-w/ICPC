#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 30;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
    int t, tt = 0, n, m, minsum[MAX_N][MAX_N], maxsum[MAX_N][MAX_N], a[MAX_N][MAX_N], dp[MAX_N][MAX_N];
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                if (i == 0 && j == 0)
                    minsum[i][j] = maxsum[i][j] = a[i][j];
                else {
                    if (i == 0) 
                        minsum[i][j] = maxsum[i][j] = minsum[i][j - 1] + a[i][j];
                    if (j == 0)
                        minsum[i][j] = maxsum[i][j] = minsum[i - 1][j] + a[i][j];
                    if (i && j) {
                        minsum[i][j] = min(minsum[i - 1][j], minsum[i][j - 1]) + a[i][j];
                        maxsum[i][j] = max(maxsum[i - 1][j], maxsum[i][j - 1]) + a[i][j];
                    }
                }
            }
        }
        // cout << minsum << " " << maxsum << endl;
        int ans = INF;
        for (int i = minsum[n - 1][m - 1]; i <= maxsum[n - 1][m - 1]; ++i) {
            dp[0][0] = sqr((n + m - 1) * a[0][0] - i);
            for (int j = 1; j < n; ++j)
                dp[j][0] = dp[j - 1][0] + sqr((n + m - 1) * a[j][0] - i);
            for (int k = 1; k < m; ++k)
                dp[0][k] = dp[0][k - 1] + sqr((n + m - 1) * a[0][k] - i);
            for (int j = 1; j < n; ++j)
                for (int k = 1; k < m; ++k)
                    dp[j][k] = min(dp[j - 1][k], dp[j][k - 1]) + sqr((n + m - 1) * a[j][k] - i);
            ans = min(ans, dp[n - 1][m - 1]);
            // cout << dp[n - 1][m - 1] << endl;
        }
        cout << "Case #" << ++tt << ": " << ans / (n + m - 1) << endl;
    }
    return 0;
}