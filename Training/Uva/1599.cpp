// written at 21:54 on 09 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e5 + 10;
const int INF = INT_MAX;

int n, m;
int dis[maxn], color[maxn];
bool vis[maxn];

struct edge {
    int t, c;
    edge(int t = 0, int c = 0): t(t), c(c) {}
    bool operator < (const edge e) const {
        return c < e.c;
    }
};

vector<edge> G[maxn];

void rbfs(int u) {
    dis[u] = 0; memset(vis, 0, sizeof vis);
    queue<int> que;
    que.push(u); vis[u] = true;
    while (!que.empty()) {
        u = que.front(); que.pop();
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i].t;
            if (!vis[v]) {
                dis[v] = dis[u] + 1;
                que.push(v);
                vis[v] = true;
            }
        }
    }
}

vector<int> ans;

void bfs(int u) {
    ans.clear();
    memset(vis, false, sizeof vis);
    vis[u] = true;

    vector<int> nt; nt.push_back(u);
    for (int i = 0; i < dis[u]; i++) {
        int imin = INF;
        for (int j = 0; j < (int)nt.size(); j++)
            for (int k = 0, u = nt[j]; k < (int)G[u].size(); k++)
                if (dis[G[u][k].t] + 1 == dis[u])
                    imin = min(imin, G[u][k].c);
        ans.push_back(imin);

        vector<int> nt2;
        for (int j = 0; j < (int)nt.size(); j++)
            for (int k = 0, u = nt[j]; k < (int)G[u].size(); k++) {
                int v = G[u][k].t, c = G[u][k].c;
                if (imin == c && !vis[v] && dis[v] + 1 == dis[u]) {
                    nt2.push_back(G[u][k].t);
                    vis[v] = true;
                }
            }
        nt = nt2;
    }
    printf("%d\n", dis[u]);
    for (int i = 0; i < dis[u]; i++) printf("%d%c", ans[i], " \n"[i + 1 == dis[u]]);
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; i++) G[i].clear();
        for (int i = 0, a, b, c; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c); --a, --b;
            G[a].push_back(edge(b, c));
            G[b].push_back(edge(a, c));
        }
        rbfs(n - 1);
        bfs(0);
    }
    return 0;
}
