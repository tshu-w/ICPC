// written at 16:08 on 05 May 2017
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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll > Pll;
const int MAX_N = 200 + 10;
const int MAX_LOG_N = 8;

template<typename T> T gcd(T a, T b) {
    //return (b)? gcd(b, a  % b) : a;
    while (b) { T t = a % b; a = b; b = t; } return a;
}
template<typename T> T exgcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b) {
        d = exgcd(b, a % b, y, x);
        y -= a / b * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}
template<typename T> T mod_inverse(T a, T m) {
    T x, y;
    exgcd(a, m, x, y);
    return (m + x % m) % m;
}

std::pair<int, int> linear_congruence(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &M) {
    int x = 0, m = 1;
    for(int i = 0; i < (int)A.size(); i++) {
        int a = A[i] * m, b = B[i] - A[i] * x, d = gcd(M[i], a);
        if(b % d != 0) return std::make_pair(0, -1); // no solutioin
        int t = b / d * mod_inverse(a / d, M[i] / d) % (M[i] / d);
        x = x + m * t;
        m *= M[i] / d;
    }
    while (x < 0) x += m;
    return std::make_pair(x % m, m);
}

Pll CRT(Pll u, Pll v) { // In fact it's linear_congruence.
    if (u.first == -1 || v.first == -1) return Pll(-1, -1);
    __int128 x = u.first % u.second, m = u.second;
    __int128 a = u.second, b = v.first - x, d = gcd(u.second, v.second);
    if (b % d != 0) return Pll(-1, -1);
    __int128 t = b / d * mod_inverse(a / d, v.second / d) % (v.second / d);
    x = x + m * t;
    m *= v.second / d;
    while (x < 0) x += m;
    return Pll(x % m, m);
}

Pll f[MAX_N][MAX_N][MAX_LOG_N][MAX_LOG_N];
int main(void) {
    int t, n, m;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%lld", &f[i][j][0][0].first);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%lld", &f[i][j][0][0].second);

        for (int x = 0; (1 << x) <= n; x++)
            for (int y = 0; (1 << y) <= m; y++)
                for (int i = 0; i + (1 << x) <= n; i++)
                    for (int j = 0; j + (1 << y) <= m; j++) {
                        if (x == 0 && y == 0) continue;
                        if (x == 0)
                            f[i][j][x][y] = CRT(f[i][j][x][y - 1], f[i][j + (1 << (y - 1))][x][y - 1]);
                        else if (y == 0)
                            f[i][j][x][y] = CRT(f[i][j][x - 1][y], f[i + (1 << (x - 1))][j][x - 1][y]);
                        else {
                            f[i][j][x][y] = f[i][j][x - 1][y - 1];
                            f[i][j][x][y] = CRT(f[i][j][x][y], f[i + (1 << (x - 1))][j][x - 1][y - 1]);
                            f[i][j][x][y] = CRT(f[i][j][x][y], f[i][j + (1 << (y - 1))][x - 1][y - 1]);
                            f[i][j][x][y] = CRT(f[i][j][x][y], f[i + (1 << (x - 1))][j + (1 << (y - 1))][x - 1][y - 1]);
                        }
                    }
        int q;
        scanf("%d", &q);
        printf("Case #%d:\n", _ + 1);
        while (q--) {
            int x1, x2, y1, y2, x = 0, y = 0;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            --x1, --y1, --x2, --y2;
            while ((1 << (x + 1)) <= x2 - x1) x++;
            while ((1 << (y + 1)) <= y2 - y1) y++;
            Pll ans = f[x1][y1][x][y];
            ans = CRT(ans, f[x2 - (1 << x) + 1][y1][x][y]);
            ans = CRT(ans, f[x1][y2 - (1 << y) + 1][x][y]);
            ans = CRT(ans, f[x2 - (1 << x) + 1][y2 - (1 << y) + 1][x][y]);
            printf("%lld\n", ans.first);
        }
    }
    return 0;
}
