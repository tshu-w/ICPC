// written at 14:46 on 03 Aug 2018
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

const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;

struct Query { int l, r, id; };
int t, l, r, SIZE;
ll cur = 1, ans[maxn], i2;
Query queries[maxn];
ll fact[maxn], iact[maxn];

bool cmp(Query p, Query q) {
    return p.l / SIZE == q.l / SIZE ? p.r < q.r : p.l / SIZE < q.l / SIZE;
}

ll inverse(ll x) {
    if (x == 1) return 1;
    return (mod - (mod / x) * inverse(mod % x) % mod) % mod;
}

void init() {
    i2 = inverse(2ll); fact[0] = 1;
    for (int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
    iact[maxn - 1] = inverse(fact[maxn - 1]);
    for (int i = maxn - 2; i >= 0; i--) iact[i] = iact[i + 1] * (i + 1) % mod;
}

int C(int n, int k) {
    return fact[n] * iact[n - k] % mod * iact[k] % mod;
}

void move(int x, int y) {
    if (x) {
        if (x == 1) cur = (2 * cur - C(l, r) + mod) % mod;
        else cur = (cur + C(l - 1, r)) * i2 % mod;
    } else {
        if (y == 1) cur = (cur + C(l, r + 1)) % mod;
        else cur = (cur - C(l, r) + mod) % mod;
    }
    l += x; r += y;
}

void solve() {
    SIZE = sqrt(t);
    sort(queries, queries + t, cmp);
    for (int i = 0; i < t; i++) {
        Query &q = queries[i];
        while (r > q.r) move(0, -1);
        while (l > q.l) move(-1, 0);
        while (l < q.l) move(1, 0);
        while (r < q.r) move(0, 1);
        ans[q.id] = cur;
    }
}

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &queries[i].l, &queries[i].r);
        queries[i].id = i;
    }
    init(); solve();
    for (int i = 0; i < t; i++) printf("%lld\n", ans[i]);
    return 0;
}
