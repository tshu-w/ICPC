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
const int MAX_N = 100;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	int n, d;
	scanf("%d", &n);
	d = (n + 1) / 2;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < abs(i - d); ++j)
			printf("*");
		for (int j = 0; j < n - 2 * (abs(i - d)); ++j)
			printf("D");
		for (int j = 0; j < abs(i - d); ++j)
			printf("*");
		printf("\n");
	}
	return 0;
}