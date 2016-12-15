#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define WIN32
#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;
const ll MOD = 110119;

template <typename T>
inline T sqr(T a) { return a * a;};

ll fact[MOD + 10], N, M;
int t, cases = 0, r;

void init() {
	fact[0] = 1;
	for (int i = 1; i <= MOD; ++i)
		fact[i] = fact[i - 1] * i % MOD;
}
template<typename T> T exgcd(T a, T b, T &x, T &y) { 
    T d = a; 
    if (b) { 
        d = exgcd(b, a % b, y, x); 
        y -= a / b * x; 
    } else { 
        x = 1; y = 0; 
    } 
    return d;
}
template<typename T> T mod_inverse(T a, T m) {
    T x, y;
    exgcd(a, m, x, y);
    return (m + x % m) % m;
}
ll mod_fact(ll n, ll p, int &e) {
	e = 0;
	if (n == 0) return 1;

	ll res = mod_fact(n / p, p, e);
	e += n / p;

	if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
	return res * fact[n % p] % p;
}
ll mod_comb(ll n, ll k, const ll &p) {
	if (n < 0 || k < 0 || n < k) return 0;
	if (n == 0) return 1;
	int e1, e2, e3;
	ll a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);
	if (e1 > e2 + e3) return 0;
	return a1 * mod_inverse(a2 * a3 % p, p) % p;
}
ll lucas(ll n, ll k, const ll &p) {
	if (n < 0 || k < 0 || n < k) return 0;
	if (n == 0) return 1;
	return lucas(n / p, k / p, p) * mod_comb(n % p, k % p, p) % p;
}
pair<ll, ll> check(ll x, ll y) {
	if ((x + y) % 3 == 0) {
		ll k = (x + y) / 3;
		if (x >= k && y >= k)
			return {k, x - k};
	}
	return {-1, -1};
}

int main(int argc, char const *argv[])
{
	init();
	while (~scanf(LLD LLD "%d", &N, &M, &r)) {
		vector<pair<pair<ll, ll>, ll> > v;
		for (int i = 0; i < r; ++i){
			ll x, y;
			scanf(LLD LLD, &x, &y);
			--x; --y;
			pair<ll, ll> p = check(x, y);
			if (p.first != -1) {
				v.emplace_back(p, 0);
			}
		}
		pair<ll, ll> end = check(N - 1, M - 1);
		if (end.first == -1) {
			printf("Case #%d: 0\n", ++cases);
		} else {
			sort(v.begin(), v.end());
			v.emplace_back(end, 0);
			for (int i = 0; i < v.size(); ++i) {
				const pair<ll, ll> &p1 = v[i].first;
				ll p = lucas(p1.first, p1.second, MOD) % MOD;
				for (int j = 0; j < i; ++j) {
					const pair<ll, ll> &p2 = v[j].first;
					p = (p - v[j].second * lucas(p1.first - p2.first, p1.second - p2.second, MOD) % MOD + MOD) % MOD;
				}
				v[i].second = p;
			}
			printf("Case #%d: " LLD "\n", ++cases, v.back().second);
		}
	}
	return 0;
}