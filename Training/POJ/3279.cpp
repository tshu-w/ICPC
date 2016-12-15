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
const int MAX_N = 20;

template <typename T>
inline T sqr(T a) { return a * a;};

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

int N, M, tile[MAX_N][MAX_N], opt[MAX_N][MAX_N], flip[MAX_N][MAX_N];
int get(int x, int y) {
	int c = tile[x][y];
	for (int i = 0; i < 5; ++i) {
		int xx, yy;
		xx = dx[i] + x; yy = dy[i] + y;
		if (0 <= xx && xx < M && 0 <= yy && yy < N)
			c += flip[xx][yy];
	}
	return c % 2;
}
int calc() {
	for (int i = 1; i < M; ++i)
		for (int j = 0; j < N; ++j)
			if (get(i - 1, j) != 0) 
				flip[i][j] = 1;

	for (int i = 0; i < N; ++i)
		if (get(M - 1, i) != 0)
			return -1;

	int res = 0;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j) 
			res += flip[i][j];

	return res;
}
void solve() {
	int res = -1;
	for (int i = 0; i < 1 << N; ++i) {
		memset(flip, 0, sizeof flip);
		for (int j = 0; j < N; ++j)
			flip[0][N - j - 1] = i >> j & 1;

		int num = calc();
		if (num >= 0 && (res < 0 || res > num)) {
			res = num;
			memcpy(opt, flip, sizeof flip);
		}
	}
	if (res == -1) 
		printf("IMPOSSIBLE\n");
	else {
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				printf("%d%c", opt[i][j], (j == N - 1)? '\n' : ' ');	
	}
}
int main(int argc, char const *argv[])
{
	cin >> M >> N;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> tile[i][j];
	solve();

	return 0;
}