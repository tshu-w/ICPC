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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, A[MAX_N], cs = 0;
char s[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int len = strlen(s);
		sort(s, s + len);
		int ans = unique(s, s + len) - s;
		printf("Case #%d: %d\n", ++cs, ans);
	}
	return 0;
}