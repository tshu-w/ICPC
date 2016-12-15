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
const int MAX_N = 1000 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char ch[] = {'D', 'I', 'M', 'A'};

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M, ans = 0, dp[MAX_N][MAX_N];
char s[MAX_N][MAX_N];
bool flag[MAX_N][MAX_N];

int dfs(int x, int y) {
	// cout << x << " " << y << endl;
	if (dp[x][y] + 1) return dp[x][y];
	if (flag[x][y] && s[x][y] == 'D') return INF;
	flag[x][y] = true;
	int res = 0;
	for (int i = 0; i < 4; ++i) {
		int xx = x + dx[i], yy = y + dy[i], id;
		id = (find(ch, ch + 4, s[x][y]) - ch + 1) % 4;
		if (0 <= xx && xx < N && 0 <= yy && yy < M && s[xx][yy] == ch[id]) {
			res = max(res, dfs(xx, yy));
		}
	}
	if (s[x][y] == 'A' && res != INF) res += 1;
	flag[x][y] = false;
	// cout << x << " " << y << " " << res << endl;
	return dp[x][y] = res;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%s", s[i]);
	memset(dp, -1, sizeof dp);
	memset(flag, false, sizeof flag);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (s[i][j] == 'D') {
				ans = max(ans, dfs(i, j));
			}
	if (ans == 0) printf("Poor Dima!\n");
	else if (ans == INF) printf("Poor Inna!\n");
	else printf("%d\n", ans);
	return 0;
}