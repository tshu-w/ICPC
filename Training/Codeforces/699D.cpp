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
const int MAX_N = 200000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N], cnt = 0;
bool flag[MAX_N], vis[MAX_N], mark[MAX_N];

void dfs(int i) {
	flag[i] = vis[i] = true;
	if (A[i] == i || vis[A[i]]) mark[i] = true;
	if (flag[A[i]])
		return ;
	dfs(A[i]);
}

int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		scanf("%d", A + i);	
	memset(flag, false, sizeof flag);
	memset(mark, false, sizeof mark);
	for (int i = 1; i <= N; ++i)
		if (!flag[i]) {
			memset(vis, false, sizeof vis);
			dfs(i);
		}
	int root = 0;
	for (int i = 1; i <= N; ++i)
		if (mark[i] && A[i] == i) {
			root = i;
			break;
		}
	if (!root)
		for (int i = 1; i <= N; ++i)
			if (mark[i]) {
				root = i;
				break;
			}
	for (int i = 1; i <= N; ++i)
		if (mark[i] && root != A[i])
			++cnt;
	cout << cnt << endl;
	for (int i = 1; i <= N; ++i)
		if (mark[i])
			printf("%d%c", root, (i == N)? '\n' : ' ');
		else 
			printf("%d%c", A[i], (i == N)? '\n' : ' ');
	return 0;
}