// written at 14:27 on 12 Aug 2017
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

const int maxn = 1e2 + 10;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, vis[maxn][maxn], res, cnt;
char s[maxn][maxn];
int buff[maxn][maxn];

void dfs(int x, int y, int c) {
    vis[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int xx = x + dx[d], yy = y + dy[d];
        if (0 <= xx && xx < n && 0 <= yy && y < m && !vis[xx][yy] && buff[xx][yy] == c)
            dfs(xx, yy, c);
    }
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; i++)
            scanf("%s", s[i]);
        memset(vis, false, sizeof vis);
        memset(buff, 0, sizeof buff);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                buff[i + 1][j + 1] = s[i][j] - '0';
            }
        n = n + 2; m = m + 2;
        int res = 0, cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j]) {
                    if (buff[i][j]) cnt++;
                    else res++;
                    dfs(i, j, buff[i][j]);
                }
        if (cnt != 1) printf("-1\n");
        else if (res == 1) printf("1\n");
        else if (res == 2) printf("0\n");
        else printf("-1\n");
    }
    return 0;
}
