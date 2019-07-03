// written at 10:26 on 02 Aug 2018
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

template <typename T> inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 5e4 + 10;

struct Query { int l, r, id; };

int n, m, C[maxn];
int l, r, size, cnt[maxn];
Pii cur, ans[maxn];
Query queries[maxn];

int gcd(int a, int b) { return b == 0? a : gcd(b, a % b); }

bool cmp(Query p, Query q) {
    return p.l / size == q.l / size? p.r < q.r : p.l / size < q.l / size;
}

void move(int pos, int sign) {
    if (pos == l) {
        if (sign == 1) {
            cur.first += cnt[C[pos]];
            cur.second += r - l - 1;
            cnt[C[pos]]++;
        } else {
            cnt[C[pos - 1]]--;
            cur.first -= cnt[C[pos - 1]];
            cur.second -= r - l;
        }
    } else {
        if (sign == 1) {
            cur.first += cnt[C[pos - 1]];
            cur.second += r - l - 1;
            cnt[C[pos - 1]]++;
        } else {
            cnt[C[pos]]--;
            cur.first -= cnt[C[pos]];
            cur.second -= r - l;
        }
    }
}

void solve() {
    size = (int)sqrt(n);
    sort(queries, queries + m, cmp);
    for (int i = 0; i < m; i++) {
        const Query &q = queries[i];
        while (l > q.l) move(--l, 1);
        while (r < q.r) move(++r, 1);
        while (l < q.l) move(++l, -1);
        while (r > q.r) move(--r, -1);
        ans[q.id] = cur;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", C + i);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &queries[i].l, &queries[i].r);
        queries[i].l--;
        queries[i].id = i;
    }
    solve();
    for (int i = 0; i < m; i++) {
        int tmp = gcd(ans[i].first, ans[i].second);
        if (tmp) printf("%d/%d\n", ans[i].first / tmp, ans[i].second / tmp);
        else printf("0/1\n");
    }
    return 0;
}
