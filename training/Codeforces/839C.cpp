// written at 22:31 on 12 Aug 2017
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

const int maxn = 1e5 + 10;

vector<int> G[maxn];
int n;
double ans;

void dfs(int u, int fa, double p, int d) {
    if (G[u].size() == 1) ans += p * d;
    int m = G[u].size();
    for (int i = 0; i < m; i++)
        if (G[u][i] != fa) {
            if (u == 0)
                dfs(G[u][i], u, p / m, d + 1);
            else dfs(G[u][i], u, p / (m - 1), d + 1);
        }

}

int main() {
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; i++) {
        scanf("%d%d", &u, &v);u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(0, -1, 1, 0);
    printf("%.15f\n", ans);
    return 0;
}
