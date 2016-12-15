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
const int MAX_N = 1e9 + 2;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, m;
char s[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	while (m * (m + 1) <= 2 * n) ++m;
	--m;
	// cout << m << endl;
	int p = 0, i;
	for (i = 0; i < n - m * (m + 1) / 2; ++i) {
		s[p + i] = ')';
	}
	p += i;
	// puts(s);
	if (m * (m + 1) != 2 * n) { s[p++] = '('; s[p++] = ')';}
	// puts(s);
	for (i = 0; i < m - (n - m * (m + 1) / 2); ++i)
		s[p + i] = ')';
	p += i;
	for (int i = 0;i < m; ++i)
		s[p + i] = '(';
	p += i;
	puts(s);
	return 0;
}