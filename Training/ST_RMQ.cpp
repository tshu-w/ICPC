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
const int MAX_N = 1e5 + 10;
const int MAX_K = 31 - __builtin_clz(MAX_N);

int n, ST[MAX_N][MAX_K + 1], A[MAX_N];
void build(int N) {
	for (int i = 0; i < N; ++i) 
		ST[i][0] = A[i];
	int k = 31 - __builtin_clz(N);
	for (int j = 1; j <= k; ++j)
		for (int i = 0; i <= N - (1 << j); ++i)
			ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	if (l >= r) return 0;
	int ans = INF, k = 31 - __builtin_clz(r - l);
	for (int j = k; j >= 0; --j)
		if (l + (1 << j) - 1 <= r) {
			ans = min(ans, ST[l][j]);
			l += 1 << j; 
		}
	return ans;
}

int RMQ(int l, int r) {
	if (l >= r) return 0;
	int k = 31 - __builtin_clz(r - l);
	return min(ST[l][k], ST[r - (1 << k)][k]);
}

int main(int argc, char const *argv[])
{
	cout << endl;
	return 0;
}