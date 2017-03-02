// written at 14:29 on 2 Mar 2017 
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
const int MAX_V = 1e4 + 10;

int V, E, cmp[MAX_V], cnt[MAX_V];
vector<int> G[MAX_V], rG[MAX_V], vs;
bool used[MAX_V];

void add_edge(int from, int to) {
    G[from].push_back(to); rG[to].push_back(from);
}
void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++)
        if (!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++)
        if (!used[rG[v][i]]) rdfs(rG[v][i], k);
}

int scc() {
    memset(used, 0, sizeof used);
    vs.clear();
    for (int v = 0; v < V; v++)
        if (!used[v]) dfs(v);
    int k = 0;
    memset(used, 0, sizeof used);
    for (int i = vs.size() - 1; i >= 0; i--)
        if (!used[vs[i]]) rdfs(vs[i], k++);
    for (int v = 0; v < V; v++)
        cnt[cmp[v]]++;
    int num = 0;
    for (int i = 0; i < k; ++i)
        if (cnt[i] >= 2) ++num;
    printf("%d\n", num);
    return k;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &V, &E);
    for (int i = 0, v, u; i < E; ++i) 
        scanf("%d%d", &v, &u), add_edge(v - 1, u - 1);
    scc();
    return 0;
}