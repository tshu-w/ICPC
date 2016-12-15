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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const ll INF = LONG_LONG_MAX;
const int MAX_N = 43;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, W;
ll w[MAX_N], v[MAX_N];
pair<ll, ll> ps[1 << (MAX_N / 2)];

void solve() {
	int n2 = n / 2;
	for (int i = 0; i < 1 << n2; ++i) {
		ll sw = 0, sv = 0;
		for (int j = 0; j < n2; ++j)
			if (i >> j & 1) {
				sw += w[j];
				sv += v[j];
			}
		ps[i] = make_pair(sw, sv);
	}	

	sort(ps, ps + (1 << n2));
	int m = 1;
	for (int i = 1; i < 1 << n2; ++i) {
		if (ps[m - 1].second < ps[i].second)
			ps[m++] = ps[i];
	}

	ll res = 0;
	for (int i = 0; i < 1 << (n - n2); ++i) {
		ll sw = 0, sv = 0;
		for (int j = 0; j < n - n2; ++j) 
			if (i >> j & 1) {
				sw += w[n2 + j];
				sv += v[n2 + j];
			}
		if (sw <= W) {
			ll tv = (lower_bound(ps, ps + m, make_pair(W - sw, INF)) - 1)->second;
			res = max(res, sv + tv);
		}
	}

	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}