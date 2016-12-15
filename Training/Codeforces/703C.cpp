#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
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
typedef pair<int, int> Pii;

const double pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, w, u, v;

int main(int argc, char const *argv[])
{
	IOS;
	scanf("%d%d%d%d", &n, &w, &v, &u);
	double ans = (double)w / u;
	bool flag = false;
	for (int i = 0; i < n; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (!(x >= 0 && (double)x / v > (double)y / u - eps))
				flag = true;
			ans = max(ans, (double)x / v + (double)(w - y) / u);
		}	
	if (flag)
		printf("%.10lf\n", ans);
	else 
		printf("%.10lf\n", (double)w / u);
	return 0;
}