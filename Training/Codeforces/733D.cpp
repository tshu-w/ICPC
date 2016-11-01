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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N][5], ans[5], k;

bool C(int d) {
	map<Pii, int> m, it;
	for (int i = 0; i < N; ++i) 
		if (A[i][1] >= d && A[i][2] >= d) {
			if (A[i][0] >= d) {
				k = 1;
				ans[0] = i;
				return true;
			}
			Pii p = Pii(A[i][1], A[i][2]);
			if (m[p] != 0) {
				if (m[p] + A[i][0] >= d) {
					k = 2;
					ans[0] = it[p];
					ans[1] = i;
					return true;
				}
				if (m[p] < A[i][0]) {
					m[p] = A[i][0];
					it[p] = i;
				}
			} else {
				m[p] = A[i][0];
				it[p] = i;
			}
		}
	return false;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &A[i][j]);
		}
		sort(A[i], A[i] + 3);
	}
	int lb = 0, ub = INF;
	while (ub - lb > 1) {
		int mid = (ub - lb) / 2 + lb;
		if (C(mid)) lb = mid;
		else ub = mid;
	}
	printf("%d\n", k);
	for (int i = 0; i < k; ++i)
		printf("%d%c", ans[i] + 1, i + 1 == k ? '\n' : ' ');
	return 0;
}