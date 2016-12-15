#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = (1 << 17) - 1;

int n, dat[2 * MAX_N - 1];
void init(int _n) {
	n = 1;
	while (n < _n) n <<= 1;
	for (int i = 0; i < 2 * n - 1; ++i)
		dat[i] = INF;
}
void update(int k, int a) {
	k += n - 1;
	dat[k] = a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
	}
}
// query [a, b), index k in [l, r)
// query(a, b, 0, 0, n)
int query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l) return INF;
	if (a <= l && r <= b) return dat[k];
	else {
		int v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(v1, v2);
	}
}

int main(int argc, char const *argv[])
{
		
	return 0;
}