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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const int INF = INT_MAX;
const int MAX_N = 50005;
const int MAX_V = MAX_N;
const int MAX_E = 100010;

struct edge {
    int u, v;
    int dis;
};
struct Cmp
{
    bool operator ()(const Pii &a, const Pii &b) {
        return a.first < b.first;
    }
};
vector<edge> g[MAX_V];
vector<edge> es;
bool vis[MAX_V];
int d[MAX_V], V, E, d2[MAX_V];

void dijkstra(int s) {
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;// fisrt 是最短距离，second 是顶点编号
    fill(d, d + V, INF);
    fill(d2, d2 + V, INF);
    d[s] = 0;
    que.push(Pii(0, s));
    while (!que.empty()) {
        Pii p = que.top();que.pop();
        int u = p.second;
        if (d2[u] < p.first) continue;
        for (int i = 0; i < g[u].size(); i++) {
            edge &e = g[u][i];
            int dd = p.first + e.dis;
            if (dd < d[e.v]) {
                swap(dd, d[e.v]);
                que.push(Pii(d[e.v], e.v));
            }
            if (dd > d[e.v] && dd < d2[e.v]) {
                d2[e.v] = dd;
                que.push(Pii(d2[e.v], e.v));
            }
        }
    }
}
int main(void) {
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; ++i) {
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        g[u - 1].push_back(edge{u - 1, v - 1, dis});
        g[v - 1].push_back(edge{v - 1, u - 1, dis});
    }
    dijkstra(0);
    printf("%d\n", d2[V - 1]);
    return 0;
}