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
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N, M, A[MAX_N], B[MAX_N], C[MAX_N];
bool vis[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &N, &M);
		bool flag = true;
		for (int i = 0; i < N; ++i)
			scanf("%d", A + i);
		for (int i = 0; i < N; ++i)
			scanf("%d", B + i);
		memset(vis, false, sizeof vis);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (!vis[j] && A[i] == B[j]) {
					// cout << i << " " << j << endl;
					vis[j] = true;
					C[i] = j;
					break;
				}
		for (int i = 0; i < N; ++i)
			flag &= vis[i];
		for (int i = 0, l, r; i < M; ++i) {
			scanf("%d%d", &l, &r); --l; --r;
			if (flag) sort(C + l, C + r + 1);
		}
		for (int i = 0; flag && i < N; ++i)
			if (C[i] != i) flag = false;
		printf("%s\n", flag ? "Yes" : "No");
	}	
	return 0;
}