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
const int MAX_N = 50000;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M, L, D[MAX_N];

bool C(int dis) {
	int last = 0;
	for (int i = 1; i < N - M; ++i) {
		int crt = last + 1;
		while (crt < N && D[crt] - D[last] < dis)
			++crt;
		if (crt == N) return false;
		last = crt;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &L, &N, &M);
	for (int i = 1; i <= N; ++i)
		scanf("%d", D + i);
	D[0] = 0; D[++N] = L; ++N;
	sort(D, D + N);
	int lb = 0, ub = L + 1;
	while (ub - lb > 1) {
		int mid = (ub - lb) / 2 + lb;
		if (C(mid)) lb = mid;
		else ub = mid;
	}
	printf("%d\n", lb);
	return 0;
}