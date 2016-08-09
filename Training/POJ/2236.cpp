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

int N, d, X[MAX_N], Y[MAX_N];
vector<int> v[MAX_N];
bool flag[MAX_N];

int par[MAX_N];
int rnk[MAX_N];
void init(int n) {
	for (int i = 0; i < n; ++i)
		par[i] = i, rnk[i] = 0;
}
int find(int x) {
	return par[x] == x? x : par[x] = find(par[x]);
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
	scanf("%d%d", &N, &d);
	init(N);
	memset(flag, false, sizeof flag);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", X + i, Y + i);
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
			if (sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]) <= sqr(d)) {
				v[i].push_back(j);
				v[j].push_back(i);
			}	
	char opt[4]; int p, q;
	while (~scanf("%s", opt)) {
		if (opt[0] == 'O') {
			scanf("%d", &p);
			--p;	
			flag[p] = true;
			for (int i = 0; i < v[p].size(); ++i) 
				if (flag[v[p][i]]) {
				unite(p, v[p][i]);
			}
		} else {
			scanf("%d%d", &p, &q);
			--p; --q;
			if (same(p, q)) 
				printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}