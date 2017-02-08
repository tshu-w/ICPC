// written at 15:43 on 8 Feb 2017 
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
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e2 + 10;
const double EPS = 1e-13;

int N;
double X[MAX_N], Y[MAX_N], R[MAX_N];
bool flag[MAX_N];

int top(double x, double y) {
	irep(i, N, 0)
		if (sqrt(sqr(x - X[i]) + sqr(y - Y[i])) < R[i]) return i;
	return -1;
}

double nm(double r) {
	while (r < 0.) r += 2 * pi;
	while (r >= 2 * pi) r -= 2 * pi;
	return r;
}

double dis(int i, int j) {
	return sqrt(sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]));
}

void solve() {
	memset(flag, false, sizeof flag);
	rep(i, 0, N) {
		vector<double> rds;
		// rds.push_back(0.); rds.push_back(2. * pi);
		rep(j, 0, N) if (i != j){
			double d = dis(i, j);
			if (d > R[i] + R[j] || R[i] > d + R[j] || R[j] > d + R[i]) continue;
			double phi = acos((sqr(R[i]) + sqr(d) - sqr(R[j])) / (2. * R[i] * d));
			double theta = atan2(Y[j] - Y[i], X[j] - X[i]);
			rds.push_back(nm(theta + phi)), rds.push_back(nm(theta - phi));
		}
		sort(rds.begin(), rds.end());
		rep(j, 0, rds.size() - 1) {
			double rad = (rds[j + 1] + rds[j]) / 2.;
			for (int k = -1; k <= 1; k += 2) {
				int t = top(X[i] + cos(rad) * (R[i] + k * EPS), Y[i] + sin(rad) * (R[i] + k * EPS));
				if (t != -1) flag[t] = true;
			}
		}
	}
	int res = 0; rep(i, 0, N) if (flag[i]) ++res;
	printf("%d\n", res);
}

int main(int argc, char const *argv[])
{
	while (scanf("%d", &N) && N) {
		rep(i, 0, N) scanf("%lf%lf%lf", X + i, Y + i, R + i);
		solve();
	}
	return 0;
}
