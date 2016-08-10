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
const int MAX_V = 500 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

struct edge {int from, to, cost;};
 
edge es[MAX_V * MAX_V];
int d[MAX_V];

int F, N, M, W, E;

bool find_negative_loop() {
	memset(d, 0, sizeof d);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < E; ++j) {
			edge e = es[j];
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				if (i == N - 1) return true;
			}
		}

	return false;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &F);
	while (F--) {
		E = 0;
		scanf("%d%d%d", &N, &M, &W);
		for (int i = 0, u, v, t; i < M; ++i) {
			scanf("%d%d%d", &u, &v, &t);
			es[E++] = edge{u, v, t};
			es[E++] = edge{v, u, t};
		}
		for (int i = 0, u, v, t; i < W; ++i) {
			scanf("%d%d%d", &u, &v, &t);
			es[E++] = edge{u, v, -t};
		}
		if (find_negative_loop()) 
			printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}