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

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50000 + 10;

const int ST_SIZE = 1 << 18;

int N, Q, A[MAX_N], l, r;
Pii dat[ST_SIZE];

void init(int k, int l, int r) {
	if (l + 1 == r)
		dat[k] = Pii(A[l], A[l]);
	else {
		int lch = 2 * k + 1, rch = 2 * k + 2;
		init(lch, l, (l + r) / 2);
		init(rch, (l + r) / 2, r);
		dat[k] = Pii(min(dat[lch].first, dat[rch].first), max(dat[lch].second, dat[rch].second));
	}
}
Pii query(int a, int b, int k, int l, int r) {
	if (b <= l || r <= a) 
		return Pii(INF, 0);
	else if (a <= l && r <= b)
		return dat[k];
	else {
		int lch = 2 * k + 1, rch = 2 * k + 2;
		Pii pl = query(a, b, lch, l, (l + r) / 2);
		Pii pr = query(a, b, rch, (l + r) / 2, r);
		return Pii(min(pl.first, pr.first), max(pl.second, pr.second));
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i)
		scanf("%d", A + i);
	init(0, 0, N);
	for (int i = 0; i < Q; ++i) {
		scanf("%d%d", &l, &r);
		Pii p = query(l - 1, r, 0, 0, N);
		printf("%d\n", p.second - p.first);
	}
	return 0;
}

// const int B = 300;

// int N, Q, A[MAX_N], l, r;
// vector<int> bucket[MAX_N / B];


// int main(int argc, char const *argv[])
// {
// 	scanf("%d%d", &N, &Q);
// 	for (int i = 0; i < N; ++i) {
// 		scanf("%d", A + i);
// 		nums[i] = A[i];
// 		bucket[i / B].push_back(A[i]);
// 	}	
// 	for (int i = 0; i < N / B; ++i)
// 		sort(bucket[i].begin(), bucket[i].end());
// 	for (int i = 0; i < Q; ++i) {
// 		scanf("%d%d", &l, &r); --l;
// 		int imin = INF, imax = 0;
// 		while (l < r && l % B != 0) { imin = min(imin, A[l]); imax = max(imax, A[l]); ++l;}
// 		while (l < r && r % B != 0) { --r; imin = min(imin, A[r]); imax = max(imax, A[r]);}
// 		while (l < r) {
// 			int b = l / B;
// 			imin = min(bucket[b].front(), imin);
// 			imax = max(bucket[b].back(), imax);
// 			l += B;
// 		}
// 		printf("%d\n", imax - imin);
// 	}
// 	return 0;
// }