// written at 23:51 on 29 Mar 2017
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
const int MAX_N = 1e5 + 10;
ll b, q, l, m, ans;
set<ll> s;

int main() {
    cin >> b >> q >> l >> m;
    for (int i = 0; i < m; i++) {
        ll a;
        scanf("%lld", &a);
        s.insert(a);
    }
    if (sqr(q) == 1) {
        if (q == 1) {
            if (abs(b) <= l && s.count(b) == 0) printf("inf\n");
            else printf("0\n");
        } else {
            for (int d = -1; d <= 1; d += 2) {
                ll bb = d * b;
                if (abs(bb) <= l && s.count(bb) == 0) ++ans;
            }
            if (ans == 0) printf("0\n");
            else printf("inf\n");
        }
    } else {
        if (b == 0) {
            if (s.count(b) == 0 && abs(b) <= l) printf("inf\n");
            else printf("0\n");
            return 0;
        }
        if (q == 0) {
            if (abs(b) <= l) 
                if (s.count(0) == 0) printf("inf\n");
                else printf("%d\n", !s.count(b));
            else printf("0\n");
            return 0;
        }
        while (abs(b) <= l) {
            if (s.count(b) == 0 && abs(b) <= l) ++ans;
            b *= q;
        }
        cout << ans << endl;
    }
    return 0;
}