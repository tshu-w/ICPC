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

int N, k, A[MAX_N], B[MAX_N];
double d[MAX_N];

bool C(double avg) {
	for (int i = 0; i < N; ++i)
		d[i] = A[i] - B[i] * avg;
	sort(d, d + N);
	double sum = 0.;
	for (int i = 0; i < k; ++i)
		sum += d[N - i - 1];
	return sum >= 0;
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &N, &k) && (N || k)) {
		for (int i = 0; i < N; ++i)
			scanf("%d", A + i);
		for (int i = 0; i < N; ++i)
			scanf("%d", B + i);
		double lb = 0, ub = INF;
		k = N - k;
		for (int i = 0; i < 100; ++i) {
			// cout << lb << " " << ub << endl;
			double mid = (lb + ub) / 2;
			if (C(mid)) lb = mid;
			else ub = mid;
		}
		printf("%.0f\n", lb * 100);
	}
	return 0;
}