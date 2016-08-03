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
const int MAX_N = 30;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, m, cases = 0;
bool flag[MAX_N][MAX_N];
string s1, s2;

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		cin >> s1;
		cin >> s2;
		scanf("%d", &m);
		memset(flag, false, sizeof flag);
		for (int i = 0; i < m; ++i) {
			char d, b;
			do d = getchar(); while (d == ' ' || d == '\n');
			do b = getchar(); while (b == ' ' || b == '\n');
			flag[d - 'a'][b - 'a'] = true;	
		}
		int i, j, l1, l2;
		i = j = 0;
		l1 = s1.size(); l2 = s2.size();
		while (i < s1.size() && j < s2.size()) 
			if (s1[i] == s2[j] || flag[s2[j] - 'a'][s1[i] - 'a']) {
				++i; ++j;
			} else {
				++j;
			}
		// cout << i << " " << j << endl;
		if (i == s1.size()) 
			printf("Case #%d: happy\n", ++cases);
		else 
			printf("Case #%d: unhappy\n", ++cases);
	}	
	return 0;
}