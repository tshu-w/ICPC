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
const int MAX_N = 100 + 10;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	bool flag[MAX_N];
	string line;
	int n, x, p, q;
	scanf("%d", &n);
	fill(flag + 1, flag + n + 1, false);
	scanf("%d", &p);
	for (int i = 0; i < p; ++i) {
		scanf("%d", &x);
		flag[x] = true;
	}
	scanf("%d", &p);
	for (int i = 0; i < p; ++i) {
		scanf("%d", &x);
		flag[x] = true;
	}
	// getline(cin, line);
	// getline(cin, line);
	// stringstream ss(line);
 //    while (ss >> x) {
 //    	flag[x] = true;
 //    	// printf("%d\n", x);
 //    }
 //    getline(cin, line);
 //    stringstream st(line);
 //    while (st >> x) {
 //    	flag[x] = true;
 //    	// printf("%d\n", x);
 //    }
    // for (int i = 1; i <= n; ++i)
    	// printf("%d %d\n", i, flag[i]);
	for (int i = 1; i <= n; ++i)
		if (!flag[i]) {
			printf("Oh, my keyboard!\n");
			return 0;
		}
	printf("I become the guy.\n");
	return 0;
}