// written at 17:19 on 13 Feb 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

int cnt25(int n, int k) {
	return n == 0? 0 : cnt25(n / k, k) + n / k;
}
int g(int n, int x) {
	return n == 0? 0 : n / 10 + (n % 10 >= x) + g(n / 5, x);
}
int f(int n, int x) {
	return n == 0? 0 : f(n / 2, x) + g(n, x);
}

const int table[4][4] = { 
	{6, 2, 4, 8},
	{1, 3, 9, 7},
	{1, 7, 9, 3},
	{1, 9, 1, 9}
};
int N, M;

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &N, &M)) {
		int n2 = cnt25(N, 2) - cnt25(N - M, 2);
		int n5 = cnt25(N, 5) - cnt25(N - M, 5);
		int n3 = f(N, 3) - f(N - M, 3);
		int n7 = f(N, 7) - f(N - M, 7);
		int n9 = f(N, 9) - f(N - M, 9);
		// cout << n2 << " " << n5 << " " << n3 << " " << n7 << " " << n9 << endl;
		int ans = 1;
		if (n5 > n2) {
			printf("5\n");
		} else {
			if (n2 != n5) {
				ans *= table[0][(n2 - n5) % 4];
			}	
			ans *= table[1][n3 % 4];
			ans *= table[2][n7 % 4];
			ans *= table[3][n9 % 4];
			ans %= 10;
			printf("%d\n", ans);
		}
	}
	return 0;
}