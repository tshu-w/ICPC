// written at 13:59 on 22 Feb 2018
#include <bits/stdc++.h>
using namespace std;

#define g()rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e6 + 10;
const int maxm = 10;

int cnt[maxn][maxm];
map<int, int> f, g;

int F(int x) {
    if (f.count(x)) return f[x];
    int res = 1;
    while (x) {
        if (x % 10) res = res * (x % 10);
        x /= 10;
    }
    return f[x] = res;
}

int G(int x) {
    if (g.count(x)) return g[x];
    if (x < 10) return g[x] = x;
    else return g[x] = G(F(x));
}

int main() {
    for (int i = 0; i < maxn; i++) {
        G(i); cnt[i][g[i]]++;
    }
    for (int j = 0; j < maxm; j++)
        for (int i = 0; i < maxn; i++)
            cnt[i + 1][j] += cnt[i][j];
    int q, l, r, k;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", cnt[r][k] - cnt[l - 1][k]);
    }
    return 0;
}
