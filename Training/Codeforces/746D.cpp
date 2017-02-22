// written at 09:55 on 22 Feb 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

int N, k, a, b;

inline void print(char c, int tm) {
	rep(i, 0, tm) printf("%c", c);
}

void solve() {
	if (a == b) {
		rep(i, 0, a) printf("GB"); puts("");
		return;
	}
	if (a < b) {
		if (b / (a + 1) + (b % (a + 1)? 1 : 0) > k) {puts("NO"); return;}	
		else {
			int tmp = b % (a + 1);
			rep(i, 0, tmp) print('B', b / (a + 1) + 1), print('G', 1);
			rep(i, 0, a + 1 - tmp) print('B', b / (a + 1)), print(i == a - tmp? '\n' : 'G', 1);
		}
	} else {
		if (a / (b + 1) + (a % (b + 1)? 1 : 0) > k) {puts("NO"); return;}
		else {
			int tmp = a % (b + 1);
			rep(i, 0, tmp) print('G', a / (b + 1) + 1), print('B', 1);
			rep(i, 0, b + 1 - tmp) print('G', a / (b + 1)), print(i == b - tmp? '\n' : 'B', 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	while (cin >> N >> k >> a >> b) {
		solve();
	}
	return 0;
}