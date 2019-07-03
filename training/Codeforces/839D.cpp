// written at 22:31 on 12 Aug 2017
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

const int maxn = 2e5 + 10;
const int maxm = 1e6 + 10;
const ll mod = 1e9 + 7;

int n, A[maxn];
ll a[maxm], f[maxm], pw2[maxn];

int main() {
    pw2[0] = 1;
    for (int i = 1; i < maxn; i++) pw2[i] = pw2[i - 1] * 2 % mod;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", A + i); a[A[i]]++;
    }
    ll ans = 0;
    for (int i = maxm - 1; i >= 2; i--) {
        int res = 0;
        for (int j = i; j < maxm; j += i) res += a[j];
        if (res) {
            f[i] = (ll)res * pw2[res - 1] % mod;
            for (int j = 2 * i; j < maxm; j += i) f[i] = (f[i] - f[j] + mod) % mod;
        }
        ans = (ans + i * f[i] % mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
