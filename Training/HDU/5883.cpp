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
const int MAX_N = 100000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, m, A[MAX_N], d[MAX_N], t;

int par[MAX_N];
int rnk[MAX_N];
void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
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
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		memset(d, 0, sizeof d);
		scanf("%d%d", &n, &m);
		init(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", A + i);
		for (int i = 0, u, v; i < m; ++i) {
			scanf("%d%d", &u, &v);
			--u; --v;
			++d[u]; ++d[v];
			unite(u, v);
		}
		int cnt = 0, root = find(0), ans = 0;
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			if (d[i] & 1) {
				++cnt;
				ans ^= A[i];
			}
			if ((d[i] / 2) % 2) ans ^= A[i];
			if (root != find(i) && d[i]) flag = false;

		}
		if (cnt == 1 || cnt > 2) flag = false;
		if (flag) {
			int imax = 0;
			if (cnt == 0) {
				for (int i = 0; i < n; ++i)
					imax = max(A[i] ^ ans, imax);
			} else imax = ans;
			printf("%d\n", imax);
		}
		else 
			printf("Impossible\n");
	}	
	return 0;
}