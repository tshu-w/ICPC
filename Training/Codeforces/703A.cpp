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
int x, y;
int main(int argc, char const *argv[])
{
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (a > b) ++x;
		else if (b > a) ++y;
	}
	if (x > y)
		cout << "Mishka" << endl;
	else if (x == y) cout << "Friendship is magic!^^" << endl;
	else cout << "Chris" << endl;
	return 0;
}