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
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int a, b, n, x, y, z;
double ans = INF * 1.;

int main(int argc, char const *argv[])
{
	cin >> a >> b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> z;
		ans = min(ans, sqrt(sqr(x - a) + sqr(y - b)) / (double)z);
	}
	printf("%.10f\n", ans);
	return 0;
}