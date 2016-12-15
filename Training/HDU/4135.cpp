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
const int MAX_N = 1e9 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, cs = 0;
ll a, b, N;

vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) n /= i;
            // cout << n << endl;
        }
    }
    if (n != 1) res.push_back(n);
    return res;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld%lld", &a, &b, &N); --a;
		vector<ll> v = divisor(N);
		ll ans = 0;
		int len = v.size();
		for (int i = 0; i < 1 << len; ++i) {
			int mul = 1, cnt = 0;
			for (int j = 0; j < len; ++j)
				if (i >> j & 1) mul *= v[j], ++cnt;	
			ans += ((b / mul) - (a / mul)) * (cnt & 1? -1 : 1);
		}
		printf("Case #%d: %lld\n", ++cs, ans);
	}	
	return 0;
}