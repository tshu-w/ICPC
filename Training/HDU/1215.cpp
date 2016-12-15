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
const int MAX_N = 500000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int ans[MAX_N];

void seive(int n) {
	fill(ans, ans + MAX_N, 1);
	for (int i = 2; i < MAX_N / 2; ++i)
		for (int j = 2; j * i < MAX_N; ++j)
			ans[i * j] += i;
}

int main(int argc, char const *argv[])
{
	int t, N, p;
	seive(MAX_N);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		printf("%d\n", ans[N]);
	}	
	return 0;
}