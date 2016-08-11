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
const int MAX_N = 3e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

ll N, M, sum[MAX_N], cnt[MAX_N], imax, x;

int main(int argc, char const *argv[])
{
	scanf("%I64d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%I64d", &x);
		++cnt[x];	
		imax = max(imax, x);
	}
	for (int i = 1; i <= imax; ++i) 
		for (int j = 1; j <= imax; ++j) {
			if (i * j >= MAX_N) break;
			sum[i * j] += cnt[i] * cnt[j] - ((i == j) ? cnt[i] : 0);
		}
	for (int i = 1; i < MAX_N; ++i)
		sum[i] += sum[i - 1];	
	scanf("%I64d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%I64d", &x);
		printf("%I64d\n", N * (N - 1) - sum[x - 1]);
	}
	return 0;
}