// written at 21:25 on 01 Jun 2017
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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 20;

int n, m, l[MAX_N], r[MAX_N], dp[MAX_N][2];
string s[MAX_N];

int min(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

int main(void) {
    cin >> n >> m;
    m = m + 2;
    int k = n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        l[i] = s[i].find_first_of('1');
        r[i] = s[i].find_last_of('1');
        // cout << l[i] << " " << r[i] << endl;
        if (k == n && s[i].find('1') != string::npos)
            k = i;
    }
    dp[k][0] = dp[k][1] = r[k] - l[k];
    for (int i = k + 1; i < n; i++) {
        int len = r[i] - l[i];
        if (s[i].find('1') == string::npos) {
            l[i] = 0; r[i] = m - 1;
        }
        dp[i][0] = min(dp[i - 1][0] + l[i - 1] + 1 + l[i] + 2 * len,
                       dp[i - 1][0] + 2 * m - l[i - 1] - l[i] - 1,
                       dp[i - 1][1] + 2 * m - r[i - 1] - l[i] - 1,
                       dp[i - 1][1] + r[i - 1] + 1 + l[i] + 2 * len
            );
        dp[i][1] = min(dp[i - 1][0] + l[i - 1] + 1 + r[i],
                       dp[i - 1][0] + 2 * m - l[i - 1] - r[i] - 1 + 2 * len,
                       dp[i - 1][1] + 2 * m - r[i - 1] - r[i] - 1 + 2 * len,
                       dp[i - 1][1] + r[i - 1] + 1 + r[i]
            );
        // cout << i << "  " << dp[i][0] << " " << dp[i][1] << endl;
    }
    if (k == n) cout << 0 << endl;
    else cout << min(dp[n - 1][0] + l[n - 1], dp[n - 1][1] + r[n - 1]) << endl;
    return 0;
}
