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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int grundy(int n) {
	if (n % 8 == 7) return n + 1;
	if (n % 8 == 0) return n - 1;
	return n;
}

int main(int argc, char const *argv[])
{
	int t, n, s, res;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		res = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &s);
			res ^= grundy(s);	
		}
		if (res) 
			printf("First player wins.\n");
		else 
			printf("Second player wins.\n");
	}
	return 0;
}