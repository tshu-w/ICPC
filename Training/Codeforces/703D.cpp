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
const int MAX_N = 1e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int bit[MAX_N + 1], n, m, A[MAX_N], ans[MAX_N];
vector<pair<Pii, int> > q;
map<int, int> nxt;

int sum(int i) {
	int s = 0;
	while (i > 0) {
		s ^= bit[i];
		i -= i & -i;
	}
	return s;
}
void add(int i, int x) {
	while (i <= n) {
		bit[i] ^= x;
		i += i & -i;
	}
}

bool cmp(const pair<Pii, int> &a, const pair<Pii, int> &b) {
	return a.first.first > b.first.first;
}

int main(int argc, char const *argv[])
{
	IOS;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", A + i);
	scanf("%d", &m);
	for (int i = 0, l, r; i < m; ++i) {
		scanf("%d%d", &l, &r);
		q.emplace_back(Pii(l, r), i);
	}
	sort(q.begin(), q.end(), cmp);

	int pos = n;
	for (int i = 0; i < m; ++i) {
		while (pos >= q[i].first.first) {
			if (nxt.find(A[pos]) == nxt.end()) nxt[A[pos]] = pos;
			else {
				add(nxt[A[pos]], A[pos]);
				nxt[A[pos]] = pos;
			}
			--pos;
		}
		ans[q[i].second] = sum(q[i].first.second);
	}
	for (int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);

	return 0;
}