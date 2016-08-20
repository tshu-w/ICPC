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

int N, M, X, Y, a, b, ans = INF, n, m;
bool C(int n, int m) {
	return ((n - X) % a == 0 && (m - Y) % b == 0 && abs((n - X) / a - (m - Y) / b) % 2 == 0);
}
int cnt(int n, int m) {
	return max((n - X) / a, (m - Y) / b);
}

int main(int argc, char const *argv[])
{
	cin >> N >> M >> X >> Y >> a >> b;
	n = 2 * X - 1; m = 2 * Y - 1;
	if (C(n, m))
		ans = min(ans, cnt(n, m));
	if (C(N, m))
		ans = min(ans, cnt(N, m));
	if (C(n, M))
		ans = min(ans, cnt(n, M));
	if (C(N, M))
		ans = min(ans, cnt(N, M));
	if (0 >= X - a && X + a > N && Y != m && Y != M) ans = INF;
	if (0 >= Y - b && Y + b > M && X != n && X != N) ans = INF;
	if (ans == INF) 
		cout << "Poor Inna and pony!" << endl;
	else
		cout << ans << endl;
	return 0;
}