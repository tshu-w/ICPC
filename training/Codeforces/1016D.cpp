// written at 22:21 on 03 Aug 2018
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
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

const int maxn = 1e2 + 10;

int n, m, a[maxn], b[maxn], A[maxn][maxn], xr;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i), xr ^= a[i];
    for (int i = 0; i < m; i++) scanf("%d", b + i), xr ^= b[i];
    if (xr) {
        puts("NO");
        return 0;
    }
    puts("YES");
    xr = 0;
    for (int i = 0; i + 1 < m; i++) A[0][i] = b[i], xr ^= b[i]; A[0][m - 1] = a[0] ^ xr;
    for (int i = 1; i < n; i++) A[i][m - 1] = a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%c", A[i][j], " \n"[j + 1 == m]);
    return 0;
}
