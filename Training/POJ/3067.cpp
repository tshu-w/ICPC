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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, n, m, k, bit[MAX_N];

int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x) {
	while (i <= m) {
		bit[i] += x;
		i += i & -i;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs) {
		vector<Pii> bridge;
		memset(bit, 0, sizeof bit);
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0, l, r; i < k; ++i) {
			scanf("%d%d", &l, &r);
			bridge.push_back(Pii(l, r));
		}
		sort(bridge.begin(), bridge.end());
		ll ans = 0;
		for (int i = 0; i < k; ++i) {
			ans += sum(m) - sum(bridge[i].second);
			add(bridge[i].second, 1);
		}
		printf("Test case %d: %lld\n", cs, ans);
	}
	return 0;
}