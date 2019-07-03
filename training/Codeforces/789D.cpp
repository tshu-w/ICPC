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
const int MAX_V = 1e6 + 10;

int V, E;
vector<int> G[MAX_V];
bool flag[MAX_V];

void dfs(int v) {
    flag[v] = true;
    for (auto u: G[v]) if (!flag[u])
        dfs(u);
}

int main() {
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        G[a].push_back(b);
        if (a != b) G[b].push_back(a);
    }
    for (int v = 0; v < V; v++)
        if (G[v].size()) {
            dfs(v);
            break;
        }
    for (int i = 0; i < V; i++) {
        if (!flag[i] && G[i].size()) return printf("0\n"), 0;
    }
    ll ans = 0, res = 0;
    for (int v = 0; v < V; v++) {
        ll tmp = 0;
        for (auto u : G[v]) if (u == v) ++tmp;
        res += tmp;
        tmp = G[v].size() - tmp;
        ans += (tmp - 1) * tmp / 2;
    }
    ans += res * (E - 1);
    ans -= (res - 1) * res / 2;
    cout << ans << endl;
    return 0;
}