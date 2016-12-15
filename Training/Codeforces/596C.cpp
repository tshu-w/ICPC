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
const int gap = 1e5;
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
set<Pii> P[2 * MAX_N], cnt;
Pii ans[MAX_N];

bool solve() {
	cin >> N;
	for (int i = 0, x, y; i < N; ++i) {
		cin >> x >> y;
		P[y - x + gap].insert(Pii(x, y));
	}
	for (int i = 0, w; i < N; ++i) {
		cin >> w; w += gap;
		if (P[w].size() == 0) return 0;
		int x, y;
		x = P[w].begin()->first; y = P[w].begin()->second;
		P[w].erase(P[w].begin());
		if (x && !cnt.count(Pii(x - 1, y))) return 0;
		if (y && !cnt.count(Pii(x, y - 1))) return 0;
		cnt.insert(Pii(x, y));
		ans[i] = Pii(x, y);
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	if (solve()) {
		cout << "YES" << endl;
		for (int i = 0; i < N; ++i)
			cout << ans[i].first << " " << ans[i].second << endl;
	} else cout << "NO" << endl;
	return 0;
}