// written at 13:00 on 13 Mar 2017
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
#include <numeric>

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

const int INF = INT_MAX;
const int MAX_N = 1e4 + 10;

struct edge {
    int to, len;
    edge(int _to = -1, int _len = 0): to(_to), len(_len) {};
};

int N, K, ans;
vector<edge> G[MAX_N];

bool centroid[MAX_N];
int subtree_size[MAX_N];

int compute_subtree_size(int v, int p) {
    int c = 1;
    for (int i = 0; i < (int)G[v].size(); i++) {
        edge e = G[v][i];
        if (e.to == p || centroid[e.to]) continue;
        c += compute_subtree_size(e.to, v);
    }
    return subtree_size[v] = c;
}

Pii search_centroid(int v, int p, int t) {
    Pii res = Pii(INF, -1);
    int s = 1, m = 0;
    for (int i = 0; i < (int)G[v].size(); i++) {
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

void enumerate_paths(int v, int p, int d, vector<int> &ds) {
    ds.push_back(d);
    for (int i = 0; i < (int)G[v].size(); i++) {
        int w = G[v][i].to;
        if (w == p || centroid[w]) continue;
        enumerate_paths(w, v, d + G[v][i].len, ds);
    }
}

int count_pairs(vector<int> &ds) {
    int res = 0;
    sort(ds.begin(), ds.end());
    int j = ds.size();
    for (int i = 0; i + 1 < j; i++) {
        while (j > i + 1 && ds[i] + ds[j - 1] > K) j--;
        res += j - i - 1;
    }
    j = ds.size();
    for (int i = 0; i + 1 < j; i++) {
        while (j > i + 1 && ds[i] + ds[j - 1] >= K) j--;
        res -= j - i - 1;
    }
    j = ds.size();
    return res;
}

bool solve_subproblem(int v) {
    compute_subtree_size(v, -1);
    int s = search_centroid(v, -1, subtree_size[v]).second;
    centroid[s] = true;

    for (int i = 0; i < (int)G[s].size(); i++) {
        if (centroid[G[s][i].to]) continue;
        if (solve_subproblem(G[s][i].to)) return true;
    }

    static vector<int> ds; ds.clear();
    ds.push_back(0);
    for (int i = 0; i < (int)G[s].size(); i++) {
        if (centroid[G[s][i].to]) continue;

        static vector<int> tds; tds.clear();
        enumerate_paths(G[s][i].to, s, G[s][i].len, tds);

        ans -= count_pairs(tds);
        ds.insert(ds.end(), tds.begin(), tds.end());
    }

    ans += count_pairs(ds);
    centroid[s] = false;
    if (ans > 0) return true;
    return false;
}

void solve() {
    ans = 0;
    puts(solve_subproblem(0) ? "AYE" : "NAY");
}

int main() {
    while (scanf("%d", &N), N) {
        for (int i = 0; i < N; i++)
            G[i].clear();
        for (int u = 0; u < N; u++) {
            int v, l;
            while (scanf("%d", &v) && v) {
                --v;
                scanf("%d", &l);
                G[u].push_back(edge{v, l});
                G[v].push_back(edge{u, l});
            }
        }
        while (scanf("%d", &K), K) {
            memset(centroid, 0, sizeof centroid);
            solve();
        }
        puts(".");
    }
    return 0;
}
