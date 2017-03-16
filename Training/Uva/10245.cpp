// written at 13:22 on 12 Mar 2017 
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
typedef pair<int, int> Pii;
typedef pair<double, double> P;

const double pi = acos(-1.0);
const double INF = DBL_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e4 + 10;

int N;
P A[MAX_N];

bool cmp_y(P a, P b) {
    return a.second < b.second;
}

double closest_pair(P *a, int n) {
    if (n <= 1) return INF;
    int m = n / 2;
    double x = a[m].first;
    double d = min(closest_pair(a, m), closest_pair(a + m, n - m));
    inplace_merge(a, a + m, a + n, cmp_y);

    vector<P> b;
    for (int i = 0; i < n; i++) {
        if (fabs(a[i].first - x) >= d) continue;
        for (int j = b.size() - 1; j >= 0; j--) {
            double dx = a[i].first - b[j].first;
            double dy = a[i].second - b[j].second;
            if (dy >= d) break;
            d = min(d, sqrt(dx * dx + dy * dy));
        }
        b.push_back(a[i]);
    }
    return d;
}

void solve() {
    sort(A, A + N);
    double ans = closest_pair(A, N);
    if (ans < 10000.) printf("%.10f\n", ans);
    else printf("INFINITY\n");
}

int main(int argc, char const *argv[])
{
    while (scanf("%d", &N), N) {
        for (int i = 0; i < N; i++)
            scanf("%lf%lf", &A[i].first, &A[i].second);
        solve();
    }
    return 0;
}