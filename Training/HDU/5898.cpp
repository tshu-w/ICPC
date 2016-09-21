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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, cs = 0;
ll dp[20][20][3], l, r;
int num[20];

ll dfs(int pos, int cnt, int parity, bool zero, bool edge) {
	if (pos == -1) return parity ? !(cnt & 1) : (cnt & 1);
	if (!edge && ~dp[pos][cnt][parity]) return dp[pos][cnt][parity];
	ll res = 0;
	int ed = edge ? num[pos] : 9;
	for (int i = 0; i <= ed; ++i) {
		if (i & 1) { // odd
			if (parity) // pre odd
				res += dfs(pos - 1, cnt + 1, 1, (i == 0) && zero, (i == ed) && edge);
			else if (zero || (cnt & 1)) // pre even || zero
				res += dfs(pos - 1, 1, 1, (i == 0) && zero, (i == ed) && edge);
		} else { // even
			if (!parity) // pre even
				res += dfs(pos - 1, (zero && i == 0)? 0 : cnt + 1, 0, (i == 0) && zero, (i == ed) && edge);
			else if (!(cnt & 1)) // pre odd
				res += dfs(pos - 1, 1, 0, (i == 0) && zero, (i == ed) && edge);
		}	
	}
	if (!edge) dp[pos][cnt][parity] = res;
	return res;
}

ll cnt(ll n) {
	int pos = 0;
	while (n) {
		num[pos++] = n % 10;
		n /= 10;
	}
	return dfs(pos - 1, 0, 0, true, true);
}

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &l, &r);
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %lld\n", ++cs, cnt(r) - cnt(l - 1));
	}
	return 0;
}
