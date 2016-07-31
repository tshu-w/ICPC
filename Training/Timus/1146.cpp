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

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif	
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

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

int N, A[MAX_N][MAX_N], ans, S[MAX_N][MAX_N];

int max_sub_array(int * a, int n) {
	int res, cur;
	if (!a || n <= 0) return 0;
	res = cur = a[0];
	for (int i = 1; i < n; ++i) {
		if (cur < 0)
			cur = a[i];
		else
			cur += a[i];
		res = max(res, cur);
	}
	return res;
}
void solve() {
	int sub[MAX_N];
	memset(S, 0, sizeof S);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			S[i][j + 1] = S[i][j] + A[i][j];
	ans = -INF;
	for (int f = 0; f < N; ++f)
		for (int b = f; b < N; ++b) {
			for (int i = 0; i < N; ++i)
				sub[i] = S[i][b + 1] - S[i][f];
			ans = max(ans, max_sub_array(sub, N));	
		}
	cout << ans << endl;
} 
int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];	
	solve();
	return 0;
}