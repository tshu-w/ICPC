// written at 10:05 on 11 Mar 2017 
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
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const char dir[] = {'R', 'L', 'D', 'U'};
const int FOUND = -1;

vector<char> path;
int brd[15][15], t, Ex, Ey;

int H() {
    int h = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (brd[i][j]) {
                int x = (brd[i][j] - 1) / 4;
                int y = (brd[i][j] - 1) % 4;
                h += abs(i - x) + abs(j - y);
            }
    return h;
}

int dfs(int g, int pdir, int bound) {
    int h = H();
    int f = g + h;
    if (f > bound) return f;
    if (h == 0) return FOUND;

    int mn = INF;
    for (int i = 0; i < 4; i++) {
        if (i == (pdir ^ 1)) continue;

        int nx = Ex + dx[i];
        int ny = Ey + dy[i];
        if (nx < 0 || nx >= 4) continue;
        if (ny < 0 || ny >= 4) continue;

        path.push_back(dir[i]);
        swap(brd[nx][ny], brd[Ex][Ey]);
        swap(Ex, nx); swap(Ey, ny);

        int t = dfs(g + 1, i, bound);
        if (t == FOUND) return FOUND;
        if (t < mn) mn = t;
        swap(brd[nx][ny], brd[Ex][Ey]);
        swap(Ex, nx); swap(Ey, ny);
        path.pop_back();
    }

    return mn;
}

bool IDAstar() {
    int bound = H();
    for (;;) {
        int t = dfs(0, -1, bound);
        if (t == FOUND) return true;
        if (t >= 90) return false;
        bound = t;
    }
    return false;
}

bool solvable() {
    int cnt = 0;
    bool occur[16] = {false};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (brd[i][j] == 0)
                Ex = i, Ey = j;
            else {
                cnt += count(occur + 1, occur + brd[i][j], false);
                occur[brd[i][j]] = true;
            }
    return (cnt + Ex + 1) % 2 == 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", brd[i] + j);
        path.clear();
        if (!solvable() || !IDAstar()) {
            puts("This puzzle is not solvable.");
        } else {
            for (char c : path)
                putchar(c);
            puts("");
        }
    } 
    return 0;
}