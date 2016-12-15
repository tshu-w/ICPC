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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int gcd(int a, int b) {
	return (b)? gcd(b, a % b) : a;
}
int main(int argc, char const *argv[])
{
	int a, b, n, res, x, y, d;
	bool flag = false;
	cin >> a >> b >> n;
	if (a < b) {
		swap(a, b);
		flag = true;
	}
	d = gcd(a, b);
	a /= d; b /= d; n /= d;
	int t = n / a;
	res = n; x = y = 0;
	for (int i = 0; i <= t; ++i)
		if (res > (n - i * a) % b) {
			x = i; y = (n - i * a) / b;
			res = n - x * a - y * b;
			if (res == 0) break;
		}
	if (flag)
		cout << y << ' ' << x << endl;
	else
		cout << x << " " << y << endl;
	return 0;
}