//#include <bits/stdc++.h>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_V = 50005;
const int MAX_E = 1e6;

struct edge {
    int from;
    int to, dis;
};
vector<edge> G[MAX_V];
vector<edge> es;
bool vis[MAX_V];
int dist[MAX_V], V, E, pre[MAX_V];
int cost[MAX_V][MAX_V];

void dijkstra(int s) {
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;// fisrt 是最短距离，second 是顶点编号
    fill(dist, dist + V, INF);
    dist[s] = 0; que.push(Pii(0, s));
    while (!que.empty()) {
        Pii p = que.top(); que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (dist[e.to] > dist[v] + e.dis) {
                dist[e.to] = dist[v] + e.dis;
                que.push(Pii(dist[e.to], e.to));
            }
        }
    } 
}
void bellman_ford(int s) {
    fill(dist, dist + V, INF);
    dist[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; ++i) {
            edge e = es[i];
            if (dist[e.from] != INF && dist[e.from] + e.dis < dist[e.to]) {
                update = true;
                dist[e.to] = dist[e.from] + e.dis;
            }
        }
        if (!update) break;
    }
}
void spfa(int s) {
    queue<int> que;
    fill(dist, dist + V, INF);
    fill(vis, vis + V, false);
    dist[s] = 0; que.push(s); vis[s] = true;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        vis[v] = false;
        for (int i = 0; i < G[v].size(); ++i) {
            int u = G[v][i].to;
            if (dist[u] > dist[v] + G[v][i].dis) {
                dist[u] = dist[v] + G[v][i].dis;
                if (!vis[u]) {
                    que.push(u);
                    vis[u] = true;
                }
            }
        }
    }
}

int prime() {
    fill(dist, dist + V, INF);
    fill(vis, vis + V, false);
    dist[0] = 0;
    int res = 0;
    while (true) {
        int v = -1;
        for (int u = 0; u < V; ++u) {
            if(!vis[u] && (v == -1 || dist[u] < dist[v])) v = u;
        }
        if (v == -1) break;
        vis[v] = true;
        res += dist[v];
        for (int u = 0; u < V; u++)
            dist[u] = min(dist[u], cost[v][u]);
    }
    /*
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;
    int res;
    fill(dist, dist + V, INF);
    fill(vis, vis + V, false);
    res = dist[0] = 0;
    que.push(Pii(0, s));
    while (!que.empty()) {
        Pii p = que.top(); que.pop();
        int v = p.second;
        if (used[v] || dist[v] < p.first) continue;
        res += dist[v];
        for (int i = 0; i < G[v].size(); ++i) {
            edge e = g[v][i];
            if (dist[e.to] > e.dis) {
                dist[e.to] = e.dis;
                que.push(Pii(dist[e.to], e.to));
            }
        }
    }
    */
    return res;
}
int par[MAX_V];
int rnk[MAX_V];

void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
}
int find(int x) {
    return par[x] == x? x : par[x] = find(par[x]);
}
bool same(int a, int b) {
    return find(a) == find(b);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}
bool cmp(edge &e1, edge &e2) {
    return e1.dis < e2.dis;
}
int kruskal() {
    sort(es.begin(), es.end(), cmp);
    init(V);
    int res = 0;
    for (int i = 0; i < E; ++i) {
        edge e = es[i];
        if (!same(e.from, e.to)) {
            unite(e.from, e.to);
            res += e.dis;
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}