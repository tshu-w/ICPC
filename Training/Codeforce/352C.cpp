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
const int MAX_N = 1e5 + 5;

const double PI = acos(-1.0);

template <typename T>
inline T sqr(T a) { return a * a;}

class Point {
public:
	double x, y;
	friend double dis(Point A, Point B) {
		return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
	}
	void print() {
		printf("(%.2f, %.2f)\n", x, y);
	}
};

int main(int argc, char const *argv[])
{
	Point a, b, t, p[MAX_N];
	int n, amax, bmax;
	double ans = 0., damax, dbmax, dmax;
	scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &t.x, &t.y);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		ans += 2.0 * dis(p[i], t);
	}
	damax = -(double)1e9 * sqrt(2);
	for (int i = 0; i < n; ++i) {
		// cout << i << " " << dis(t, p[i]) - dis(a, p[i]) << endl;
		if (dis(t, p[i]) - dis(a, p[i]) > damax) {
			damax = dis(t, p[i]) - dis(a, p[i]);
			amax = i;
		}
	}
	// p[amax].print();
	dbmax = 0;
	for (int i = 0; i < n; ++i) if (i != amax){
		if (dis(t, p[i]) - dis(b, p[i]) > dbmax) {
			dbmax = dis(t, p[i]) - dis(b, p[i]);
			bmax = i;
		}
	}
	// p[bmax].print();
	dmax = damax + dbmax;
	swap(a, b);
	damax = -(double)1e9 * sqrt(2);
	for (int i = 0; i < n; ++i) {
		// cout << i << " " << dis(t, p[i]) - dis(a, p[i]) << endl;
		if (dis(t, p[i]) - dis(a, p[i]) > damax) {
			damax = dis(t, p[i]) - dis(a, p[i]);
			amax = i;
		}
	}
	// p[amax].print();
	dbmax = 0;
	for (int i = 0; i < n; ++i) if (i != amax){
		if (dis(t, p[i]) - dis(b, p[i]) > dbmax) {
			dbmax = dis(t, p[i]) - dis(b, p[i]);
			bmax = i;
		}
	}
	// p[bmax].print();
	dmax = max(damax + dbmax, dmax);
	ans -= dmax;
	printf("%.10lf\n", ans);
	return 0;
}