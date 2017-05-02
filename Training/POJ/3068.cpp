// written at 23:09 on 22 Jan 2017 
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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_V = 1e3 + 10;

struct edge {int to, cap, cost, rev; };
vector<edge> G[MAX_V];
int V, N, M, cs;
int dist[MAX_V], h[MAX_V], prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}
int min_cost_flow(int s, int t, int f) {
    int res = 0;
    memset(h, 0, sizeof h);
    while (f > 0) {
        fill(dist, dist + V, INF / 3);
        priority_queue<Pii, vector<Pii>, greater<Pii> > que;
        dist[s] = 0; que.push(Pii(0, s));
        while (!que.empty()) {
            Pii p = que.top(); que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            rep(i, 0, G[v].size()) {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v; preve[e.to] = i;
                    que.push(Pii(dist[e.to], e.to));
                }
            }
        }
        if (dist[t] == INF / 3) return -1;
        rep(i, 0, V) h[i] += dist[i];
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

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &N, &M) && N + M) {
        int u, v, c;
        int s = N, t = s + 1;
        V = t + 1;
        rep(i, 0, V) G[i].clear();
        rep(i, 0, M) {
            scanf("%d%d%d", &v, &u, &c);
            add_edge(v, u, 1, c);
        }
        add_edge(s, 0, 2, 0);
        add_edge(N - 1, t, 2, 0);
        int res = min_cost_flow(s, t, 2);
        if (res == -1) printf("Instance #%d: Not possible\n", ++cs);
        else printf("Instance #%d: %d\n", ++cs, res);
    }    
    return 0;
}