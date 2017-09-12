// written at 16:53 on 11 Aug 2017
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

const int maxn = 25;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int t, m, n, k, buff[maxn][maxn], dis[maxn][maxn][maxn];
struct Tuple {
    int x, y, o;
    Tuple(int x = 0, int y = 0, int o = 0): x(x), y(y), o(o) {}
};

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        scanf("%d", &k);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", buff[i] + j);
        memset(dis, -1, sizeof dis);
        Tuple s;
        queue<Tuple> que; que.push(s); dis[s.x][s.y][s.o] = 0;
        bool flag = true;
        while (!que.empty()) {
            Tuple u = que.front(); que.pop();
            if (u.x == m - 1 && u.y == n - 1) {
                printf("%d\n", dis[u.x][u.y][u.o]);
                flag = false;
                break;
            }
            for (int d = 0; d < 4; d++) {
                int x = u.x + dx[d], y = u.y + dy[d], o = u.o + (buff[x][y] ? 1 : -u.o);
                if (0 <= x && x < m && 0 <= y && y < n && o <= k && dis[x][y][o] == -1) {
                    dis[x][y][o] = dis[u.x][u.y][u.o] + 1;
                    que.push(Tuple(x, y, o));
                }
            }
        }
        if (flag) printf("-1\n");
    }
    return 0;
}
