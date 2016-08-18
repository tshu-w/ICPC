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
// const int MAX_N = ;
const double pi = 2.0 * asin(1.0);

int main(int argc, char const *argv[])
{
	double d, h, v, e, t;
	cin >> d >> h >> v >> e;
	double s = pi * d * d / 4.0;
	if (e * s > v) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		t = h / (v / s - e);
		printf("%.12lf\n", t);
	}
	return 0;
}