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
const int MAX_N = 10;
const int N = 5, M = 6;

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

template <typename T>
inline T sqr(T a) { return a * a;};

int t, tt, title[MAX_N][MAX_N], opt[MAX_N][MAX_N];

int get(int x, int y) {
	int c = title[x][y];
	for (int d = 0; d < 5; ++d) {
		int xx, yy;
		xx = x + dx[d]; yy = y + dy[d];
		if (0 <= xx && xx < N && 0 <= yy && yy < M)
			c += opt[xx][yy];
	}
	return c % 2;
}

bool cal() {
	for (int i = 1; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (get(i - 1, j)) opt[i][j] = 1;
	for (int j = 0; j < M; ++j)
		if (get(N - 1, j)) return false;
	return true;
}

void solve() {
	for (int i = 0; i < 1 << M; ++i) {
		memset(opt, 0, sizeof opt);
		for (int j = 0; j < M; ++j) {
			opt[0][M - j - 1] = i >> j & 1;
		}
		if (cal())
			break;
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			printf("%d%c", opt[i][j], (j + 1 == M)? '\n' : ' ');
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		printf("PUZZLE #%d\n", ++tt);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				scanf("%d", &title[i][j]);
		solve();
	}
	return 0;
}