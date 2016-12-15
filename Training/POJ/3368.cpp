#include <bits/stdc++.h>

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
const int MAX_N = 1 << 17;

template <typename T>
inline T sqr(T a) { return a * a;};

struct Node
{
	int lc, rc, c;
};

int n, q, A[MAX_N], l, r;
Node dat[2 * MAX_N];

void build(int k, int l, int r) {
	if (l + 1 == r)
		dat[k].lc = dat[k].rc = dat[k].c = 1;
	else {
		int lch = 2 * k + 1, rch = 2 * k + 2, mid = (l + r) / 2;
		build(lch, l, mid);
		build(rch, mid, r);
		if (A[mid - 1] == A[mid]) {
			dat[k].c = dat[lch].rc + dat[rch].lc;
			if (dat[lch].lc == mid - l) dat[k].lc = dat[lch].lc + dat[rch].lc;
			else dat[k].lc = dat[lch].lc;
			if (dat[rch].rc == r - mid) dat[k].rc = dat[lch].rc + dat[rch].rc;
			else dat[k].rc = dat[rch].rc;
		} else {
			dat[k].c = 0;
			dat[k].lc = dat[lch].lc;
			dat[k].rc = dat[rch].rc;
		}
		dat[k].c = max(dat[k].c, dat[lch].c);
		dat[k].c = max(dat[k].c, dat[rch].c);
	}
}

int query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l)
		return 0;
	else 
		if (a <= l && r <= b)
			return dat[k].c;
		else {
			int lch = 2 * k + 1, rch = 2 * k + 2, mid = (l + r) / 2;
			int tmp = max(query(a, b, lch, l, mid), query(a, b, rch, mid, r));
			int tl = max(l, a), tr = min(r, b);
			if (tl < mid && mid < tr && A[mid - 1] == A[mid]) {
				int res = min(dat[lch].rc, mid - tl) + min(dat[rch].lc, tr - mid);
				tmp = max(tmp, res);
			}
			return tmp;
		}
}

int main(int argc, char const *argv[])
{
	while (scanf("%d", &n) && n) {
		scanf("%d", &q);
		for (int i = 0; i < n; ++i)
			scanf("%d", A + i);
		build(0, 0, n);
		for (int i = 0; i < q; ++i) {
			scanf("%d%d", &l, &r);
			printf("%d\n", query(l - 1, r, 0, 0, n));
		}
	}
	return 0;
}

/* ST
int n, q, A[MAX_N], ST[MAX_N][20], l, r, ans;

void init() {
	for (int i = 0; i < n; ++i)
		if (!i || A[i] != A[i - 1]) ST[i][0] = 1;
		else ST[i][0] = ST[i - 1][0] + 1;
	int k = 32 - __builtin_clz(n);
	for (int j = 1; j < k; ++j)
		for (int i = 0; i <= n - (1 << j); ++i)
			ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}

int rmq_max(int l, int r) {
	if (l >= r) return 0;
	int k = 31 - __builtin_clz(r - l);
	return max(ST[l][k], ST[r - (1 << k)][k]);
}

int main(int argc, char const *argv[])
{
	while(scanf("%d", &n) && n) {
		scanf("%d", &q);
		for (int i = 0; i < n; ++i)
			scanf("%d", A + i);
		memset(ST, 0, sizeof ST);
		init();
		for (int i = 0; i < q; ++i) {
			scanf("%d%d", &l, &r);
			int k = l--;
			while (k < r && A[k] == A[k - 1]) ++k;
			int cnt = rmq_max(k, r);
			ans = max(k - l, cnt);
			printf("%d\n", ans);
		}
	}
	return 0;
}
//*/