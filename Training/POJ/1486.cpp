// written at 13:33 on 19 Jan 2017
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
const int MAX_V = 1e3 + 10;

struct slide {
    int x1, x2, y1, y2;
}S[MAX_V];
struct  num {
    int x, y;
}A[MAX_V];

bool G[MAX_V][MAX_V];
int V, match[MAX_V], t, mth[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v) {
    G[u][v] = G[v][u] = true;
}
void remove_edge(int u, int v) {
    G[u][v] = G[v][u] = false;
}
bool in(int a, int s) {
    return S[s].x1 < A[a].x && A[a].x < S[s].x2 && S[s].y1 < A[a].y && A[a].y < S[s].y2;
}
bool dfs(int v) {
    used[v] = true;
    rep(i, 0, 2 * V) if(G[v][i]) {
        int u = i, w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}
int bipartite_match() {
    int res = 0;
    memset(match, -1, sizeof match);
    rep(v, 0, 2 * V) if (match[v] < 0) {
        memset(used, false, sizeof used);
        if (dfs(v)) ++res;
    }
    return res;
}

void solve(int t) {
    memset(G, false, sizeof G);
    rep(a, 0, V)
    rep(s, 0, V) if (in(a, s)) {
        add_edge(a, s + V);
    }
    printf("Heap %d\n", t);
    if (bipartite_match() < V)
        printf("none\n");
    else {
        bool f = false;
        rep(i, 0, 2 * V) mth[i] = match[i];
        rep(i, 0, V) {
            remove_edge(i + V, mth[i + V]);
            if (bipartite_match() == V) continue;
            else {
                if (f) printf(" ");
                printf("(%c,%d)", 'A' + i, mth[i + V] + 1);
                f = true;
            }
            add_edge(i + V, mth[i + V]);
        }
        if (!f) printf("none\n");
        else printf("\n");
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    while (scanf("%d", &V) && V) {
        rep(i, 0, V)
        scanf("%d%d%d%d", &S[i].x1, &S[i].x2, &S[i].y1, &S[i].y2);
        rep(i, 0, V)
        scanf("%d%d", &A[i].x, &A[i].y);
        solve(++t);
    }
    return 0;
}