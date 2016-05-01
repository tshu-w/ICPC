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
// const int MAX_N = ;

const double PI = acos(-1.);

int main(int argc, char const *argv[])
{
	ull n;
	scanf("%llu", &n);
	if (n % 3 == 0)
		printf("%llu\n",  2 * n / 3);
	else 
		printf("%llu\n", (n / 3)* 2 + 1);
	return 0;
}