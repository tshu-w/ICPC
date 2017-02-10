// written at 19:09 on 8 Feb 2017 
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector> 
#include <utility>
#include <bitset>

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
typedef pair<double, int > Pdi;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

int n;
double x[MAX_N], y[MAX_N], r[MAX_N];

bool inside(int i, int j) {
	double dx = x[i] - x[j], dy = y[i] - y[j];
	return sqr(dx) + sqr(dy) <= sqr(r[j]) + sqr(r[i]) - 2 * r[i] * r[j];
}

void solve() {
	vector<Pdi > events;
	rep(i, 0, n) {
		events.push_back(Pdi(x[i] - r[i], i));
		events.push_back(Pdi(x[i] + r[i], i + n));
	}
	sort(events.begin(), events.end());

	set<Pdi > outers;
	vector<int> res;
	rep(i, 0, events.size()) {
		int id = events[i].second % n;
		if (events[i].second < n) {
			set<Pdi>::iterator it = outers.lower_bound(Pdi(y[id], id));
			if (it != outers.end() && inside(id, it->second)) continue;
			if (it != outers.begin() && inside(id, (--it)->second)) continue;
			res.push_back(id);
			outers.insert(Pdi(y[id], id));
		} else outers.erase(Pdi(y[id], id));
	}
	sort(res.begin(), res.end());
	printf("%d\n", (int)res.size());
	rep(i, 0, res.size())
		printf("%d%c", res[i] + 1, i + 1 == res.size() ? '\n' : ' ');
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d", &n)) {
		rep(i, 0, n) scanf("%lf%lf%lf", r + i, x + i, y + i);
		solve();
	}
	return 0;
}