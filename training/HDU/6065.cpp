// written at 09:33 on 03 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename "1010"
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

const int MAX_N = 3e5 + 10;
const int MAX_LOG_N = 32 - __builtin_clz(MAX_N);
const int INF = INT_MAX / 3;

int n, k, dp[2][MAX_N], A[MAX_N];
vector<int> G[MAX_N];
int root, parent[MAX_LOG_N][MAX_N], depth[MAX_N];

void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (int i = 0; i < (int)G[v].size(); i++)
        if (G[v][i] != p) dfs(G[v][i], v, d + 1);
}
void init(int N) {
    dfs(1, -1, 1);
    for (int k = 0; k + 1 < MAX_LOG_N; k++)
        for (int v = 1; v <= N; v++)
            if (parent[k][v] < 0) parent[k + 1][v] = -1;
            else parent[k + 1][v] = parent[k][parent[k][v]];
}
int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_N; k++)
        if ((depth[v] - depth[u]) >> k & 1)
            v = parent[k][v];
    if (u == v) return u;
    for (int k = MAX_LOG_N - 1; k >= 0; k--)
        if (parent[k][u] != parent[k][v])
            u = parent[k][u], v = parent[k][v];
    return parent[0][u];
}

int main() {
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 0; i < n; i++) scanf("%d", A + i);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        init(n);
        int *cur = dp[1 & 1], *nxt = dp[2 & 1];
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < i - 1; j++) nxt[j] = INF;
            for (int j = i - 1; j < n; j++) {
                int tmp = INF;
                if (j - 1 >= 0) tmp = min(tmp, nxt[j - 1]);
                if (j - 1 >= 0) tmp = min(tmp, cur[j - 1] + depth[A[j]]);
                if (j - 2 >= 0) tmp = min(tmp, cur[j - 2] + depth[lca(A[j - 1], A[j])]);
                nxt[j] = tmp;
                if (j == 0) nxt[j] = depth[A[j]];
            }
            swap(cur, nxt);
        }
        printf("%d\n", cur[n - 1]);
        for (int i = 0; i < n; i++) dp[1 & 1][i] = 0;
        for (int i = 1; i <= n; i++) G[i].clear();
    }
    return 0;
}
