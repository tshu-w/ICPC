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

typedef long L;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef long double LD;

const int INF = INT_MAX;
const int MAX_N = 100000 + 10;

int main(int argc, char const *argv[])
{
	int l[MAX_N], n, z;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &l[i]);
	sort(l, l + n);
	int ans = l[n - 1];
	for (int i = n - 2; i >= 0; --i)
		if (ans > 0) 
			ans -= l[i];
		else ans += l[i];
	printf("%d\n", ans + 1);
	return 0;
}