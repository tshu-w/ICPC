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

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	bool flag = false;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == '.') flag = true;
	if (!flag) s += ".";
	if (s[0] == '.') s = "0" + s;
	if (s[s.size() - 1] == '.') s = s + "0";
	int l, r, pos;
	for (l = 0; l < s.size(); ++l)
		if (s[l] != '.' && s[l] != '0') break;
	for (r = s.size() - 1; r >= 0; --r)
		if (s[r] != '.' && s[r] != '0') break;
	for (pos = 0; pos < s.size(); ++pos)
		if (s[pos] == '.') break;
	cout << s[l];
	if (l != r) cout << '.';
	for (int i = l + 1; i <= r; ++i)
		if (s[i] != '.')
			cout << s[i];
	if (pos != l + 1) {
		cout << "E" << pos - l - ((l < pos) ? 1 : 0);
	}
	cout << endl;
	return 0;
}