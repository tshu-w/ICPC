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
const int MAX_N = 2000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, m, A[MAX_N], B[MAX_N], cnt[MAX_N], c = 0;

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", A + i);
		if (A[i] <= m)
			++cnt[A[i]];
	}
	int k = n / m, r = n % m;
	for (int i = 1; i <= m; ++i) {
		cnt[i] -= k;
		if (cnt[i] > 0 && r) {
			int imin = min(cnt[i], r);
			cnt[i] -= imin;
			r -= imin;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (A[i] > m || cnt[A[i]] > 0) {
			for (int j = 1; j <= m; ++j)
				if (cnt[j] < 0) {
					++c;
					if (A[i] <= m) --cnt[A[i]];
					++cnt[j];
					A[i] = j;
					break;
				}
		}
	}
	printf("%d %d\n", k, c);
	for (int i = 0; i < n; ++i)
		printf("%d%c", A[i], i + 1 == n ? '\n' : ' ');
	return 0;
}