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
	int n, ans = 0;
	bool flag[30];
	fill(flag, flag + 30, false);
	string s;
	scanf("%d", &n);
	cin >> s;
	if (n > 26) {
		printf("%d\n", -1);
		return 0;
	}
	for (int i = 0; i < s.length(); ++i)
		if (flag[s[i] - 'a']) {
			++ans;
		} else {
			flag[s[i] - 'a'] = true;
		}
	cout << ans << endl;
	return 0;
}