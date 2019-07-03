// written at 09:22 on 24 Dec 2016 
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
typedef pair<int, Pii> Piii;

const double pi = acos(-1.0);
const int INF = INT_MAX / 3;
const int MAX_N = 15;
const int MAX_S = 1 << 15;

struct edge {
    int to, c, p, r;
    edge(int _to, int _c = 0, int _p = INF, int _r = INF):to(_to), c(_c), p(_p), r(_r) {}
};

int N, m, dp[MAX_S][MAX_N];
vector<edge> G[MAX_N];

void dijkstra(int s) {
    priority_queue<Piii, vector<Piii>, greater<Piii> > que;
    rep(S, 0, 1 << N) fill(dp[S], dp[S] + N, INF);
    dp[1 << s][s] = 0; que.push(Piii(0, make_pair(1 << s, s)));
    while (!que.empty()) {
        Piii p = que.top(); que.pop();
        int S = p.second.first, v = p.second.second;
        if (dp[S][v] < p.first) continue;
        rep(i, 0, G[v].size()) {
            int u = G[v][i].to;
            if (S >> G[v][i].c & 1) {
                if (dp[S | 1 << u][u] > dp[S][v] + G[v][i].p) {
                      dp[S | 1 << u][u] = dp[S][v] + G[v][i].p;
                      que.push(Piii(dp[S | 1 << u][u], make_pair(S | 1 << u, u)));
                }
            }
              else {
                if (dp[S | 1 << u][u] > dp[S][v] + G[v][i].r) {
                      dp[S | 1 << u][u] = dp[S][v] + G[v][i].r;
                      que.push(Piii(dp[S | 1 << u][u], make_pair(S | 1 << u, u)));
                }
            }
        }
    } 
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &m);
    rep(i, 0, m) {
        int a, b, c, p, r;
        scanf("%d%d%d%d%d", &a, &b, &c, &p, &r); --a, --b, --c;
        G[a].push_back(edge(b, c, p, r));
    }
    dijkstra(0);
    int ans = INF;
    rep(S, 0, 1 << N) ans = min(ans, dp[S][N - 1]);
    if (ans == INF) puts("impossible"); else printf("%d\n", ans);
    return 0;
}