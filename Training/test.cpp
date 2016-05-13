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

const double pi = acos(-1.0);

const int INF = INT_MAX;
const int MAX_N = 50005;
const int MAX_V = MAX_N;
const int MAX_E = 100010;

struct edge {
    int u, v;
    int dis;
};
vector<edge> g[MAX_V];
vector<edge> es;
bool vis[MAX_V];
int d[MAX_N], V, E, pre[MAX_V];
int cost[MAX_V][MAX_V];

void dijkstra(int s) {
    //
    // fill(d, d + V, INF);
    // fill(vis, vis + V, false);
    // d[s] = 0;
    // while (true) {
    //     int v = -1;
    //     for (int u = 0; u < V; ++u) 
    //         if (!vis[u] && (v == -1 || d[u] < d[v])) v = u;
    //     if (v == -1) break;
    //     vis[v] = true;
    //     for (int u = 0; u < V; ++u) {
    //         d[u] = min(d[v] + cost[v][u], d[u]);
    //     }
    // }
    //
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;// fisrt 是最短距离，second 是顶点编号
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(Pii(0, s));
    while (!que.empty()) {
        Pii p = que.top();que.pop();
        int u = p.second;
        if (d[u] < p.first) continue;
        for (int i = 0; i < g[u].size(); i++) {
            edge e = g[u][i];
            if (d[e.v] > d[u] + e.dis) {
                d[e.v] = d[u] + e.dis;
                que.push(Pii(d[e.v], e.v));
            }
        }
    } 
}
void bellman_ford(int s) {
    fill(d, d + V, INF);
    d[s] = 0;
    //
    // for (int i = 0; i < V; ++i
    //     for (int j = 0; j < E; ++j) {
    //         int u, v;
    //         u = es[j].u;
    //         v = es[j].v;
    //         if (d[u] != INF)
    //             d[v] = min(d[u] + es[j].dis, d[v]);
    //         if (d[v] != INF)
    //             d[u] = min(d[v] + es[j].dis, d[u]);
    //     }
    //
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
int prim() {
    fill(d, d + V, INF);
    fill(vis, vis + V, false);
    d[0] = 0;
    int res = 0;
    while (true) {
        int v = -1;
        for (int u = 0; u < V; ++u) {
            if(!vis[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if (v == -1) break;
        vis[v] = true;
        res += d[v];
        for (int u = 0; u < V; u++)
            d[u] = min(d[u], cost[v][u]);
    }
    return res;
}
bool cmp(edge &e1, edge &e2) {
    return e1.dis < e2.dis;
}
// int kruskal() {
//     sort(es, es + E, cmp);
//     init(V);
//     int res = 0;
//     for (int i = 0; i < E; ++i) {
//         edge e = es[i];
//         if (!same(e.u, e.v)) {
//             unite(e.u, e.v);
//             res += e.dis;
//         }
//     }
//     return res;
// }
bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return n != 1;
}
vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}
map<int, int> primeFactor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}
int prime[MAX_N];
bool is_prime[MAX_N + 1];
int seive(int n) {
    int p = 0;
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) 
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    return p;
}
const int MAX_L = 1e5, MAX_SQRT_R = 1e3;
bool seg_prime_small[MAX_L];
bool seg_prime[MAX_SQRT_R];
// the number of prime in [L, r)
// 对区间 [l, r）内的整数执行筛法，prime[i - l] = true <=> i 是素数
void segmentSieve(ll l, ll r) {
    for (int i = 0; (ll)i * i < r; ++i) seg_prime_small[i] = true;
    for (int i = 0; i < r - l; ++i) seg_prime[i] = true;
    for (int i = 2; (ll)i * i < r; ++i) {
        if (seg_prime_small[i]) {
            for (int j = 2 * i; (ll)j * j <= r; j += i) seg_prime_small[j] = false;
            for (ll j = max(2LL, (l + i - 1) / i) * i; j < r; j += i) seg_prime[j - l] = false;
        }
    }
}
int main(void) {
    
    return 0;
}
