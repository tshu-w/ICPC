// written at 16:31 on 15 Mar 2017 
#include <bits/stdc++.h>

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
const int MAX_N = 3e4 + 10;

struct edge { 
    int to, damage, length, next;
};
int G[MAX_N], En, N, M, T;
edge E[MAX_N * 2];

void add_edge(int from, int to, int damage, int length) {
    edge e = {to, damage, length, G[from]};
    E[En] = e;
    G[from] = En++;
}

int ans, subtree_size[MAX_N];
bool flag[MAX_N];

int s, t;
Pii ds[MAX_N];

int compute_subtree_size(int v, int p) {
    int c = 1;
    for (int j = G[v]; ~j; j = E[j].next) {
        int w = E[j].to;
        if (w == p || flag[w]) continue;
        c += compute_subtree_size(w, v);
    }
    return subtree_size[v] = c;
}

Pii search_centroid(int v, int p, int t) {
    Pii res = Pii(INT_MAX, -1);
    int s = 1, m = 0;
    for (int j = G[v]; ~j; j = E[j].next) {
        int w = E[j].to;
        if (w == p || flag[w]) continue;
        res = min(res, search_centroid(w, v, t));
        m = max(subtree_size[w], m);
        s += subtree_size[w];
    }
    m = max(m, t - s);
    res = min(res, Pii(m, v));
    return res;
}

void enumrate_path(int v, int p, int damage, int length) {
    ds[t++] = Pii(damage, length);
    for (int j = G[v]; ~j; j = E[j].next) {
        int w = E[j].to;
        if (w == p || flag[w]) continue;
        if (damage + E[j].damage <= M) {
            enumrate_path(w, v, damage + E[j].damage, length + E[j].length);
        }
    }
}

void remove_useless(int s, int &t) {
    if (s == t) return;
    int tt;
    for (int i = tt = s + 1; i < t; i++) {
        if (ds[i].first == ds[tt - 1].first) continue;
        if (ds[i].second <= ds[tt - 1].second) continue;
        ds[tt++] = ds[i];
    }
    t = tt;
}

void solve_sub_problem(int v) {
    compute_subtree_size(v, -1);
    int c = search_centroid(v, -1, subtree_size[v]).second;
    flag[c] = true;
    for (int j = G[c]; ~j; j = E[j].next) {
        if (flag[E[j].to]) continue;
        solve_sub_problem(E[j].to);
    }

    s = t = 0;
    for (int j = G[c]; ~j; j = E[j].next) {
        int w = E[j].to;
        if (flag[w]) continue;
        if (E[j].damage <= M)
            enumrate_path(w, v, E[j].damage, E[j].length);
        if (s > 0) {
            sort(ds + s, ds + t);
            remove_useless(s, t);
            for (int l = 0, r = t - 1; l < s && r >= s; l++) {
                while (r >= s && ds[l].first + ds[r].first > M) r--;
                if (r >= s)
                    ans = max(ans, ds[l].second + ds[r].second);
            }
        }
        sort(ds, ds + t);
        remove_useless(0, t);
        s = t;
    }

    flag[c] = false;
}

int solve() {
    solve_sub_problem(0);
    return ans;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &T);
    for (int _ = 0; _ < T; _++) {
        ans = 0;
        En = 0;
        memset(G, -1, sizeof G);
        memset(flag, false, sizeof flag);
        scanf("%d%d", &N, &M);
        for (int i = 1; i < N; i++) {
            int u, v, damage, length;
            scanf("%d%d%d%d", &u, &v, &damage, &length);
            --u, --v;
            add_edge(u, v, damage, length);
            add_edge(v, u, damage, length);
        }
        printf("Case %d: %d\n", _ + 1, solve());
    } 
    return 0;
}