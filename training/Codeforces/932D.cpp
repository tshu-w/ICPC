// written at 13:59 on 22 Feb 2018
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

const int maxn = 4e5 + 10;
const int maxk = 20;

int Q, pre[maxn][maxk], cnt = 1;
ll t, p, q, last, w[maxn], dp[maxn][maxk];

int main() {
    scanf("%d", &Q);
    memset(pre[0], -1, sizeof pre[0]);
    memset(pre[1], -1, sizeof pre[1]); pre[1][0] = 0;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 0; for (int i = 0; i < 20; i++) dp[0][i] = LLONG_MAX;
    w[1] = 0;
    while (Q--) {
        scanf("%lld%lld%lld", &t, &p, &q);
        p = p ^ last; q = q ^ last;
        // cout << t << "," << p << "," << q << endl;
        if (t == 1ll) {
            w[++cnt] = q;
            dp[cnt][0] = w[cnt];
            if (w[p] >= q) pre[cnt][0] = p;
            else {
                for (int k = 19; p > 0 && k >= 0; k--) {
                    if (pre[p][k] > 0 && w[pre[p][k]] < q) p = pre[p][k];
                }
                pre[cnt][0] = p <= 0 ? 0 : pre[p][0];
            }
            // cout << 0 << " " << pre[cnt][0] << " " << dp[cnt][0] << endl;
            for (int k = 1; k < 20; k++) {
                if (pre[cnt][k - 1] != -1) pre[cnt][k] = pre[pre[cnt][k - 1]][k - 1];
                else pre[cnt][k] = -1;
                if (pre[cnt][k] != -1) dp[cnt][k] = dp[pre[cnt][k - 1]][k - 1] + dp[cnt][k - 1];
                else dp[cnt][k] = LLONG_MAX / 2;
                // cout << k << " " << pre[cnt][k] << " " << dp[cnt][k] << endl;
            }
        } else {
            int ans = 0;
            ll tot = 0;
            for (int k = 19; k >= 0; k--) {
                if (pre[p][k] >= 0 && tot + dp[p][k] <= q) ans += 1 << k, tot += dp[p][k], p = pre[p][k];
            }
            printf("%d\n", ans);
            last = ans;
        }
    }
    return 0;
}
