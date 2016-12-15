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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, cs = 0, n, m, k;

void mputs(string s, int len) {
	int sn = s.length();
	for (int i = 0; i < len; ++i)
		printf("%c", s[i % sn]);
	return ;
}

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		printf("Case #%d:\n", ++cs);
		if (n < m) puts("Impossible");
		else if (n == m) mputs("A", n), puts("");
		else {
			if (k == 1) puts("Impossible");
			else {
				if (k == 2) {
					if (m < 8) {
						if (n == 8 && m == 7) puts("AABABBAA");
						else puts("Impossible");
					}
					else mputs("A", m - 8), mputs("ABAABB", n - m + 8), puts("");
				}
				else if (m < 3) puts("Impossible");
					 else mputs("A", m - 3), mputs("ABC", n - m + 3), puts("");
			}
		}
	}
	return 0;
}
