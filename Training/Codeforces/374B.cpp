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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

string s;

int main(int argc, char const *argv[])
{
	cin >> s;
	ll ans = 1;
	int cnt = 0, i = 0;
	while (i < s.size()) {
		while (i + 1 < s.size() && s[i] - '0' + s[i + 1] - '0' == 9) {
			++cnt;
			++i;
		}
		// cout << i << " " << cnt << endl;
		if (cnt % 2 == 0) ans *= cnt / 2 + 1;
		++i;cnt = 0;
	}
	cout << ans << endl;
	return 0;
}