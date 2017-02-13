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
const int MAX_N = 2e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, K, X, A[MAX_N], L[MAX_N], R[MAX_N];

int main(int argc, char const *argv[])
{
	cin >> N >> K >> X;
	for (int i = 0; i < N; ++i)	
		scanf("%d", A + i);
	for (int i = 0; i < N; ++i)
		L[i + 1] = L[i] | A[i];
	for (int i = N - 1; i >= 0; --i)
		R[i] = R[i + 1] | A[i];	
	ll mul = 1LL, ans = 0;
	while (K--)
		mul = mul * X;
	for (int i = 0; i < N; ++i)
		ans = max(ans, L[i] | A[i] * mul | R[i + 1]);
	cout << ans << endl;
	return 0;
}