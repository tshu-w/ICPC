// written at 20:33 on 14 Dec 2017
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

const int maxn = 1e4 + 10;
const int INF = INT_MAX;

int t, n, m, x, a[maxn], b[maxn], c[maxn], d[maxn], dist[maxn];

int main() {
    scanf("%d", &t);
    for (int _ = 1; _ <= t; _++) {
        scanf("%d%d%d", &n, &m, &x);
        fill(dist, dist + n, INF);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
            a[i]--, b[i]--, c[i]--, d[i]--;
        }
        dist[0] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i + 1 < n; i++)
                if (dist[i + 1] < INF) dist[i] = min(dist[i], dist[i + 1] - 1);
            for (int i = 0; i < m; i++) {
                if (a[i] == b[i] && c[i] == d[i]) {
                    if (dist[c[i]] < INF) dist[a[i]] = min(dist[a[i]], dist[c[i]] - x);
                    if (dist[a[i]] < INF) dist[c[i]] = min(dist[c[i]], dist[a[i]] + x);
                } else if (a[i] == c[i] && b[i] == d[i]) {
                    cerr << a[i] << "->" << d[i] << " " << x - 1 << endl;
                    if (dist[a[i]] < INF) dist[d[i]] = min(dist[d[i]], dist[a[i]] + x - 1);
                } else {
                    cerr << b[i] << "->" << c[i] << " " << x - 1 << endl;
                    cerr << d[i] << "->" << a[i] << " " << -x - 1 << endl;
                    if (dist[b[i]] < INF) dist[c[i]] = min(dist[c[i]], dist[b[i]] + x - 1);
                    if (dist[d[i]] < INF) dist[a[i]] = min(dist[a[i]], dist[d[i]] - x - 1);
                }
            }
            cerr << "-----------" << endl;
        }
        dprint(dist, dist + n);
        if (dist[0] < 0) printf("Case #%d: IMPOSSIBLE\n", _);
        else {
            printf("Case #%d:", _);
            for (int i = 0; i + 1 < n; i++)
                printf(" %d", dist[i + 1] - dist[i]);
            printf("\n");
        }
    }
    return 0;
}
