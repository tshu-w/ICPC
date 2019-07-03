// written at 14:58 on 13 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1000 + 10;
const int INF = INT_MAX / 3;

struct edge {int to, cap, cost, rev; };

int V, E, sum;
vector<edge> G[maxn];
int prevv[maxn], preve[maxn], dist[maxn];
bool vis[maxn];

void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while (f > 0) {
        for (int i = 0; i < V; i++) dist[i] = INF, vis[i] = false;
        queue<int> que;
        dist[s] = 0; que.push(s); vis[s] = true;
        while (!que.empty()) {
            int v = que.front(); que.pop();
            vis[v] = false;
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    if (!vis[e.to]) {
                        que.push(e.to); vis[e.to] = true;
                    }
                }
            }
        }
        if (dist[t] >= 0) return res;
        int d = f;
        for (int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d * dist[t];
        for (int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main() {
    while (~scanf("%d%d", &V, &E)) {
        sum = 0;
        for (int i = 0; i < V + 2; i++) G[i].clear();
        memset(prevv, 0, sizeof prevv);
        memset(preve, 0, sizeof preve);

        for (int i = 1, a, b, c, d; i <= V; i++) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            sum += a;
            add_edge(0, i, b, a);
            add_edge(i, V + 1, d, -c);
        }
        V += 2;
        for (int i = 0, u, v, k; i < E; i++) {
            scanf("%d%d%d", &u, &v, &k);
            add_edge(u, v, sum, k);
            add_edge(v, u, sum, k);
        }
        printf("%d\n", -min_cost_flow(0, V - 1, INF));
    }
    return 0;
}
