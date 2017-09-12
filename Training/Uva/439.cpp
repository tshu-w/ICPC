// written at 16:35 on 11 Aug 2017
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

const int W = 8;
const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int sx, sy, ex, ey, vis[W][W];
char ch1[5], ch2[5];

int main() {
    while (~scanf("%s%s", ch1, ch2)) {
        sx = ch1[0] - 'a'; sy = ch1[1] - '1';
        ex = ch2[0] - 'a'; ey = ch2[1] - '1';
        memset(vis, -1, sizeof vis);
        queue<Pii> que;
        que.push(Pii(sx, sy)); vis[sx][sy] = 0;
        while (!que.empty()) {
            Pii p = que.front(); que.pop();
            if (p == Pii(ex, ey)) {
                printf("To get from %s to %s takes %d knight moves.\n", ch1, ch2, vis[p.first][p.second]);
                break;
            }
            for (int i = 0; i < 8; i++) {
                int x = p.first + dx[i], y = p.second + dy[i];
                if (0 <= x && x < W && 0 <= y && y < W && vis[x][y] == -1) {
                    que.push(Pii(x, y));
                    vis[x][y] = vis[p.first][p.second] + 1;
                }
            }
        }
    }
    return 0;
}
