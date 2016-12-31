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
const int MAX_N = 55;

template <typename T>
inline T sqr(T a) { return a * a;};

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m, k, f[MAX_N][MAX_N], ans;
char s[MAX_N][MAX_N], ss[MAX_N][MAX_N];
priority_queue<pair<int, Pii> , vector<pair<int, Pii> >, greater<pair<int, Pii> > > que;

int dfs(int x, int y) {
	int res = 1;
	s[x][y] = '*';
	// cout << x << " " << y << endl;
	for (int i = 0; i < 4; ++i) {
			int xx = dx[i] + x, yy = dy[i] + y;
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) return 100000;
			if (s[xx][yy] == '.') {
				// cout << xx << "--" << yy << endl;
				res += dfs(xx, yy);
			}
		}
	// cout << x << "-" << y << "-" << res << endl;
	return res;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++j) {
			ss[i][j] = s[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '.') {
				int res = dfs(i, j);
				// cout << k << endl;
				if (res < 100000)
					que.push(make_pair(res, Pii(i, j)));
			}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			s[i][j] = ss[i][j];
	k = que.size() - k;
	while (k--) {
		Pii p = que.top().second; que.pop();
		ans += dfs(p.first, p.second);
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%c", s[i][j]);
		printf("\n");
	}
	return 0;
}