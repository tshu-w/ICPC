// written at 16:12 on 2 Mar 2017 
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
const int MAX_V = 2e4 + 10;

int V, cmp[MAX_V], N, S[MAX_V], T[MAX_V], D[MAX_V];
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

int solve() {
    V = 2 * N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j) {
            if (min(S[i] + D[i], S[j] + D[j]) > max(S[i], S[j])) // ¬xi ^ ¬xj 
                add_edge(i, j + N), add_edge(j, i + N);
            if (min(S[i] + D[i], T[j]) > max(S[i], T[j] - D[j])) // ¬xi ^ xj
                add_edge(i, j), add_edge(j + N, i + N);
            if (min(T[i], S[j] + D[j]) > max(T[i] - D[i], S[j])) // xi ^ ¬xj
                add_edge(i + N, j + N), add_edge(j, i);
            if (min(T[i], T[j]) > max(T[i] - D[i], T[j] - D[j])) // xi ^ xj
                add_edge(i + N, j), add_edge(j + N, i);
        }
    scc();
    for (int i = 0; i < N; ++i)
        if (cmp[i] == cmp[i + N]) return printf("NO\n"), 0;
    puts("YES");
    for (int i = 0; i < N; ++i)
        if (cmp[i] > cmp[i + N])
            printf("%02d:%02d %02d:%02d\n", S[i] / 60, S[i] % 60, (S[i] + D[i]) / 60, (S[i] + D[i]) % 60);
        else 
            printf("%02d:%02d %02d:%02d\n", (T[i] - D[i]) / 60, (T[i] - D[i]) % 60, T[i] / 60, T[i] % 60);
    return 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int a, b, c, d;
        scanf("%d:%d %d:%d %d", &a, &b, &c, &d, D + i); 
        S[i] = a * 60 + b;
        T[i] = c * 60 + d;
    }
    solve();
    return 0;
}