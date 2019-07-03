// written at 09:28 on 08 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define BREAKPOINT cerr << "Fine" << endl

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

const int maxn = 1e2 + 10;

int n, m, G[maxn][maxn], c[maxn];
int topo[maxn], t;

bool dfs(int u) {
    c[u] = -1;
    for (int v = 1; v <= n; v++)
        if (G[u][v]) {
            if (c[v] < 0) return false;
            else if (!c[v] && !dfs(v)) return false;
        }
    c[u] = 1; topo[--t] = u;
    return true;
}

bool toposort() {
    t = n;
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; i++)
        if (!c[i]) if (!dfs(i)) return false;
    return true;
}

int main() {
    while (~scanf("%d%d", &n, &m) && n + m) {
        memset(G, 0, sizeof G);
        for (int i = 0, u, v; i < m; i++) {
            scanf("%d%d", &u, &v);
            G[u][v] = 1;
        }
        if (toposort())
            for (int i = 0; i < n; i++) printf("%d%c", topo[i], " \n"[i + 1 == n]);
    }
    return 0;
}
