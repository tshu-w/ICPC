// written at 22:17 on 23 Feb 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

int N, k, A[MAX_N];
ll s[MAX_N], ans;
vector<pair<ll, int> > v;

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &k);
	rep(i, 0, N) {
		scanf("%d", A + i);
		s[i + 1] = s[i] + A[i];
	}
	rep(i, 0, N + 1) v.push_back(make_pair(s[i], i));
	sort(v.begin(), v.end());
	rep(i, 1, N + 1) {
		ll kk = 1ll;
		while (llabs(kk) <= llabs(v[i].first - v[0].first)) {
			if (kk > 0) {
				int l = lower_bound(v.begin(), v.end(), make_pair(v[i].first - kk, 0)) - v.begin();
				int r = lower_bound(v.begin(), v.end(), make_pair(v[i].first - kk, v[i].second)) - v.begin();
				ans += r - l;
			} else {
				int l = lower_bound(v.begin(), v.end(), make_pair(v[i].first + kk, v[i].second)) - v.begin();
				int r = lower_bound(v.begin(), v.end(), make_pair(v[i].first + kk, INF)) - v.begin();
				ans += r - l;
			}
			kk = kk * k;
			if (kk == 1ll) break;
		}
	}
	cout << ans << endl;
	return 0;
}