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
const int MAX_N = 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
	int n;	
	set<int> X, Y;
	cin >> n;
	for (int i = 0, x, y; i < n; ++i) {
		cin >> x >> y;	
		X.insert(x); Y.insert(y);
	}
	if (X.size() <= 1 || Y.size() <= 1) 
		cout << -1 << endl;
	else {
		int a, b, c, d;
		auto xit = X.begin();
		a = *xit; ++xit; b = *xit;
		auto yit = Y.begin();
		c = *yit; ++yit; d = *yit;
		cout << (b - a) * (d - c) << endl;	
	}
	return 0;
}