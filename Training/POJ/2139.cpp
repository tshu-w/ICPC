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
const int MAX_V = 300;

template <typename T>
inline T sqr(T a) { return a * a;};

int V, E, ans = INF, q[MAX_V];
int G[MAX_V][MAX_V], f[MAX_V][MAX_V];

int main(int argc, char const *argv[])
{
	scanf("%d%d", &V, &E);
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			G[i][j] = i == j? 0 : INF / 3;
	for (int i = 0, k, v; i < E; ++i) {
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", q + j); q[j]--;
		}
		for (int j = 0; j < k; ++j)
			for (int l = j + 1; l < k; ++l) 
				G[q[j]][q[l]] = G[q[l]][q[j]] = 1; 
	}
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j) 
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	for (int i = 0; i < V; ++i) { 
		int res = 0;
		for (int j = 0; j < V; ++j) if (i != j)
			res += G[i][j];
		ans = min(ans, res);
	} 
	printf("%d\n", 100 * ans / (V - 1));
	return 0;
}