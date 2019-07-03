// written at 14:57 on 2 Mar 2017 
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

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_V = 1e2 + 10;

int V, cmp[MAX_V], in[MAX_V], out[MAX_V];
vector<int> G[MAX_V], rG[MAX_V], vs;
bool flag[MAX_V];

void add_edge(int from, int to) {
    G[from].push_back(to); rG[to].push_back(from);
}
void dfs(int v) {
    flag[v] = true;
    for (int i = 0; i < G[v].size(); i++)
        if (!flag[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v, int k) {
    flag[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++)
        if (!flag[rG[v][i]]) rdfs(rG[v][i], k); 
}
int scc() {
    memset(flag, 0, sizeof flag);
    vs.clear();
    for (int i = 0; i < V; i++)
        if (!flag[i]) dfs(i);
    int k = 0;
    memset(flag, 0, sizeof flag);
    for (int i = vs.size() - 1; i >= 0; --i)
        if (!flag[vs[i]])
            rdfs(vs[i], k++);
    return k;
}
void solve() {
    int n = scc();
    for (int v = 0; v < V; v++)
        for (int i = 0; i < G[v].size(); i++) if (cmp[v] != cmp[G[v][i]]) {
            in[cmp[G[v][i]]]++, out[cmp[v]]++;
        }
    int n1 = 0, n2 = 0;
    for (int i = 0; i < n; ++i) {
        if (!in[i]) ++n1;
        if (!out[i]) ++n2;
    }
    printf("%d\n%d\n", n1, n == 1? 0 : max(n1, n2));
}

int main(int argc, char const *argv[])
{
    scanf("%d", &V);
    for (int i = 0, u; i < V; i++)
        while (scanf("%d", &u), u)
            add_edge(i, u - 1);
    solve();
    return 0;
}