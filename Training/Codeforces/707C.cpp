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

ll a, b, c;

int main(int argc, char const *argv[])
{
	cin >> a;
	if (a % 2 == 1) {
		ll n = a / 2;
		b = 2LL * n * (n + 1);
		c = 2LL * n * (n + 1) + 1;
		if (b && c)
			cout << b << " " << c << endl;
		else cout << -1 << endl;
	} else {
		ll n = a / 2;
		b = n * n - 1;
		c = n * n + 1;
		if (b && c)
			cout << b << " " << c << endl;
		else cout << -1 << endl;
	}
	return 0;
}