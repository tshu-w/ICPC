// written at 11:41 on 23 Jan 2018
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e5 + 10;
const int INF = INT_MAX;
const int mod = 1e6 + 3;

struct edge {
    int to;
    edge(int _to = -1) : to(_to) {};
};

int N, K;
vector<edge> G[maxn];

bool centroid[maxn];
int subtree_size[maxn], val[maxn], inv[mod + 10], fn;
Pii ans, flag[mod + 10];

void init_inverse() {
    inv[1] = 1;
    for (int i = 2; i < mod + 10; i++)
        inv[i] = (mod - 1ll * (mod / i) * inv[mod % i] % mod) % mod;
}

int compute_subtree_size(int v, int p) {
    int c = 1;
    for (int i = 0; i < SZ(G[v]); i++) {
        edge e = G[v][i];
        if (e.to == p || centroid[e.to]) continue;
        c += compute_subtree_size(e.to, v);
    }
    return subtree_size[v] = c;
}

Pii search_centroid(int v, int p, int t) {
    Pii res = Pii(INF, -1);
    int s = 1, m = 0;
    for (int i = 0; i < SZ(G[v]); i++) {
        int w = G[v][i].to;
        if (w == p || centroid[w]) continue;
        res = min(res, search_centroid(w, v, t));

        m = max(m, subtree_size[w]);
        s += subtree_size[w];
    }
    m = max(m, t - s);
    res = min(res, Pii(m, v));
    return res;
}

void check_satisfaction(int v, int p, int d) {
    if (flag[d].first == fn) {
        if (flag[d].second < v) ans = min(ans, make_pair(flag[d].second, v));
        else ans = min(ans, make_pair(v, flag[inv[d]].second));
    }
    for (int i = 0; i < SZ(G[v]); i++) {
        int w = G[v][i].to;
        if (w == p || centroid[w]) continue;
        check_satisfaction(w, v, (1ll * d * val[G[v][i].to]) % mod);
    }
}

void enumerate_paths(int v, int p, int d) {
    if (flag[d].first == fn) flag[d].second = min(flag[d].second, v);
    else flag[d] = make_pair(fn, v);
    for (int i = 0; i < SZ(G[v]); i++) {
        int w = G[v][i].to;
        if (w == p || centroid[w]) continue;
        enumerate_paths(w, v, (1ll * d * inv[val[G[v][i].to]]) % mod);
    }
}

void solve_subproblem(int v) {
    compute_subtree_size(v, -1);
    int s = search_centroid(v, -1, subtree_size[v]).second;
    centroid[s] = true;

    for (int i = 0; i < SZ(G[s]); i++) {
        if (centroid[G[s][i].to]) continue;
        solve_subproblem(G[s][i].to);
    }

    int res = 1ll * K * inv[val[s]] % mod;
    flag[res] = make_pair(++fn, s);
    for (int i = 0; i < SZ(G[s]); i++) {
        if (centroid[G[s][i].to]) continue;
        check_satisfaction(G[s][i].to, s, val[G[s][i].to]);
        enumerate_paths(G[s][i].to, s, (1ll * res * inv[val[G[s][i].to]]) % mod);
    }

    centroid[s] = false;
}

int main() {
    init_inverse();
    while (~scanf("%d%d", &N, &K)) {
        for (int i = 0; i < N; i++) scanf("%d", val + i), G[i].clear();
        ans = make_pair(INF, INF);
        int x, y;
        for (int i = 1; i < N; i++) {
            scanf("%d%d", &x, &y); --x, --y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        solve_subproblem(0);
        if (ans.first != INF) printf("%d %d\n", ans.first + 1, ans.second + 1);
        else puts("No solution");
    }
    return 0;
}
