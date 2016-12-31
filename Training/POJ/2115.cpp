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

ll modular_linear(ll a, ll b, ll n) {
	ll d, e, x, y;
	d = exgcd(a, n, x, y);
	if (b % d)
		return -1;
	e = x * (b / d) % n + n;
	return e % (n / d);
}

int main(int argc, char const *argv[])
{
	ll a, b, c, k;
	while (~scanf("%lld%lld%lld%lld", &a, &b, &c, &k) && (a + b + c + k)) {
		ll d = modular_linear(c, b - a, 1LL << k);
		if (d == -1) 
			printf("FOREVER\n");
		else printf("%lld\n", d);	
	}	
	return 0;
}