// written at 19:44 on 19 Jan 2017 
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
const int MAX_N = 50 + 10;

int V, R, C;
vector<int> G[MAX_V];
int match[MAX_V], g[MAX_N][MAX_N];
bool used[MAX_V];
char mp[MAX_N][MAX_N];

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v) {
    used[v] = true;
    rep(i, 0, G[v].size()) {
        int u = G[v][i], w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}
int bipartite_matching() {
    int res = 0;
    memset(match, -1, sizeof match);
    rep (v, 0, V) 
        if (match[v] < 0) {
            memset(used, false, sizeof used);
            if (dfs(v)) ++res;
        }
    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &R, &C);
    rep(i, 0, R)
        scanf("%s", mp[i]);
    memset(g, -1, sizeof g);
    int t = 0;
    rep(i, 0, R) rep(j, 0, C)
        if (mp[i][j] == '*' && g[i][j] < 0) {
            while (j < C && mp[i][j] == '*' && g[i][j] < 0) g[i][j++] = t;
            ++t;
        }
    //rep(i, 0, R) {
    //    rep(j, 0, C) printf("%d ", g[i][j]);
    //    printf("\n");
    //}
    rep(j, 0, C) rep(i, 0, R) 
        if (mp[i][j] == '*' && g[i][j] >= 0) {
            while (i < R && mp[i][j] == '*' && g[i][j] >= 0) add_edge(g[i++][j], t);
            ++t;
        }
    V = t;
    printf("%d\n", bipartite_matching());
    return 0;
}