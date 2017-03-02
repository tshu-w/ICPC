// written at 19:14 on 2 Mar 2017 
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

int V, cmp[MAX_V];
vector<int> G[MAX_V], rG[MAX_V], vs;
bool flag[MAX_V];

int N, an, bn, A[MAX_V][2], B[MAX_V][2], X[MAX_V], Y[MAX_V], s[2][2], D;

void add_edge(int from, int to) {
    // cout << from << "->" << to << endl;
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

inline int dis(int i, int t) {
    return abs(X[i] - s[t][0]) + abs(Y[i] - s[t][1]);
}

bool C(const int k) {
    for (int i = 0; i < V; ++i) G[i].clear(), rG[i].clear();
    for (int i = 0; i < an; ++i)
        add_edge(A[i][0], A[i][1] + N), add_edge(A[i][1], A[i][0] + N),
        add_edge(A[i][0] + N, A[i][1]), add_edge(A[i][1] + N, A[i][0]);
    for (int i = 0; i < bn; ++i)
        add_edge(B[i][0], B[i][1]), add_edge(B[i][0] + N, B[i][1] + N),
        add_edge(B[i][1], B[i][0]), add_edge(B[i][1] + N, B[i][0] + N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j) {
            if (dis(i, 0) + dis(j, 0) > k)
                add_edge(i, j + N), add_edge(j, i + N);
            if (dis(i, 1) + dis(j, 1) > k)
                add_edge(i + N, j), add_edge(j + N, i);
            if (dis(i, 0) + dis(j, 1) + D > k)
                add_edge(i, j), add_edge(j + N, i + N);
            if (dis(i, 1) + dis(j, 0) + D > k)
                add_edge(i + N, j + N), add_edge(j, i);
        }
    scc();
    for (int i = 0; i < N; ++i)
        if (cmp[i] == cmp[i + N]) return false;
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &N, &an, &bn);
    scanf("%d%d%d%d", s[0], s[0] + 1, s[1], s[1] + 1);
    D = abs(s[0][0] - s[1][0]) + abs(s[0][1] - s[1][1]);
    V = 2 * N;
    for (int i = 0; i < N; ++i)
        scanf("%d%d", X + i, Y + i);
    for (int i = 0; i < an; ++i)
        scanf("%d%d", A[i], A[i] + 1), --A[i][0], --A[i][1];
    for (int i = 0; i < bn; ++i)
        scanf("%d%d", B[i], B[i] + 1), --B[i][0], --B[i][1];

    int lb = -1, ub = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j)
            for (int k = 0; k < 2; ++k)
                ub = max(ub, dis(i, k) + dis(i, k)),
                ub = max(ub, dis(i, k) + dis(j, 1 - k) + D);
    while (lb + 1 < ub) {
        int mid = (lb + ub) / 2;
        if (C(mid)) ub = mid;
        else lb = mid;
    }
    printf("%d\n", C(ub)? ub : -1);
    return 0;
}