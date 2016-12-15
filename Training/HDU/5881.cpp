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

ll l, r;

int main(int argc, char const *argv[])
{
	// freopen("my.ans", "w", stdout);
	//     for (ll i = 0; i < 100; ++i) for (ll j = i; j < 100; ++j) {
	//     	double l = i, r = j;
	//     	double a = max((l + 1.) / 2., 1.);
	//     	// l -= a; if (l < 0) l = 0.;
	//     	// r -= a;
	//     	if (i == 2 && r == 2) printf("2 2 1\n"); else
	// 		if (r <= 1) printf("%lld %lld 0\n", i, j);
	// 		else 
	// 			if (r - a <= 1 && a <= 1) printf("%lld %lld 1\n", i, j);
	// 			else 
	// 				if (l + 1 >= r) printf("%lld %lld 2\n", i, j);
	// 				else {
	// 					ll ans = (ll)ceil(r / 2. - a) + 1.;
	// 					printf("%lld %lld %lld\n", i, j, ans);
	// 				}
	//     }        
	// fclose(stdin);
    while (~scanf("%lld%lld", &l, &r)) {
		double a = max((l + 1.) / 2., 1.);
		// l -= a; if (l < 0) l = 0.;
		// r -= a;
		if (r <= 1) puts("0");
		else if (r <= 2) puts("1");
		else if (l == 0) printf("%lld\n", (r + 1) / 2);
		else printf("%lld\n", max(2ll, (r - l) / 2 + 1));
    }        
    return 0;
}
