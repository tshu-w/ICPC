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
const int MAX_N = 1e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n;

int euler[MAX_N];
void euler_phi2() {
	for (int i = 0; i < MAX_N; ++i) euler[i] = i;
	for (int i = 2; i < MAX_N; ++i) {
		if (euler[i] == i)
			for (int j = i; j < MAX_N; j += i) euler[j] = euler[j] / i * (i - 1);
	}
}

int main(int argc, char const *argv[])
{
	euler_phi2();
	while (~scanf("%d", &n) && n) {
		ll ans = 0;
		for (int i = 2; i <= n; ++i) ans += euler[i];
		printf("%lld\n", ans);
	}	
	return 0;
}