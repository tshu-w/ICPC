// written at 22:17 on 23 Feb 2017 
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
const int MAX_N = 1e5 + 10;

int N, M, r[MAX_N], x, xi;
vector<int> s[MAX_N];

int par[MAX_N * 2];
int rnk[MAX_N * 2];
void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
}
int find(int x) {
    return par[x] == x? x : par[x] = find(par[x]);
}
bool same(int x, int y) {
    return find(x) == find(y);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &M);
    init(2 * M);
    rep(i, 0, N) scanf("%d", r + i);
    rep(i, 0, M) {
        scanf("%d", &x);
        rep(j, 0, x) {
            scanf("%d", &xi), --xi;
            s[xi].push_back(i);
        }
    }
    rep(i, 0, N) {
        int u = s[i][0], v = s[i][1];
        if (r[i]) unite(u, v), unite(u + M, v + M);
        else unite(u, v + M), unite(u + M, v);
    }
    bool flag = true;
    rep(i, 0, M) if (same(i, i + M)) { flag = false;break;}
    puts(flag? "YES" : "NO");
    return 0;
}