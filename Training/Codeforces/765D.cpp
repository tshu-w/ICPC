// written at 15:49 on 14 Feb 2017 
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
const int MAX_N = 1e6 + 10;

int n, m;
int f[MAX_N], g[MAX_N], h[MAX_N], cnt[MAX_N]; 
bool flag;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    rep(i, 1, n + 1) scanf("%d", f + i);
    flag = true;
    rep(i, 1, n + 1) if (f[i] != f[f[i]]) { cout << -1 << endl; return 0;}
    rep(i, 1, n + 1) if (i == f[i]) ++m;
    printf("%d\n", m);
    int k = 0;
    rep(i, 1, n + 1) if (f[i] == i) g[i] = ++k;
    rep(i, 1, n + 1) if (f[i] != i) g[i] = g[f[i]];
    rep(i, 1, n + 1) printf("%d%c", g[i], " \n"[i == n]);
    k = 0;
    rep(i, 1, n + 1) if (f[i] == i) h[++k] = i;
    rep(i, 1, m + 1) printf("%d%c", h[i], " \n"[i == m]);
    return 0;
}