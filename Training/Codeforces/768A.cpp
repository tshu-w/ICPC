// written at 09:08 on 21 Feb 2017 
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

int N, A[MAX_N], ans;

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	rep(i, 0, N) scanf("%d", A + i);
	sort(A, A + N);
	ans = N;
	ans -= upper_bound(A, A + N, A[0]) - lower_bound(A, A + N, A[0]);
	if (A[0] != A[N - 1])
	ans -= upper_bound(A, A + N, A[N - 1]) - lower_bound(A, A + N, A[N - 1]);
	printf("%d\n", ans);
	return 0;
}