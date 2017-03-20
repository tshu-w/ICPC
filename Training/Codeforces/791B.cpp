// written at 23:07 on 18 Mar 2017
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
const int MAX_N = 150000 + 10;

int n, m, cnt[MAX_N][2];
Pii P[MAX_N];
int par[MAX_N];
int rnk[MAX_N];
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

int main() {
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        --a, --b;
        scanf("%d%d", &a, &b);
        P[i] = Pii(a, b);
        unite(a, b);
    }
    for (int i = 0; i < m; i++) {
        int fa = find(P[i].first);
        cnt[fa][1]++;
    }
    for (int i = 0; i < n; i++) {
        int fa = find(i);
        cnt[fa][0]++;
    }
    for (int i = 0; i < n; i++) 
        if ((ll)(cnt[i][0] - 1)* cnt[i][0] != (ll)2 * cnt[i][1])
            return printf("NO"), 0;
    printf("YES");
    return 0;
}