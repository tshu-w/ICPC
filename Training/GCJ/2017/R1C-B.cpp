// written at 16:46 on 30 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename "B-large"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 2000;
bool a[maxn], b[maxn];
int n, t1, t2;
void init(){
	scanf("%d%d", &t1, &t2);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= t1; i ++){
		int x, y;
		scanf("%d%d", &x, &y);
		for (int j = x; j < y; j ++)
			a[j] = 1;
	}
	for (int i = 1; i <= t2; i ++){
		int x, y;
		scanf("%d%d", &x, &y);
		for (int j = x; j < y; j ++)
			b[j] = 1;
	}
}
int f[maxn][maxn][2][2];
int work(){
	init();
	memset(f, 63, sizeof(f));
	if (!a[0]) f[0][0][0][0] = 1;
	if (!b[0]) f[0][1][1][1] = 1;
	for (int i = 1; i < 1440; i ++)
		for (int j = 0; j <= 720; j ++){
			if (!a[i]){
				f[i][j][0][0] = min(f[i - 1][j][0][1] + 1, f[i - 1][j][0][0]);
				f[i][j][1][0] = min(f[i - 1][j][1][1] + 1, f[i - 1][j][1][0]);
			}
			if (!b[i] && j){
				f[i][j][0][1] = min(f[i - 1][j - 1][0][0] + 1, f[i - 1][j - 1][0][1]);
				f[i][j][1][1] = min(f[i - 1][j - 1][1][0] + 1, f[i - 1][j - 1][1][1]);
			}
	}
	int ans = 100000;
	ans = min(ans, f[1439][720][0][0] - 1);
	ans = min(ans, f[1439][720][1][1] - 1);
	ans = min(ans, min(f[1439][720][1][0], f[1439][720][0][1]));
	return ans;
}
int main(){
    setfile();
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i ++)
		printf("Case #%d: %d\n", i, work());
    resetfile();
	return 0;
}
