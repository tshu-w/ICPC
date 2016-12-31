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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 30;

template <typename T>
inline T sqr(T a) { return a * a;};

int N = 20, ans = INF, A[MAX_N], B[MAX_N];

int cal() {
	int res = 0;
	for (int i = 1; i < N; ++i)
		if (A[i - 1]) {
			++res;
			for (int j = i - 1; j <= i + 1; ++j)
				if (j < N)
					A[j] = (A[j] + 1) % 2;
		}
	if (!A[N - 1]) return res;
	else return INF;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < N; ++i)
		scanf("%d", A + i);
	memcpy(B, A, sizeof A);
	ans = min(cal(), ans);
	memcpy(A, B, sizeof A);
	A[0] = (A[0] + 1) % 2;
	A[1] = (A[1] + 1) % 2;
	ans = min(cal() + 1, ans);
	printf("%d\n", ans);
	return 0;
}