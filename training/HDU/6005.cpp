// written at 09:13 on 04 May 2017
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

const int MAX_N = 4000 + 10;
const int INF = INT_MAX / 3;

struct edge {
    int from;
    int to, dis;
    edge(int _from = 0, int _to = 0, int _dis = 0) {
        from = _from;
        to = _to;
        dis = _dis;
    }
};

int t, m, n, dist[MAX_N], ans;
map<Pii, int> node;
vector<edge> G[MAX_N];
edge dl, es[MAX_N];

void dijkstra(int s, int add) {
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;// fisrt 是最短距离，second 是顶点编号
    fill(dist + 1, dist + n + 1, INF);
    dist[s] = 0; que.push(Pii(0, s));
    while (!que.empty()) {
        Pii p = que.top(); que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        if (dist[v] + add >= ans) return;
        for (int i = 0; i < (int)G[v].size(); i++) {
            edge e = G[v][i];
            if (dist[e.to] > dist[v] + e.dis) {
                dist[e.to] = dist[v] + e.dis;
                que.push(Pii(dist[e.to], e.to));
            }
        }
    }
}

int main(void) {
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        n = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int w; Pii p1, p2;
            scanf("%d%d%d%d%d", &p1.first, &p1.second, &p2.first, &p2.second, &w);
            if (node[p1] == 0) node[p1] = ++n;
            if (node[p2] == 0) node[p2] = ++n;
            G[node[p1]].push_back(edge(node[p1], node[p2], w));
            G[node[p2]].push_back(edge(node[p2], node[p1], w));
            es[i] = edge(node[p1], node[p2], w);
            // cout << node[p1] << "<->" << node[p2] << " " << w << endl;
        }
        ans = INF;
        for (int i = 0; i < m; i++) {
            dl = es[i];
            for (int j = 0; j < (int)G[dl.from].size(); j++)
                if (G[dl.from][j].to == dl.to && G[dl.from][j].dis == dl.dis) {
                    G[dl.from][j].dis = INF;
                    break;
                }
            for (int j = 0; j < (int)G[dl.to].size(); j++)
                if (G[dl.to][j].to == dl.from && G[dl.to][j].dis == dl.dis) {
                    G[dl.to][j].dis = INF;
                    break;
                }

            dijkstra(dl.from, dl.dis);
            ans = min(dist[dl.to] + dl.dis, ans);

            for (int j = 0; j < (int)G[dl.from].size(); j++)
                if (G[dl.from][j].to == dl.to && G[dl.from][j].dis == INF) {
                    G[dl.from][j].dis = dl.dis;
                    break;
                }
            for (int j = 0; j < (int)G[dl.to].size(); j++)
                if (G[dl.to][j].to == dl.from && G[dl.to][j].dis == INF) {
                    G[dl.to][j].dis = dl.dis;
                    break;
                }

        }
        printf("Case #%d: %d\n", _ + 1, ans == INF? 0 : ans);

        for (int i = 1; i <= n; i++) G[i].clear();
        node.clear();
    }
    return 0;
}
