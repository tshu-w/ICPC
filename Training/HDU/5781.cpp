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
const int MAX_K = 2000 + 10;
const int MAX_W = 15;

template <typename T>
inline T sqr(T a) { return a * a;};

int K, W;
double E[MAX_K][MAX_W];

int main(int argc, char const *argv[])
{
	for (int i = 0; i < MAX_K; ++i)
		for (int j = 0; j < MAX_W; ++j)  
			if (i == 0) E[i][j] = 0;
			else E[i][j] = DBL_MAX;
	for (int i = 1; i < MAX_K; ++i)
		for (int j = 1; j < MAX_W; ++j)
			for (int k = 1; k <= i; ++k) {
				E[i][j] = min(E[i][j], (i - k + 1.) / (i + 1.) * E[i - k][j] + (k * 1.) / (i + 1.) * E[k - 1][j - 1] + 1.);
			}
	while (~scanf("%d%d", &K, &W)) {
		W = min(W, 13);
		printf("%.6f\n", E[K][W]);
	}	
	return 0;
}