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
#include <bitset>

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_V = 100 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

struct edge {
    int from;
    int to, dis;
};
vector<edge> G[MAX_V];
vector<edge> es;
bool vis[MAX_V];
int V, E, pre[MAX_V], dist[MAX_V];
int cost[MAX_V][MAX_V];

int prime() {
    // fill(dist, dist + V, INF);
    // fill(vis, vis + V, false);
    // dist[0] = 0;
    // int res = 0;
    // while (true) {
    //     int v = -1;
    //     for (int u = 0; u < V; ++u) {
    //         if(!vis[u] && (v == -1 || dist[u] < dist[v])) v = u;
    //     }
    //     if (v == -1) break;
    //     vis[v] = true;
    //     res += dist[v];
    //     for (int u = 0; u < V; u++)
    //         dist[u] = min(dist[u], cost[v][u]);
    // }
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;
    int res = 0;
    fill(dist, dist + V, INF);
    fill(vis, vis + V, false);
    dist[0] = 0;
    que.push(Pii(0, 0));
    while (!que.empty()) {
        Pii p = que.top(); que.pop();
        int v = p.second;
        if (vis[v] || dist[v] < p.first) continue;
        res += dist[v]; vis[v] = true;
        for (int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if (dist[e.to] > e.dis) {
                dist[e.to] = e.dis;
                que.push(Pii(dist[e.to], e.to));
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d", &V)) {
        for (int i = 0; i < V; ++i) {
            G[i].clear();
            for (int j = 0; j < V; ++j) {
                int d;
                scanf("%d", &d);
                G[i].push_back(edge{i, j, d});
            }
        }
        printf("%d\n", prime());
    }
    return 0;
}