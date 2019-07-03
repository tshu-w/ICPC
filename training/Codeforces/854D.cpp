// written at 20:38 on 06 Sep 2017
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

const int INF = INT_MAX / 3;
const int maxn = 1e5 + 10;
const int maxk = 1e6 + 10;

struct flight {
    int d, f, t, c, id;
    flight(int d = 0, int f = 0, int t = 0, int c = 0, int id = 0):d(d), f(f), t(t), c(c), id(id) {}
};

bool cmp1(const flight &a, const flight &b) {
    return a.d < b.d;
}

bool cmp2(const flight &a, const flight &b) {
    return a.d > b.d;
}

int n, m, k, d[maxn], f[maxn], t[maxn], c[maxn];
flight flt[maxn];
int l[maxn], r[maxn];
int cost1[maxn], cost2[maxn];
ll sum1[maxk], sum2[maxk];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    fill(l + 1, l + n + 1, INF);
    fill(r + 1, r + n + 1, 0);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", d + i, f + i, t + i, c + i);
        flt[i] = flight(d[i], f[i], t[i], c[i], i);
        if (f[i] != 0) l[f[i]] = min(d[i], l[f[i]]);
        else r[t[i]] = max(d[i], r[t[i]]);
    }
    int ll = 0, rr = INF;
    for (int i = 1; i <= n; i++) {
        ll = max(l[i], ll);
        rr = min(r[i], rr);
    }
    if (rr - ll - 1 < k) {
        printf("-1\n");
        return 0;
    }
    fill(cost1 + 1, cost1 + n + 1, INF);
    sum1[0] = accumulate(cost1 + 1, cost1 + n + 1, 0ll);
    sort(flt + 1, flt + m + 1, cmp1);
    for (int d = 1, i = 1; d < maxk; d++) {
        sum1[d] = sum1[d - 1];
        while (i <= m && flt[i].d == d) {
            if (flt[i].f != 0) {
                if (cost1[flt[i].f] > flt[i].c) {
                    sum1[d] -= cost1[flt[i].f] - flt[i].c;
                    cost1[flt[i].f] = flt[i].c;
                }
            }
            i++;
        }
    }

    fill(cost2 + 1, cost2 + n + 1, INF);
    sum2[maxk - 1] = accumulate(cost2 + 1, cost2 + n + 1, 0ll);
    sort(flt + 1, flt + m + 1, cmp2);
    for (int d = maxk - 2, i = 1; d > 0; d--) {
        sum2[d] = sum2[d + 1];
        while (i <= m && flt[i].d == d) {
            if (flt[i].f == 0) {
                if (cost2[flt[i].t] > flt[i].c) {
                    sum2[d] -= cost2[flt[i].t] - flt[i].c;
                    cost2[flt[i].t] = flt[i].c;
                }
            }
            i++;
        }
    }

    long long ans = LLONG_MAX / 3;
    for (int d = 1; d + k + 1 < maxk; d++) {
        ans = min(ans, sum1[d] + sum2[d + k + 1]);
    }
    cout << ans << endl;
    return 0;
}
