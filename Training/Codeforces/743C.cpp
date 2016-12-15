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
const int INF = 1e9;
const int MAX_N = 1e9;

ll N, x, y, z;

bool check(ll x, ll y, ll z) {
	return (x != y && y != z && x != z && x <= INF && y <= INF && z <= INF);
}

int main(int argc, char const *argv[])
{
	cin >> N;
	x = N;
	y = (N + 1);
	z = N * (N + 1);
	if (check(x, y, z)) 
		cout << x << " " << y << " " << z << endl;
	else cout << "-1" << endl;
	return 0;
}