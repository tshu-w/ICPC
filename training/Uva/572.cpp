// written at 14:38 on 07 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 100 + 10;

int n, m;
char s[maxn][maxn];
bool vis[maxn][maxn];

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
            int xx = dx + x, yy = dy + y;
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (!vis[xx][yy] && s[xx][yy] == '@') dfs(x + dx, y + dy);
        }
}

int main() {
    while (scanf("%d%d", &n, &m) && n + m) {
        for (int i = 0; i < n; i++)
            scanf("%s", s[i]);
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == '@' && !vis[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
        printf("%d\n", cnt);
    }
    return 0;
}
