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
const int MAX_N = 10;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int B = 1e8 + 7;

template <typename T>
inline T sqr(T a) { return a * a;};

set<ull> s;
int m[MAX_N][MAX_N];

void dfs(int x, int y, int k, ull res) {	
	res = res * B + m[x][y];
	if (k == 5) {
		// cout << res << endl;
		s.insert(res);
		return ;
	}
	for (int d = 0, xx, yy; d < 4; ++d) {
		xx = dx[d] + x; yy = dy[d] + y;
		if (0 <= xx && xx < 5 && 0 <= yy && yy < 5)
			dfs(xx, yy, k + 1, res);
	}
	return ;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			scanf("%d", &m[i][j]);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j) {
			dfs(i, j, 0, 0);
		}	
	cout << s.size() << endl;
	return 0;
}