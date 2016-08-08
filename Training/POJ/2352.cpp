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
const int MAX_N = 32000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, cnt[MAX_N];

int bit[MAX_N];
int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
void add(int i, int x) {
	while (i <= 32001) {
		bit[i] += x;
		i += i & -i;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		cnt[sum(++x)]++;
		add(x, 1);
	}	
	for (int i = 0; i < n; ++i) 
		printf("%d\n", cnt[i]);

	return 0;
}