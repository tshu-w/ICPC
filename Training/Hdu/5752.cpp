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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const double eps = 1e-6;
const int INF = INT_MAX;
const unsigned long long MAX_N = pow(2, 32) - 1;

template <typename T>
inline T sqr(T a) { return a * a;};

bool is_greater(string s, ull n) {
	if (s.size() > (int)(log(n) / log(10)) + 1)
		return true;
	ull res = 0;
	for (int i = 0; i < s.size(); ++i)
		res = res * 10 + s[i] - '0';
	return res > n;
}

int main(int argc, char const *argv[])
{
	string s;
	while (cin >> s) {
		if (is_greater(s, MAX_N) || (s.size() == 1 && s[0] == '0')) {
			cout << "TAT" << endl;
		}
		else {
			int cnt = 0;
			ull res = 0;
			for (int i = 0; i < s.size(); ++i)
				res = res * 10 + s[i] - '0';
			while (res != 1) {
				res = (int)(sqrt(res) + eps);
				++cnt;
			}
			cout << cnt << endl;
		}
	}	
	return 0;
}