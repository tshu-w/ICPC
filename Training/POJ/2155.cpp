#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

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
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, n, q;

int bit[MAX_N][MAX_N];
int sum(int x, int y) {
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		for (int j = y; j > 0; j -= j & -j) 
			res += bit[i][j];
	return res;
}
void add(int x, int y, int k) {
	for (int i = x; i <= n; i += i & -i)
		for (int j = y; j <= n; j += j & -j)
			bit[i][j] += k;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		memset(bit, 0, sizeof bit);
		scanf("%d%d", &n, &q);
		char tp[5];
		while (q--) {
			scanf("%s", tp);
			if (tp[0] == 'C') {
				int x1, x2, y1, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				add(x1, y1, 1);
				add(x2 + 1, y2 + 1, 1);
				add(x1, y2 + 1, -1);
				add(x2 + 1, y1, -1);
			} else {
				int x, y;
				scanf("%d%d", &x, &y);
				printf("%d\n", sum(x, y) & 1);
			}
		}
		if (t) printf("\n");
	}	
	return 0;
}