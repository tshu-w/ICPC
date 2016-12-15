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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;
typedef pair<ll, ll > Pll;

const double pi = acos(-1.0);
const int INF = INT_MAX;

template <typename T>
inline T sqr(T a) { return a * a;};

ll N;
vector<Pll> v;

int main(int argc, char const *argv[])
{
	scanf("%lld", &N);
	ll ceil = sqrt(N) + 1e-5;
	ll s = 1, t = 1, sum = 0;
	for(;;) {
		// cout << s << " " << t << endl;
		while (t <= ceil && sum + t * t <= N) {
			sum += t * t;
			++t;
		}
		// cout << s << "->" << t << " " << sum << endl;
		if (sum == N)
			v.push_back(Pll(s, t - 1));
		if (t > ceil) break;
		sum -= s * s;
		++s;
	}
	printf("%d\n", (int)v.size());
	for (int i = 0; i < v.size(); ++i) {
		printf("%lld", v[i].second - v[i].first + 1);
		for (int j = v[i].first; j <= v[i].second; ++j)
			printf(" %d", j);
		printf("\n");
	}
	return 0;
}