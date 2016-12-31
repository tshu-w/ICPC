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
const int MAX_N = 500;
const int MAX_H = 50000;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, f[MAX_H], ans;
struct Block {
	int h, a, c;
	bool operator < (const Block &b) const {
		return a < b.a;
	}
}B[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d%d%d", &B[i].h, &B[i].a, &B[i].c);
	sort(B, B + N);
	f[0] = 1;
	for (int i = 0; i < N; ++i) {
		int num = B[i].c;
		for (int k = 1; num > 0; k <<= 1) {
			int mul = min(k, num);
			for (int j = B[i].a; j >= B[i].h * mul; --j) {
				f[j] |= f[j - B[i].h * mul];
				if (f[j]) ans = max(ans, j);
			}
			num -= mul;
		}
		// cout << ans << endl;
	}
	printf("%d", ans);
	return 0;
}