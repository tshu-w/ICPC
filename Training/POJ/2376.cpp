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
const int MAX_N = 25000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, T;
Pii C[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &C[i].first, &C[i].second);
	sort(C, C + N);
	int s = 0, last = 0, cur = 0, ans = 0;
	while (s < N) {
		while (C[s].first <= last + 1) {
			cur = max(cur, C[s].second);
			++s;
		}
		if (last == cur) break;
		last = cur;
		++ans;
	}
	if (last >= T) 
		printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}