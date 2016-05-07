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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 30;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	int k, w[30], wmax = 0, ans = 0;
	string s;
	cin >> s;
	scanf("%d", &k);
	for (int i = 1; i <= 26; ++i) {
		scanf("%d", &w[i]);
		wmax = max(wmax, w[i]);
	}
	int i;
	for (i = 0; i < s.length(); ++i) {
		ans += (i + 1) * w[s[i] - 'a' + 1];
		// printf("%d\n", w[s[i] - 'a' + 1]);
	}
	// printf("%d\n", ans);
	for (i = s.length();i < s.length() + k; ++i)
		ans += (i + 1)* wmax;
	printf("%d\n", ans);
	return 0;
}