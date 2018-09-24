// written at 15:39 on 15 Sep 2018
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

const int maxv = 400 + 10;
const int maxn = 200 + 10;
const int INF = INT_MAX / 3;
struct edge {
    int to, cap, cost, rev;
    edge(int to, int cap, int cost, int rev) :to(to), cap(cap), cost(cost), rev(rev){}
};
vector<edge> G[maxv];
int prevv[maxv], preve[maxv], h[maxv], dist[maxv];
int _, n, k, m, A[maxn], B[maxn], W[maxn];
int V, s, t, p[maxv][maxn];
vector<int> vp;

void add_edge(int from, int to, int cap, int cost) {
    // cout << from << "->" << to << " " << cap << " " << cost << endl;
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}
int min_cost_flow(int s, int t, int f) {
    int res = 0;
    fill(h, h + V, 0);
    while (f > 0) {
        priority_queue<Pii, vector<Pii>, greater<Pii> > que;
        fill(dist, dist + V, INF);
        dist[s] = 0; que.push(Pii(0, s));
        while (!que.empty()) {
            Pii p = que.top(); que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(Pii(dist[e.to], e.to));
                }
            }
        }
        if (dist[t] == INF) return res;
        for (int v = 0; v < V; v++) h[v] += dist[v];
        int d = f;
        for (int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d * h[t];
        for (int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

void init() {
    memset(p, 0, sizeof p); vp.clear();
    for (int i = 0; i < m; i++) vp.push_back(A[i]), vp.push_back(B[i]);
    vp.erase(unique(vp.begin(), vp.end()), vp.end());
    V = vp.size() + 3; s = 0, t = V - 1;
    for (int v = 0; v < V; v++) G[v].clear();
    for (int i = 0; i < vp.size(); i++) {
        for (int j = 0; j < m; j++)
            if (A[j] <= vp[i] && vp[i] <= B[j])
                p[i + 1][j] = 1;
    }
    for (int i = vp.size() + 1; i >= 1; i--)
        for (int j = 0; j < m; j++)
            p[i][j] = p[i][j] - p[i - 1][j];

    add_edge(s, 1, k, 0);
    add_edge(vp.size() + 1, t, k, 0);
    for (int i = 1; i < vp.size() + 1; i++) add_edge(i, i + 1, INF, 0);
    for (int i = 0; i < m; i++) {
        int j = -1, k = -1;
        for (int it = 0; it < vp.size() + 2; it++) {
            if (p[it][i] == 1) j = it;
            if (p[it][i] == -1) k = it;
        }
        if (j != -1 && k != -1) {
            add_edge(j, k, 1, -W[i]);
        }
    }
}

int main() {
    for (scanf("%d", &_); _--; ) {
        scanf("%d%d%d", &n, &k, &m);
        for (int i = 0; i < m; i++) scanf("%d%d%d", A + i, B + i, W + i);
        init();
        printf("%d\n", -min_cost_flow(s, t, INF));
    }
    return 0;
}
