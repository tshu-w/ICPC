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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

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
	int x;
	ll res;
	while (~scanf("%d", &x) && x) {
		res = 1;
		res *= (mod_pow(2, 2 * x + 1, 29) - 1) % 29;
		res *= (mod_pow(3, x + 1, 29) - 1) * 15 % 29;
		res *= (mod_pow(22, x + 1, 29) - 1) * 18 % 29;
		printf("%lld\n", res % 29);
	}
	return 0;
}