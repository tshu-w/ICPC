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

const int INF = INT_MAX;
const int MAX_N = 1005;
const int MAX_V = MAX_N;
// const int MAX_E = ;

struct edge {
    int u, v;
    int dis;
};
bool cmp(const edge &a, const edge &b) {
    return a.dis < b.dis;
}
vector<edge> g[MAX_V];
vector<edge> es;
bool vis[MAX_V];
int d[MAX_N], V, E, pre[MAX_V];
int cost[MAX_V][MAX_V];

void bellman_ford(int s) {
    fill(d, d + V, INF);
    d[s] = 0;
    // for (int i = 0; i < V; ++i)
    //     for (int j = 0; j < E; ++j) {
    //         int u, v;
    //         u = es[j].u;
    //         v = es[j].v;
    //         if (d[u] != INF)
    //             d[v] = min(d[u] + es[j].dis, d[v]);
    //         if (d[v] != INF)
    //             d[u] = min(d[v] + es[j].dis, d[u]);
    //     }
    while (true) {
        bool update = false;
        for (int i = 0; i < E; ++i) {
            edge e = es[i];
            if (d[e.u] != INF && d[e.u] + e.dis < d[e.v]) {
                update = true;
                d[e.v] = d[e.u] + e.dis;
            }
        }
        if (!update) break;
    }
}
void spfa(int s) {
    queue<int> que;
    fill(d, d + V, INF);
    fill(vis, vis + V, false);
    d[s] = 0;
    que.push(s);
    vis[s] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].v;
            if (d[v] > d[u] + g[u][i].dis) {
                d[v] = d[u] + g[u][i].dis;
                if (!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}
int main(void) {
    int n, ml, md;
    scanf("%d%d%d", &n, &ml, &md);
    for (int i = 0; i + 1< n; ++i)
        es.push_back((edge){i + 1, i, 0});
    for (int i = 0; i < ml; ++i) {  
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        es.push_back((edge){u - 1, v - 1, dis});
    }
    for (int i = 0; i  < md; ++i) {
        int u, v, dis;
        scanf("%d%d%d", &v, &u, &dis);
        es.push_back((edge){u - 1, v - 1, -dis});
    }
    V = n;
    E = es.size();
    // vector<edge>::iterator it;
    // for (it = es.begin(); it != es.end(); it = it + 1)
    //     cout << it->u << " " << it->v << " " << it->dis << endl;
    bellman_ford(0);
    // spfa(0);
    // for (int i =0; i < n; ++i)
    //     cout << d[i] << endl;
    if (d[0] < 0)
        printf("%d\n", -1);
    else 
        if (d[n - 1] == INF)
            printf("%d\n", -2);
        else
            printf("%d\n", d[n - 1]);
    return 0;
}
