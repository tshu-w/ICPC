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
const int MAX_N = 50000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N], bit[MAX_N];

int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
void add(int i, int x) {
	while (i <= N) {
		bit[i] += x;
		i += i & -i;
	}
}

int main(int argc, char const *argv[])
{
	int t, cas = 0;
	scanf("%d", &t);
	while (t--) {
		memset(bit, 0, sizeof bit);
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", A + i);
			add(i, A[i]);
		}
		char opt[10];
		int a, b;
		printf("Case %d:\n", ++cas);
		while (scanf("%s", opt)) {
			if (opt[0] == 'E') break;
			scanf("%d%d", &a, &b);
			if (opt[0] == 'A') 
				add(a, b);
			if (opt[0] == 'S')
				add(a, -b);
			if (opt[0] == 'Q')
				printf("%d\n", sum(b) - sum(a - 1)); 
		}	
	}
	return 0;
}