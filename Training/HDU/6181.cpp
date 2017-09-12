// written at 12:07 on 24 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, int > Pli;

const ll INF = LLONG_MAX / 3;
const int MAX_V = 1e5 + 5;

struct edge {
    int u, v;
    ll dis;
};
vector<edge> G[MAX_V];
int N, R;
ll dist[MAX_V], dist2[MAX_V];

void solve() {
    priority_queue<Pli, vector<Pli>, greater<Pli> > que;
    fill(dist, dist + N, INF);
    fill(dist2, dist2 + N, INF);
    dist[0] = 0;
    que.push(Pli(0, 0));

    while (!que.empty()) {
        Pli p = que.top(); que.pop();
        int u = p.second;
        ll d = p.first;
        if (dist2[u] < d) continue;
        for (int i = 0; i < (int)G[u].size(); ++i) {
            edge e = G[u][i];
            ll d2 = d + e.dis;
            if (d2 < dist[e.v]) {
                swap(d2, dist[e.v]);
                que.push(Pli(dist[e.v], e.v));
            }
            if (d2 < dist2[e.v] && d2 > dist[e.v]) {
                dist2[e.v] = d2;
                que.push(Pli(dist2[e.v], e.v));
            }
        }
    }
    printf("%lld\n", dist2[N - 1]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &R);
        for (int i = 0; i < N; i++) G[i].clear();
        for (int i = 0; i < R; ++i) {
            int a, b;
            ll d;
            scanf("%d%d%lld", &a, &b, &d);
            --a; --b;
            G[a].push_back(edge{a, b, d});
            G[b].push_back(edge{b, a, d});
        }
        solve();
    }
    return 0;
}
