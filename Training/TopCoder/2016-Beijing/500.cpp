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
const int MAX_N = 1000 + 5;
const int MAX_K = 1000 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

class DarkMatterParticles
{
public:
	void init(int n) {
	    for (int i = 0; i < n; ++i) {
	        par[i] = i;
	        rnk[i] = 0;
	        cnt[i] = 0;
	    }
	}
	int find(int x) {
	    return par[x] == x? x : par[x] = find(par[x]);
	}
	bool same(int a, int b) {
	    return find(a) == find(b);
	}
	void unite(int x, int y) {
	    x = find(x);
	    y = find(y);
	    if (x == y) return;
	    if (rnk[x] < rnk[y]) {
	        par[x] = y;
	    } else {
	        par[y] = x;
	        if (rnk[x] == rnk[y]) rnk[x]++;
	    }
	}
	string SplitParticles(int n, int k, vector <int> x, vector <int> y) {
		init(n);
		for (int i = 0; i < x.size(); ++i) {
			int a, b;
			a = x[i];
			b = y[i];
			unite(a, b);
		}
		fill(flag, flag + n, false);
		for (int i = 0; i < n; ++i)
			++cnt[find(i)];
		// for (int i = 0; i < n; ++i)
			// cout << i << " " << cnt[i] << endl;
		for (int i = 0; i < n; ++i) {
			int fi = find(i);
			if (!flag[fi]) {
				if (cnt[fi]) //fts cnt[i] 
					v.push_back(cnt[fi]); // fts cnt[i]
				flag[fi] = true;
			}
		}
		// for (int i = 0; i < v.size(); ++i)
			// cout << v[i] << endl;
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i = 0; i < v.size(); ++i)
			for (int j = k; j >= v[i]; --j)
				if (dp[j - v[i]]) {
					dp[j] = 1;
				}
		if (dp[k]) {
			cout << "Possible" << endl;
			return "Possible";
		}
		else {
			cout << "Impossible" << endl;
			return "Impossible";
		}
	}
	int par[MAX_N], rnk[MAX_N], cnt[MAX_N], dp[MAX_K];
	bool flag[MAX_N];
	vector<int> v;
};

int main(int argc, char const *argv[])
{
	vector<int> x = {0, 1, 4};
	vector<int> y = {1, 2, 5};
	DarkMatterParticles bug;
	cout << bug.SplitParticles(6, 3, x, y) << endl;
	return 0;
}