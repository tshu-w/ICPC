// written at 13:51 on 2 Mar 2017 
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
const int MAX_N = 1e4 + 10;

int N, M, cmp[MAX_N];
vector<int> G[MAX_N], rG[MAX_N], vs;
bool used[MAX_N];

void add_edge(int from, int to) {
    G[from].push_back(to); rG[to].push_back(from);
}
void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i)
        if (!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); ++i)
        if (!used[rG[v][i]]) rdfs(rG[v][i], k); 
}

int scc() {
    memset(used, 0, sizeof used);
    vs.clear();
    for (int v = 0; v < N; ++v)
        if (!used[v]) dfs(v);
    memset(used, 0, sizeof used);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; --i)
        if (!used[vs[i]]) rdfs(vs[i], k++);
    return k;
}

void solve() {
    int n = scc();
    int u = 0, num = 0;
    for (int v = 0; v < N; ++v)
        if (cmp[v] == n - 1) {
            u = v;
            ++num;
        }
    memset(used, 0, sizeof used);
    rdfs(u, 0);
    for (int v = 0; v < N; ++v)
        if (!used[v]) {
            num = 0;
            break;
        }
    printf("%d\n", num);
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &N, &M)) {
        for (int i = 0; i < N; ++i) G[i].clear(), rG[i].clear();
        for (int i = 0, u, v; i < M; ++i) {
            scanf("%d%d", &u, &v), add_edge(u - 1, v - 1); 
        }
        solve();
    }
    return 0;
}