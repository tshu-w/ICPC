// written at 15:41 on 17 Jan 2017 
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
const ll INF = LLONG_MAX;
const int MAX_V = 5000 + 10;
const int MAX_E = 60000 + 10;

struct edge { 
    int to, rev;
    ll cap;
    edge(int _to, ll _cap, int _rev): to(_to), cap(_cap), rev(_rev) {}
};
int V, E, level[MAX_V], iter[MAX_V];
bool flag[MAX_V];
vector<edge> G[MAX_V];
ll sum;

void add_edge(int from, int to, ll cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));
}
void bfs(int s) {
    memset(level, -1, sizeof level);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        rep(i, 0, G[v].size()) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
ll dfs(int v, int t, ll f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); ++i) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            ll d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
ll max_flow(int s, int t) {
    ll flow = 0;
    for(;;) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        ll f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int cnt(int v) {
    int res = 1;
    flag[v] = true;
    rep(i, 0, G[v].size())
        if (!flag[G[v][i].to] && G[v][i].cap > 0)
            res += cnt(G[v][i].to);
    return res;
}

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &V, &E);
    const int s = 0, t = ++V;
    rep(i, 1, V) {
        scanf("%d", &a);
        if (a > 0) add_edge(s, i, a), sum += a;
        else if (a < 0) add_edge(i, t, -a);
    }
    rep(i, 0, E) {
        scanf("%d%d", &a, &b);
        add_edge(a, b, INF);
    }
    sum -= max_flow(s, t);
    memset(flag, false, sizeof flag);
    printf("%d %lld\n", cnt(0) - 1, sum);
    return 0;
}