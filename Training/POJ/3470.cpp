/* 
learn from: http://blog.csdn.net/huanghongxun/article/details/51259125/
*/

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
#define irep(i, j, k) for (int i = j; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;

const int MAX_N = 50000 + 10;
const int S = MAX_N * 3;

int N, M, wall, tot;
int dis[MAX_N], v[MAX_N], w[MAX_N], dat[3 * S];
int x[S], y[S], rx[S], ry[S], xs[S], ys[S], px[S], py[S];
int *num;

bool cmp(int a, int b) { return num[a] < num[b];}
void relabel(int *x, int *r, int n, int *a, int *mp) {
	rep(i, 0, n) r[i] = i;
	num = x;
	sort(r, r + n, cmp);
	int m = -1;
	a[r[0]] = ++m; mp[m] = x[r[0]];
	rep(i, 1, n) {
		int cur = r[i], last = r[i - 1];
		if (x[cur] == x[last]) a[cur] = m;
		else a[cur] = ++m, mp[m] = x[cur];
	}
}

int get(int q, int k, int l, int r) {
	if (dat[k] != -2) return dat[k];
	int mid = (l + r) / 2;
	if (q < mid) 
		return get(q, 2 * k + 1, l, mid);
	else return get(q, 2 * k + 2, mid, r);
}
void update(int a, int b, int k, int l, int r, int x) {
	if (r <= a || b <= l) return;
	else if (a <= l && r <= b) dat[k] = x;
	else {
		if (dat[k] != -2) {
			dat[2 * k + 1] = dat[2 * k + 2] = dat[k];
			dat[k] = -2;
		}
		update(a, b, 2 * k + 1, l, (l + r) / 2, x);
		update(a, b, 2 * k + 2, (l + r) / 2, r, x);
	} 	
}

void scan(int k, int *ys, int *xs, int *py, int W) {
	if (k < wall) {
		int k2 = k ^ 1;
		if (xs[k2] >= xs[k])
			update(xs[k], xs[k2] + 1, 0, 0, W, k / 2);
	} else {
		int t = get(xs[k], 0, 0, W);
		if (~t) {
			int d = min(abs(py[ys[k]] - py[ys[t * 2]]), abs(py[ys[k]] - py[ys[t * 2 + 1]]));
			k -= wall;
			if (d < dis[k]) dis[k] = d, v[k] = t;
		}
	}
}
void fly(int *ry, int *ys, int *xs, int *py, int W) {
	dat[0] = -1;
	rep(i, 0, tot) scan(ry[i], ys, xs, py, W);
	dat[0] = -1;
	irep(i, tot - 1, 0) scan(ry[i], ys, xs, py, W);
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	wall = 2 * N; tot = wall + M;
	rep(i, 0, tot) scanf("%d%d", x + i, y + i);
	relabel(x, rx, tot, xs, px);
	relabel(y, ry, tot, ys, py);
	fill(dis, dis + M, INF); memset(w, 0, N);
	fly(ry, ys, xs, py, xs[rx[tot - 1]] + 1);
	fly(rx, xs, ys, px, ys[ry[tot - 1]] + 1);
	rep(i, 0, M) ++w[v[i]];
	rep(i, 0, N) printf("%d\n", w[i]);
	return 0;
}