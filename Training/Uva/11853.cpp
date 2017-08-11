// written at 10:52 on 11 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e3 + 10;
const int W = 1000.0;

int n, x[maxn], y[maxn], r[maxn];
bool vis[maxn];
double lft, rgh;

bool intersect(int c1, int c2) {
    return sqrt(sqr(x[c1] - x[c2]) + sqr(y[c1] - y[c2])) <= r[c1] + r[c2];
}

void check_circle(int u) {
    if (x[u] <= r[u]) lft = min(lft, y[u] - sqrt(sqr(r[u]) - sqr(x[u])));
    if (x[u] + r[u] >= W) rgh = min(rgh, y[u] - sqrt(sqr(r[u]) - sqr(W - x[u])));
}

bool dfs(int i) {
    if (vis[i]) return false;
    vis[i] = true;
    if (y[i] <= r[i]) return true;
    for (int j = 0; j < n; j++)
        if (i != j && intersect(i, j) && dfs(j)) return true;
    check_circle(i);
    return false;
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) scanf("%d%d%d", x + i, y + i, r + i);
        memset(vis, false, sizeof vis); lft = rgh = W;
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (y[i] + r[i] >= W && dfs(i)) {
                flag = false;
                break;
            }
        if (flag) printf("0.00 %.2f 1000.00 %.2f\n", lft, rgh);
        else puts("IMPOSSIBLE");
    }
    return 0;
}
