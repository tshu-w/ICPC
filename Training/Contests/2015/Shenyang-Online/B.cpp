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
const int MAX_N = 50005;
ll MOD;

template <typename T>
inline T sqr(T a) { return a * a;}

struct Matrix {
	ll a[2][2];
	Matrix() {
		memset(a, 0, sizeof(a));
	}
	friend Matrix operator *(Matrix a, Matrix b) {
		Matrix c;
		memset(c.a, 0, sizeof(c.a));
		for (int i = 0; i < 2; ++i) 
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
		return c;
	};
};
struct Tr
{
	int a, b;
	ll t;
};
vector<Tr> mrk[50000];
int main(int argc, char const *argv[])
{
	int t, tt = 0;
	ll n;
	cin >> t;
	while (t--) {
		cin >> n >> MOD;
		for (int i = 0; i < MOD; ++i)
			mrk[i].clear();
		Matrix x, y;
		x.a[0][0] = x.a[1][1] = 5 % MOD;
		x.a[0][1] = 12 % MOD;
		x.a[1][0] = 2 % MOD;
		y = x;
		ll cnt = 1, sct;
		while (true) {
			Tr pr;
			bool flag = false;
			pr.a = x.a[0][1];
			pr.b = x.a[0][0];
			pr.t = cnt;
			for (int i = 0; i < (int)mrk[pr.b].size(); ++i)
				if (mrk[pr.b][i].a == pr.a) {
					sct = mrk[pr.b][i].t;
					flag = true;
				}
			if (flag) break;
			mrk[pr.b].push_back(pr);
			x = x * x;
			++cnt;
		}
		cnt -= sct;
		x = y;
		for (int i = 0; i < min(n, sct); ++i)
			x = x * x;
		if (n > sct) {
			n -= sct;
			n = n % cnt;
			for (int i = 0; i < n; ++i)
				x = x * x;
		}
		x = x * y;
		ll ans = (2 * x.a[0][0] - 1) % MOD;
		cout << "Case #" << ++tt << ": " << ans << endl;
	}
	// while (t--) {
	// 	cin >> n >> MOD;
	// 	x1 = x2 = 5;
	// 	y1 = y2 = 2;
	// 	for (int i = 0; i < n; ++i) {
	// 		x = (x1 * x2 + y1 * y2 * 6) % MOD;
	// 		y = (x1 * y2 + x2 * y1) % MOD;
	// 		// cout << x << " " << y << endl;
	// 		x1 = x2 = x;
	// 		y1 = y2 = y;
	// 	}
	// 	x = (5 * x2 + 2 * y2 * 6) % MOD;
	// 	y = (5 * y2 + x2 * 2) % MOD;
	// 	// cout << x << " " << y << endl;
	// 	cout << "Case #" << ++cases << ": " << (2 * x - 1) % MOD << endl;
	// }
	return 0;
}