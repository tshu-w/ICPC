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
const ll LLINF = LLONG_MAX;
const int MAX_V = 1000000 + 10;


template <typename T>
inline T sqr(T a) { return a * a;};

struct edge {
    int from;
    int to, dis;
};
vector<edge> G[MAX_V];
int V, E, dist[MAX_V], t, X[MAX_V], Y[MAX_V], Z[MAX_V];

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

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &V, &E);
        for (int i = 0; i < E; ++i) {
            scanf("%d%d%d", X + i, Y + i, Z + i);
            --X[i]; --Y[i];
        }
        for (int i = 0; i < V; ++i)
            G[i].clear();
        for (int i = 0; i < E; ++i)
            G[X[i]].push_back(edge{X[i], Y[i], Z[i]});
        dijkstra(0);
        ll ans = 0;
        for (int i = 1; i < V; ++i)
            ans += dist[i];
        for (int i = 0; i < V; ++i)
            G[i].clear();
        for (int i = 0; i < E; ++i)
            G[Y[i]].push_back(edge{Y[i], X[i], Z[i]});
        dijkstra(0);
        for (int i = 1; i < V; ++i)
            ans += dist[i];
        printf("%lld\n", ans);
    }    
    return 0;
}