// written at 21:12 on 03 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 60000 + 10;

int t, d[5][5], dis[5][MAX_N], m;
ll k, lw, up;

void dfs(int v, int rem, ll tot) {
    if (tot >= k + m || dis[v][rem]) return;
    int u;
    dis[v][rem] = 1;
    u = v - 1; if (u == 0) u += 4;
    dfs(u, (rem + d[u][v]) % m, tot + d[u][v]);
    u = v + 1; if (u > 4) u -= 4;
    dfs(u, (rem + d[u][v]) % m, tot + d[u][v]);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%d%d%d%d", &k, &d[1][2], &d[2][3], &d[3][4], &d[4][1]);
        d[2][1] = d[1][2]; d[3][2] = d[2][3]; d[4][3] = d[3][4]; d[1][4] = d[4][1];
        m = 2 * min(d[1][2], d[2][3]);
        lw = k / m * m; up = lw + m;
        memset(dis, 0, sizeof dis);
        dfs(2, 0, 0);
        ll ans = LLONG_MAX;
        for (int i = 0; i < MAX_N; i++)
            if (dis[2][i]) ans = min(ans, i + lw < k? i + up : i + lw);
        printf("%lld\n", ans);
    }
    return 0;
}
