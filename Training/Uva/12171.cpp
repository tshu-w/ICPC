// written at 16:49 on 09 Aug 2017
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

const int maxn = 50 + 5;
const int maxm = 2 * maxn;
const int mc = 1001;

int t, n;
int x[maxn][2], y[maxn][2], z[maxn][2];

int xsn, ysn, zsn;
int xs[maxm], ys[maxm], zs[maxm];

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
int color[maxm][maxm][maxm];

struct Cell {
    int x, y, z;
    Cell(int x = 0, int y = 0, int z = 0):x(x), y(y), z(z) {}
    bool isValid() { return 0 <= x && x + 1 < xsn && 0 <= y && y + 1 < ysn && 0 <= z && z + 1 < zsn;}
    bool isSolid() { return color[x][y][z] == 1;}
    void setVis() { color[x][y][z] = 2;}
    bool isVis() { return color[x][y][z] == 2;}
    Cell neighbor(int i) {return Cell(x + dx[i], y + dy[i], z + dz[i]);}
    int volume() {return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);}
    int area(int i) {
        if (dx[i]) return (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
        else if (dy[i]) return (xs[x + 1] - xs[x]) * (zs[z + 1] - zs[z]);
        else return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
    }
};

void discretize(int *x, int &n) {
    sort(x, x + n);
    n = unique(x, x + n) - x;
}

int ID(int *x, int n, int x0) {
    return lower_bound(x, x + n, x0) - x;
}

void floodfill(int &v, int &s) {
    v = s = 0;
    Cell c;
    queue<Cell> que;
    que.push(c); c.setVis();
    while (!que.empty()) {
        c = que.front(); que.pop();
        v += c.volume();
        for (int i = 0; i < 6; i++) {
            Cell nc = c.neighbor(i);
            if (!nc.isValid()) continue;
            if (nc.isSolid()) s += c.area(i);
            else if (!nc.isVis()) {
                que.push(nc);
                nc.setVis();
            }
        }
    }
    v = mc * mc * mc - v;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        xsn = ysn = zsn = 2;
        xs[0] = ys[0] = zs[0] = 0;
        xs[1] = ys[1] = zs[1] = mc;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++)
                scanf("%d%d%d", x[i] + j, y[i] + j, z[i] + j);
            x[i][1] += x[i][0]; y[i][1] += y[i][0]; z[i][1] += z[i][0];
            xs[xsn++] = x[i][0]; xs[xsn++] = x[i][1];
            ys[ysn++] = y[i][0]; ys[ysn++] = y[i][1];
            zs[zsn++] = z[i][0]; zs[zsn++] = z[i][1];
        }
        discretize(xs, xsn);
        discretize(ys, ysn);
        discretize(zs, zsn);

        memset(color, 0, sizeof color);
        for (int i = 0; i < n; i++) {
            int X1 = ID(xs, xsn, x[i][0]), X2 = ID(xs, xsn, x[i][1]);
            int Y1 = ID(ys, ysn, y[i][0]), Y2 = ID(ys, ysn, y[i][1]);
            int Z1 = ID(zs, zsn, z[i][0]), Z2 = ID(zs, zsn, z[i][1]);
            for (int X = X1; X < X2; X++)
                for (int Y = Y1; Y < Y2; Y++)
                    for (int Z = Z1; Z < Z2; Z++)
                        color[X][Y][Z] = 1;
        }

        int v, s;
        floodfill(v, s);
        printf("%d %d\n", s, v);
    }
    return 0;
}
