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

int N, M, A[MAX_N];

bool C(int ceil) {
	int sum, cur = 0;
	for (int i = 0; i < M; ++i) {
		sum = 0;
		while (cur < N && sum + A[cur] <= ceil)
			sum += A[cur++];
		if (cur == N) return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d", A + i);
	int lb = 1, ub = INF;
	while (ub - lb > 1) {
		int mid = (ub - lb) / 2 + lb;
		if (C(mid)) ub = mid;
		else lb = mid;
	}
	printf("%d\n", ub);
	return 0;
}