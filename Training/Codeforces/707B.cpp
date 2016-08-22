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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M, K, ans = INF;
bool flag[MAX_N];
vector<pair<int, Pii> > es;

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0, u, v, l; i < M; ++i) {
		scanf("%d%d%d", &u, &v, &l);
		es.emplace_back(l, Pii(u, v));
	}
	for (int i = 0, a; i < K; ++i) {
		scanf("%d", &a);
		flag[a] = true;
	}
	sort(es.begin(), es.end());
	for (int i = 0; i < M; ++i)
		if (flag[es[i].second.first] ^ flag[es[i].second.second]) {
			ans = min(ans, es[i].first);
		}
	if (ans == INF)
		printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}