#include <bits/stdc++.h>

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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1 << 17;

int N, Q, A, l, r;
char opt[4];

ll bit0[MAX_N + 1], bit1[MAX_N + 1], x;

ll sum(ll *b, int i) {
	ll s = 0;
	while (i) {
		s += b[i];
		i -= i & -i;
	}
	return s;
}
void add(ll *b, int i, int c) {
	while (i <= N) {
		b[i] += c;
		i += i & -i;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A);
		add(bit0, i, A);
	}
	for (int i = 0; i < Q; ++i) {
		scanf("%s", opt);
		if (opt[0] == 'Q') {
			scanf("%d%d", &l, &r);
			ll res = 0;
			res += sum(bit0, r) + sum(bit1, r) * r;
			res -= sum(bit0, l - 1) + sum(bit1, l - 1) * (l - 1);
			printf("%lld\n", res);
		} else {
			scanf("%d%d%lld", &l, &r, &x);
			add(bit0, l, -x * (l - 1));
			add(bit1, l, x);
			add(bit0, r, x * r);
			add(bit1, r, -x);
		}
	}
	return 0;
}

/* Segment Tree
int N, Q; 
ll data[2 * MAX_N - 1], datb[2 * MAX_N - 1], A;

void add(int a, int b, int c, int k, int l, int r) {
	if (a <= l && r <= b) data[k] += c;
	else if (l < b && r > a) {
		datb[k] += (min(r, b) - max(a, l)) * c;
		add(a, b, c, 2 * k + 1, l, (l + r) / 2);
		add(a, b, c, 2 * k + 2, (l + r) / 2, r);
	}	
}

ll sum(int a, int b, int k, int l, int r) {
	if (r <= a || l >= b) return 0;
	if (a <= l && r <= b) return data[k] * (r - l) + datb[k];
	else {
		ll res = (min(b, r) - max(a, l)) * data[k];
		res += sum(a, b, 2 * k + 1, l, (l + r) / 2);
		res += sum(a, b, 2 * k + 2, (l + r) / 2, r);
		return res;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		scanf("%lld", &A);
		add(i, i + 1, A, 0, 0, N);
	}
	for (int i = 0; i < Q; ++i) {
		char opt[4];
		int a, b, c;
		scanf("%s", opt);
		if (opt[0] == 'Q') {
			scanf("%d%d", &a, &b); --a;
			printf("%lld\n", sum(a, b, 0, 0, N));
		} else {
			scanf("%d%d%d", &a, &b, &c); --a;
			add(a, b, c, 0, 0, N);
		}
	}
	return 0;
}
*/