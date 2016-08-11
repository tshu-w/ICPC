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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
char s[MAX_N];

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &N, s);
		int l, r, len;
		bool flag = true;
		l = r = -1;
		len = strlen(s);
		for (int i = 0; i < len; ++i)
			if (s[i] == ')') {
				l = i; break;
			}
		for (int i = len - 1; i >= 0; --i)
			if (s[i] == '(') {
				r = i; break;
			}
		if (l + 1 && r + 1)
		swap(s[l], s[r]);
		int st = 0;
		for (int i = 0; i < len && flag; ++i) {
			if (s[i] == '(') ++st;
			if (s[i] == ')') --st;
			if (st < 0)
				flag = false;
		}
		printf("%s\n", flag && !st ? "Yes" : "No");
	}
	return 0;
}