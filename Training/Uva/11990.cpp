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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 2e5 + 10;
const int MAX_M = 1e5 + 10;
const int B = 450;

struct Bucket
{
    int cnt, sum;
}bucket[B][B];

int N, M, A[MAX_N], xs[MAX_N], ys[MAX_N];
ll ans;

void init() {
    ans = 0;
    memset(xs, -1, sizeof xs);
    memset(ys, -1, sizeof ys);
    memset(bucket, 0, sizeof bucket);
}

void add(int x, int y) {
    xs[y] = x, ys[x] = y;
    int bx = x / B, by = y / B;
    bucket[bx][by].cnt++;
    for (int i = bx + 1; i < B; ++i)
        bucket[i][by].sum++;
}
void remove(int x, int y) {
    xs[y] = -1, ys[x] = -1;
    int bx = x / B, by = y / B;
    bucket[bx][by].cnt--;
    for (int i = bx + 1; i < B; ++i)
        bucket[i][by].sum--;
}

ll count_sum(int x, int y) {
    ll res = 0;
    int bx = x / B, by = y / B;
    for (int i = 0; i < by; ++i)
        res += bucket[bx][i].sum;
    for (int i = bx * B; i <= x; ++i)
        if (ys[i] != -1 && ys[i] < by * B) ++res;
    for (int i = by * B; i <= y; ++i)
        if (xs[i] != -1 && xs[i] <= x) ++res;
    return res;
}
ll count_inversion(int x, int y) {
    ll res = 0;
    ll sum = count_sum(x, y);
    res += count_sum(x, N - 1) - sum;
    res += count_sum(N - 1, y) - sum;
    return res;
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &N, &M)) {
        init();
        for (int i = 0; i < N; ++i) {
            scanf("%d", A + i), --A[i];
            add(i, A[i]);
            ans += count_inversion(i, A[i]);
        }
        for (int i = 0, q; i < M; ++i) {
            scanf("%d", &q), --q;
            printf("%lld\n", ans);
            ans -= count_inversion(xs[q], q);
            remove(xs[q], q);
        }
    }
    return 0;
}