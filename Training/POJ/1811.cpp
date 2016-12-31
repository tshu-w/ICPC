#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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

template <typename T>
inline T sqr(T a) { return a * a;};

int t;
ll n;

const int S = 20;

template<typename T> T mod_mult(T x, T n, T mod) {
    T res = 0;
    while (n > 0) {
        if (n & 1) res = (res + x) % mod;
        x = (x + x) % mod;
        n >>= 1;
    }
    return res;
}

template<typename T> T mod_pow(T x, T n, T mod) {
    T res = 1;
    while (n > 0) {
        if (n & 1) res = mod_mult(res, x, mod);
        x = mod_mult(x, x, mod);
        n >>= 1;
    }
    return res;
    // return b ? mod_pow(a * a % mod, b >> 1, mod) * (b & 1 ? a : 1) % mod : 1;
}
bool check(ll a, ll n, ll x, ll t) {
	ll res = mod_pow(a, x, n);
	ll last = res;
	for (int i = 1; i <= t; ++i) {
		res = mod_mult(res, res, n);
		if (res == 1 && last != 1 && last != n - 1) return true;
		last = res;
	}
	if (res != 1) return true;
	return false;
}
bool Miller_Rabin(ll n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if ((n & 1) == 0) return false;
	ll x = n - 1, t = 0;
	while ((x & 1) == 0) {
		x >>= 1;
		++t;
	}
	for (int i = 0; i < S; ++i) {
		ll a = rand() % (n - 1) + 1;
		if (check(a, n, x, t))
			return false;
	}
	return true;
}

vector<ll> factor;

template<typename T> T gcd(T a, T b) {
    //return (b)? gcd(b, a  % b) : a;
    while (b) { T t = a % b; a = b; b = t; } return a;
}
ll Pollard_rho(ll x, ll c) {
	ll i = 1, k = 2;
	ll x0 = rand() % x;
	ll y = x0;
	while (true) {
		++i;
		x0 = (mod_mult(x0, x0, x) + c) % x;
		ll d;
		if (y == x0) d = 1;
		else 
			if (y > x0)
				d = gcd(y - x0, x);
			else d = gcd(x0 - y, x);
		if (d != 1 && d != x) return d;
		if (y == x0) return x;
		if (i == k) {
			y = x0;
			k += k;
		}
	}
}
void find_factor(ll n) {
	if (Miller_Rabin(n)) {
		factor.push_back(n);
		return ;
	}
	ll p = n;
	while (p >= n) p = Pollard_rho(p, rand() % (n - 1) + 1);
	find_factor(p);
	find_factor(n / p);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		if (Miller_Rabin(n)) 
			printf("Prime\n");
		else {
			// printf("No Prime\n");
			factor.clear();
			find_factor(n);
			ll ans = LLONG_MAX;
			for (int i = 0; i < factor.size(); ++i)
				ans = min(factor[i], ans);
			printf("%lld\n", ans);
		}
	}
	return 0;
}