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
const int MAX_N = 1e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

double sum[MAX_N];
string s;

int main(void) {
	sum[1] = 1.;
	for (ll i = 2; i < MAX_N; ++i) 
		sum[i] = sum[i - 1] + 1. / (i * i);
	while (cin >> s) {
		int p;
		for (p = 0; p < s.size(); ++p)
			if (s[p] != 0) break;
		if (s.size() - p > 6)
			printf("1.64493\n");
		else printf("%.5f\n", sum[stoi(s)]);
	}
	return 0;
}
