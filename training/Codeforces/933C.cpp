// written at 19:47 on 14 Feb 2018
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 2e3 + 10;
const int d[] = {1, 2, 1, 2};

int n, a[maxn], dp[maxn][4];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int k = 0; k < 4; k++)
        for (int i = 0; i < n; i++) {
            if (i) dp[i][k] = dp[i - 1][k];
            if (d[k] == a[i]) {
                dp[i][k] = 1;
                for (int j = 0; j < i; j++)
                    if (d[k] == a[j])
                        dp[i][k] = max(dp[i][k], dp[j][k] + 1);
                if (k) {
                    for (int j = 0; j < i; j++)
                        if (d[k - 1] == a[j])
                            dp[i][k] = max(dp[i][k], dp[j][k - 1] + 1);
                }
            }
        }
    // for (int k = 0; k < 4; k++) {
    //     for (int i = 0; i < n; i++) cout << dp[i][k] << " "; cout << endl;
    // }
    int ans = 0;
    for (int k = 0; k < 4; k++) ans = max(dp[n - 1][k], ans);
    cout << ans << endl;
    return 0;
}
