// written at 15:48 on 24 Feb 2017 
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
const ll MOD = 1000000007;

ll euler_phi(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            for (; n % i == 0; n /= i);
        }
    }
    if (n != 1) res = res / n * (n - 1);
    return res;
}

int main(int argc, char const *argv[])
{
	ll n, k;
	cin >> n >> k; k = (k - 1) / 2;
	ll ans = euler_phi(n);
	for (ll i = 0; i < k && ans != 1ll; ++i)
		ans = euler_phi(ans);
	cout << ans % MOD << endl;
	return 0;
}