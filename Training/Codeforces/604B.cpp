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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, K, A[MAX_N], ans = 0;

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &K);
	K = N - K;
	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i);
		ans = max(ans, A[i]);
	}
	for (int i = 0; i < K; ++i)
		ans = max(ans, A[i] + A[2 * K - i - 1]);
	printf("%d\n", ans);
	return 0;
}