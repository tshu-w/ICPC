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
const int MAX_N = 200;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, k, cnt[MAX_N], imin = 0, imax = 0;
string test, pd;

int main(int argc, char const *argv[])
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> test;
		cnt[test.size()]++;
	}
	cin >> pd;
	for (int i = 1; i < pd.size(); ++i)
		imin += cnt[i];
	imax = imin + cnt[pd.size()];
	++imin;
	imin = imin + (imin - 1) / k * 5;
	imax = imax + (imax - 1) / k * 5;
	cout << imin << " " << imax << endl;
	return 0;
}