// written at 10:47 on 15 Feb 2017 
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
const int MAX_N = 2e5 + 10;

int N, u, v, ans;
vector<int> G[MAX_N];

int dfs(int v, int p) {
    set<int> h;
    for (auto u : G[v]) if (u != p) {
        int res = dfs(u, v);
        if (res == -1) return -1;
        else h.insert(res + 1);
    }
    if (!h.size()) return 0;
    if (h.size() == 1) return *h.begin();
    if (!p && h.size() == 2) return *h.begin() + *h.rbegin();
    u = v; return -1;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    rep(i, 1, N) scanf("%d%d", &u, &v), G[v].push_back(u), G[u].push_back(v);
    u = 0;
    ans = dfs(1, 0);
    if (u) ans = dfs(u, 0);
    while (~ans && !(ans & 1)) ans /= 2;
    printf("%d\n", ans);
    return 0;
}