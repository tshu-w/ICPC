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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const double g = 10.0;
const int INF = INT_MAX;
const int MAX_N = 105;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, H, R, T;
double y[MAX_N];

double calc(int T) {
	if (T < 0) return H;
	double t = sqrt(2 * H / g);
	int k = (int)(T / t);
	if (k & 1) {
		double d = k * t + t - T;
		return H - g * d * d / 2;
	} else {
		double d = T - k * t;
		return H - g * d * d / 2;
	}
}
void solve() {
	for (int i = 0; i < N; ++i)
		y[i] = calc(T - i);
	sort(y, y + N);
	for (int i = 0; i < N; ++i)
		printf("%.2f%c", y[i] + 2 * R * i / 100.0, i + 1 == N ? '\n' : ' ');
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		cin >> N >> H >> R >> T;
		solve();
	}	
	return 0;
}