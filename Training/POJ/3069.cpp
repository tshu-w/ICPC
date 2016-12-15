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
const int INF = INT_MAX;
const int MAX_N = 1000 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, R, X[MAX_N];
void solve() {
	sort(X, X + N);

	int i = 0, ans = 0;
	while (i < N) {
		int s = X[i++];
		while (i < N && X[i] <= R + s) ++i;
		int t = X[i - 1];
		while (i < N && X[i] <= R + t) ++i;
		++ans;
	}
	cout << ans << endl;
}
int main(int argc, char const *argv[])
{
	while (cin >> R >> N && N + 1 && R + 1) {
		for (int i = 0; i < N; ++i)
			cin >> X[i];
		solve();
	}	
	return 0;
}