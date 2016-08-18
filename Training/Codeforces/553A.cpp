//#include <bits/stdc++.h>
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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;
const int MOD = 1000000007;

template <typename T>
inline T sqr(T a) { return a * a;};

int sum = 0, M, K, C[MAX_N];
ll fact[MAX_N];

ll mod_pow(ll x, ll n, ll mod) { 
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
    // return b ? qpow(a * a % mod, b >> 1, mod) * (b & 1 ? a : 1) % mod : 1;
}

int main(int argc, char const *argv[])
{
	ll ans = 1;
	fact[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		fact[i] = fact[i - 1] * i % MOD;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> C[i];
		sum += C[i];
	}
	for (int i = K - 1; i >= 0; --i) {
		ans *= fact[sum - 1] * mod_pow(fact[C[i] - 1] * fact[sum - C[i]] % MOD, MOD - 2, MOD) % MOD;
		ans %= MOD;
		sum -= C[i];
	}
	cout << ans << endl;
	return 0;
}