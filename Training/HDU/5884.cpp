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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, T, t, A[MAX_N], B[MAX_N];

bool C(int k) {
	int la, lb, rb, sum;
	ll res;
	la = lb = rb = 0;
	res = 0LL;
	if ((N - 1) % (k - 1) != 0) {
		sum = 0;
		for (; la < (N - 1) % (k - 1) + 1; ++la) {
			sum += A[la];
		}
		B[rb++] = sum;
		res += sum;
	}
	// cout << res << endl;
	while (N - la + rb - lb >= k) {
		sum = 0;
		for (int i = 0; i < k; ++i) {
			if (la == N) sum += B[lb++];
			else if (lb == rb) sum += A[la++];
			else
			if (A[la] <= B[lb]) {
				sum += A[la++];
			} else {
				sum += B[lb++];
			}
			// cout << "la = " << la << " ";
			// cout << "lb = " << lb << endl;
		}
		// cout << "sum = " << sum << endl;
		B[rb++] = sum;
		// cout << "rb = " << rb << endl;
		res += sum;
	}
	// cout << k << " " << res << endl;
	return res <= T;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &N, &T);
		for (int i = 0; i < N; ++i)
			scanf("%d", A + i);
		sort(A, A + N);
		int l = 1, r = N, mid;
		while (l + 1 < r) {
			mid = (r - l) / 2 + l;
			if (C(mid)) r = mid;
			else l = mid;
			// cout << l << " " << r << endl;
		}
		printf("%d\n", r);
	}
	return 0;
}