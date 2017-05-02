// written at 18:22 on 16 Jan 2017 
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
const int MAX_V = 500 + 10;
const int MAX_E = 20000 + 10;

vector<int> G[MAX_V];
int V, E, dfn[MAX_V], low[MAX_V], it, root, cnt;
stack<int> st;
bool flag[MAX_V], vis[MAX_V];

bool dfs(int v) {
    int u, sub_tree = 0;
    dfn[v] = low[v] = ++it;
    flag[v] = true;
    st.push(v);
    rep(i, 0, G[v].size()) if (!vis[G[v][i]]) {
        u = G[v][i];
        if (!dfn[u]) {
            ++sub_tree;
            dfs(u);
            low[v] = min(low[v], low[u]);
            if ((v == root && sub_tree > 1) || (v != root && dfn[v] <= low[u]))
                return false;
        } else if (flag[u])
            low[v] = min(low[v], dfn[u]);
    }
    if (low[v] == dfn[v]) ++cnt;
    return true;
}
bool tarjan() {
    cnt = it = 0;
    memset(dfn, 0, sizeof dfn);
    rep(i, 0, V) if (!vis[i])
        if (!dfn[i])
            if (!dfs(root = i)) return false;
    return cnt == 1;
}

bool solve() {
    memset(vis, 0, sizeof vis);
    if (!tarjan()) return false;
    rep(i, 0, V) {
        if (i) vis[i - 1] = false;
        vis[i] = true;
        if (!tarjan()) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &V, &E) && V + E) {
        rep(i, 0, V) G[i].clear();
        rep(i, 0, E) {
            int a, b;
            scanf("%d%d", &b, &a);
            G[a].push_back(b); G[b].push_back(a);
        }
        printf("%s\n", solve() && V >= 4? "YES" : "NO");
    }
    return 0;
}

// bool flag[MAX_V], vis[MAX_V];
// int V, E, match[MAX_V];

// bool dfs(int v, int t) {
//     rep(i, 0, G[v].size()) {
//         int u = G[v][i];
//         if (u == t) {
//             if (flag[v]) continue;
//             flag[v] = true;
//             return true;
//         }
//         if (vis[u]) continue;
//         vis[u] = true;
//         if (dfs(match[u], t)) {
//             match[u] = v;
//             return true;
//         }
//     }
//     return false;
// }

// bool go(int s, int t) {
//     rep(i, 0, V) match[i] = i;
//     memset(flag, 0, sizeof flag);
//     rep(i, 0, 3) {
//         memset(vis, false, sizeof vis);
//         if (!dfs(s, t)) return false;
//     }
//     return true;
// }

// int main(int argc, char const *argv[])
// {
//     while (scanf("%d%d", &V, &E) && V + E) {
//         rep(i, 0, V) G[i].clear(), G[i].push_back(i);
//         rep(i, 0, E) {
//             int a, b;
//             scanf("%d%d", &b, &a);
//             G[a].push_back(b); G[b].push_back(a);
//         }
//         bool f = true;
//         rep(s, 1, V)
//             if (!go(0, s)) {f = false; break;}
//         printf("%s\n", f? "YES" : "NO");
//     }
//     return 0;
// }