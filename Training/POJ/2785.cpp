//#include <bits/stdc++.h>
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
const int MAX_N = 4000 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
int CD[MAX_N * MAX_N];

void solve() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			CD[i * n + j] = C[i] + D[j];

	sort(CD, CD + n * n);

	long long res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int cd = -(A[i] + B[j]);
			res += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd);
		}

	cout << res << endl;
}
int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	 	cin >> A[i] >> B[i] >> C[i] >> D[i];

	solve();	
	return 0;
}