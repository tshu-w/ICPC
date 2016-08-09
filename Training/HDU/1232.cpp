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
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M;
int par[MAX_N], rnk[MAX_N];
bool flag[MAX_N];

void init(int n) {
	for (int i = 0; i < n; ++i)
		par[i] = i, rnk[i] = 0;
}
int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}
bool same(int x, int y) {
	return find(x) == find(y);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if (rnk[x] == rnk[y]) ++rnk[x];
	}
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d", &N) && N) {
		init(N + 1);
		scanf("%d", &M);
		for (int i = 0, a, b; i < M; ++i) {
			scanf("%d%d", &a, &b);
			unite(a, b);
		}
		int ans = 0;
		memset(flag, false, sizeof flag);
		for (int i = 1; i <= N; ++i) 
			flag[find(i)] = true;
		for (int i = 1; i <= N; ++i)
			if (flag[i]) ++ans;
		printf("%d\n", ans - 1);
	}	
	return 0;
}