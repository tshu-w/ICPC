//#include <bits/stdc++.h>
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
const int MAX_N = 100 + 10;

int N, t[MAX_N];
bool flag[MAX_N];
ll ans = 1;

ll lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	rep(i, 0, N) scanf("%d", t + i), --t[i];
	rep(i, 0, N) if (!flag[i]) {
		int res = 1;
		for (int j = t[i]; j != i; j = t[j]) {
			++res, flag[j] = true;
			if (res > N) {
				printf("-1\n");
				return 0;
			}
		}
		if (res & 1) ans = lcm(ans, res);
		else ans = lcm(ans, res / 2);
	}
	cout << ans << endl;
	return 0;
}