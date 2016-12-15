#include <bits/stdc++.h>

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
vector<ll> A;

int main(void) {
	ll a, b, c, d;
	for (int i = 0; i <= 30; ++i) {
		a = pow(2, i);
		if (a > 1e9) break;
		for (int j = 0; j <= 19; ++j) {
			b = pow(3, j);
			if (a * b > 1e9) break;
			for (int k = 0; k <= 13; ++k) {
				c = pow(5, k);
				if (a * b * c > 1e9) break;
				for (int m = 0; m <= 11; ++m) {
					d = pow(7, m);
					if (a * b * c * d > 1e9) break;
					A.push_back(a * b * c * d);
				}
			}
		}
	}
	sort(A.begin(), A.end());
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &n);
		printf("%lld\n", *lower_bound(A.begin(), A.end(), n));
	}
 	return 0;
}
