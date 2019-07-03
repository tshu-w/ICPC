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

const int maxn = 3e5 + 10;

int n;
ll a[maxn], b[maxn], aa[maxn], bb[maxn];
ll ans, sum, res;

void cal(ll res, ll *a, ll *b, int n, ll st) {
    sum = 0;
    for (int i = 0; i < n; i++) sum += a[i] + b[i];

    for (int i = 0; i < n; i++) res += a[i] * (i + st);
    for (int i = n - 1; i >= 0; i--) res += b[i] * (n + (n - i - 1) + st);
    ans = max(ans, res);

    for (int i = 0; i + 1 < n; i += 2) {
        res -= a[i] * (2 * i + st) + a[i + 1] * (2 * i + 1 + st);
        res -= b[i] * (2 * n - 1 + st) + b[i + 1] * (2 * n - 2 + st);
        sum -= a[i] + a[i + 1] + b[i] + b[i + 1];
        res += sum * 2;
        res += a[i] * (2 * i + st) + b[i] * (2 * i + 1 + st) + b[i + 1] * (2 * i + 2 + st) + a[i + 1] * (2 * i + 3 + st);
        ans = max(ans, res);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int i = 0; i < n; i++) scanf("%lld", b + i);
    cal(res, a, b, n, 0);

    res += a[0] * 0 + b[0] * 1;
    for (int i = 1; i < n; i++) aa[i - 1] = b[i], bb[i - 1] = a[i];
    cal(res, aa, bb, n - 1, 2);

    printf("%lld\n", ans);
    return 0;
}
