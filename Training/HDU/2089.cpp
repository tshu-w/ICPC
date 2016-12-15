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
const int MAX_N = 1e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, f[MAX_N], l, r;

bool check(int x) {
	while (x) {
		if (x % 10 == 4) return false;
		if (x % 100 == 62) return false;
		x /= 10;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	for (int i = 1; i < MAX_N; ++i)
		if (check(i)) 
			f[i] = f[i - 1] + 1;
		else f[i] = f[i - 1];

	while (~scanf("%d%d", &l, &r) && l && r) {
		printf("%d\n", f[r] - f[l - 1]);
	}
	return 0;
}