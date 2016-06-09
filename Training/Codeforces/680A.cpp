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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 100 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};


int main(int argc, char const *argv[])
{
	int flag[MAX_N], x, sum = 0, ans;
	memset(flag, 0, sizeof flag);
	for (int i = 0; i < 5; ++i)
		cin >> x, ++flag[x], sum += x;
	ans = sum;
	for (int i = MAX_N - 1; i >= 0; --i)
		if (flag[i] == 2)
			ans = min(ans, sum - flag[i] * i);
		else if (flag[i] >= 3)
			ans = min(ans, sum - i * 3);
	cout << ans << endl;
	return 0;
}