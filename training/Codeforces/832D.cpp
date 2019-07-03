// written at 22:12 on 24 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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

const int MAX_V = 1e5 + 10;
const int MAX_LOG_V = 32 - __builtin_clz(MAX_V);

int n, q, p, a, b, c;
vector<int> G[MAX_V];
int root, parent[MAX_LOG_V][MAX_V], depth[MAX_V];

void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (int i = 0; i < (int)G[v].size(); i++)
        if (G[v][i] != p) dfs(G[v][i], v, d + 1);
}
void init(int V) {
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < MAX_LOG_V; k++)
        for (int v = 0; v < V; v++)
            if (parent[k][v] < 0) parent[k + 1][v] = -1;
            else parent[k + 1][v] = parent[k][parent[k][v]];
}
int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++)
        if ((depth[v] - depth[u]) >> k & 1)
            v = parent[k][v];
    if (u == v) return u;
    for (int k = MAX_LOG_V - 1; k >= 0; k--)
        if (parent[k][u] != parent[k][v]) {
            u = parent[k][u], v = parent[k][v];
        }
    return parent[0][u];
}

int getans(int a, int b, int c) {
    int lc1 = lca(a, b), lc2 = lca(b, c);
    if (lc1 == b && lc2 == b)
        return depth[lca(a, c)] - depth[b];
    if (lc2 == b) swap(lc1, lc2), swap(a, c);
    if (lc1 == b) return 0;
    if (lc1 == lc2) return depth[b] - depth[lc1] + depth[lca(a, c)] - depth[lc2];
    return depth[b] - max(depth[lc1], depth[lc2]);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d", &p);--p;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    root = 0;
    init(n);
    while (q--) {
        scanf("%d%d%d", &a, &b, &c);--a; --b; --c;
        printf("%d\n", max(getans(a, b, c), max(getans(a, c, b), getans(b, a, c))) + 1);
    }
    return 0;
}
