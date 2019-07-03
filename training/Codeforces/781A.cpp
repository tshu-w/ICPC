// written at 20:57 on 5 Mar 2017 
#include <bits/stdc++.h>

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
const int MAX_V = 2e5 + 10;

int V, color[MAX_V], k;
vector<int> G[MAX_V];

int dfs(int v, int p, int pp) {
    int cur = 1;
    while (cur == color[v] || cur == color[p]) cur++;
    for (int i = 0; i < G[v].size(); i++)
        if (G[v][i] != p) {
            color[G[v][i]] = cur++;
            k = max(k, dfs(G[v][i], v, p));
            k = max(k, cur - 1);
            while (cur == color[v] || cur == color[p]) cur++;
        }
    return k;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &V);
    for (int i = 0; i < V - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
    }
    color[1] = 1; k = 1;
    printf("%d\n", dfs(1, 0, 0));
    for (int i = 1; i <= V; i++)
        printf("%d%c", color[i], " \n"[i == V]);
    return 0;
}