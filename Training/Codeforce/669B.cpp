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
const int MAX_N = 100000 + 10;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	int n;
	bool flag[MAX_N];
	int len[MAX_N];
	scanf("%d", &n);
	string s;
	cin >> s;
	fill(flag, flag + n, false);
	for (int i = 0; i < n; ++i)
		scanf("%d", &len[i]);
	int p = 0;
	while (p >= 0 && p < n) {
		// printf("%d\n", p);
		if (flag[p]) {
			printf("INFINITE\n");
			return 0;
		}
		flag[p] = true;
		if (s[p] == '>')
			p += len[p];
		else 
			p -= len[p];
	}
	printf("FINITE\n");
	return 0;
}