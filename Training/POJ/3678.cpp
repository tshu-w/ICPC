// written at 16:55 on 2 Mar 2017 
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
const int MAX_V = 1e3 + 10;

int V, E, cmp[MAX_V], N;
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

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &E); V = 2 * N;
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        char opt[5];
        scanf("%d%d%d%s", &a, &b, &c, opt);
        if (opt[0] == 'A') {
            if (c) 
                add_edge(a + N, a), add_edge(b + N, b);
            else add_edge(a, b + N), add_edge(b, a + N); 
        }
        if (opt[0] == 'O') {
            if (c)
                add_edge(a + N, b), add_edge(b + N, a);
            else 
                add_edge(a, a + N), add_edge(b, b + N);
        }
        if (opt[0] == 'X') {
            if (c)
                add_edge(a, b + N), add_edge(b, a + N), add_edge(a + N, b), add_edge(b + N, a);
            else 
                add_edge(a + N, b + N), add_edge(a, b), add_edge(b + N, a + N), add_edge(b, a);
        }
    }
    scc();
    for (int i = 0; i < N; ++i)
        if (cmp[i] == cmp[i + N]) 
            return printf("NO\n"), 0;
    printf("YES\n");
    return 0;
}