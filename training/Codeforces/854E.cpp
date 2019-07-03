// written at 00:28 on 25 Jan 2018
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

const int maxn = 1 << 18;

struct Node {int l, r, data;};
int N;
Node Tr[maxn * 25];
int cnt, root[maxn];

int init(int l, int r) {
    int k = cnt++;
    Tr[k].data = 0;
    if (l + 1 < r) {
        Tr[k].l = init(l, (l + r) / 2);
        Tr[k].r = init((l + r) / 2, r);
    }
    return k;
}

void update(int &x, int y, int p, int l, int r) {
    x = cnt++;
    Tr[x] = Tr[y];
    Tr[x].data++;
    if (l + 1 == r) return ;
    if (p < (l + r) / 2) update(Tr[x].l, Tr[y].l, p, l, (l + r) / 2);
    else update(Tr[x].r, Tr[y].r, p, (l + r) / 2, r);
}

int query(int x, int y, int a, int b, int l, int r) {
    if (a >= r || b <= l) return 0;
    if (a <= l && r <= b) return Tr[y].data - Tr[x].data;
    return query(Tr[x].l, Tr[y].l, a, b, l, (l + r) / 2) + query(Tr[x].r, Tr[y].r, a, b, (l + r) / 2, r);
}

inline int query(int l, int r, int d, int u) {
    if (l > r || d > u) return 0;
    return query(root[l-1], root[r], d, u + 1, 0, N);
}

int n, q, p[maxn];
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", p + i);

    N = n + 1;
    init(0, N);
    for (int i = 0; i < n; i++) update(root[i + 1], root[i], p[i], 0, N);

    for (int i = 0, l, d, r, u; i < q; i++) {
        scanf("%d%d%d%d", &l, &d, &r, &u);
        ll ans = 0;
        ans += 1ll * query(1, l-1, 1, d-1) * query(l, n, d, n);
        ans += 1ll * query(l, r, 1, d-1) * query(1, n, d, n);
        ans += 1ll * query(r+1, n, 1, d-1) * query(1, r, d, n);
        ans += 1ll * query(1, l-1, d, u) * query(l, n, 1, n);
        ans += 1ll * query(r+1, n, d, u) * query(1, r, 1, n);
        ans += 1ll * query(1, l-1, u+1, n) * query(l, n, 1, u);
        ans += 1ll * query(l, r, u+1, n) * query(1, n, 1, u);
        ans += 1ll * query(r+1, n, u+1, n) * query(1, r, 1, u);
        ans += 1ll * query(l, r, d, u) * (n - 1);
        printf("%lld\n", ans / 2);
    }
    return 0;
}
