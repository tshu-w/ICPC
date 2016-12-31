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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
double A, B, H[MAX_N];

bool C(double H2) {
	H[2] = H2;
	for (int i = 3; i <= N; ++i) {
		H[i] = 2 * H[i - 1] + 2.0 - H[i - 2];
		if (H[i] < 0.) return false;
	}
	if (H[N] <= B) {
		B = H[N];
		return true;
	} else return false;
}

int main(int argc, char const *argv[])
{
	scanf("%d%lf", &N, &A);
	H[1] = A;
	double lb = -1e-5, ub = A;
	B = 1000000.;
	while (ub - lb > 1e-6) {
		double mid = (ub - lb) / 2. + lb;
		if (C(mid)) ub = mid;
		else lb = mid;
	}
	printf("%.2f\n", B);
	return 0;
}