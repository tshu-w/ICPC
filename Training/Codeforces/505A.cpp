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
const int MAX_N = 1e6 + 10;

string s, ss;
int len;

bool ok() {
	int len = ss.size();
	for (int i = 0; i < len / 2; ++i)
		if (ss[i] != ss[len - i - 1])
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	cin >> s;
	len = s.size();
	for (int i = 0; i < len; ++i) {
		ss = s;
		ss.erase(ss.begin() + i);
		if (ok()) {
			ss = s[i];
			if (i * 2 < len) s.insert(len - i, ss);
			else s.insert(len - i - 1, ss);
			cout << s << endl;
			return 0;
		}
	}
	printf("NA\n");
	return 0;
}