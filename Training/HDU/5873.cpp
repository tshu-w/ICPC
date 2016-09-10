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
const int MAX_N = 20000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, m, B[MAX_N];

int main(int argc, char const *argv[])
{
	while (~scanf("%d", &t)) {
		while (t--) {
			scanf("%d", &m);
			for (int i = 0; i < m; ++i)
				scanf("%d", B + i);
			sort(B, B + m);
			ll sum = 0;
			bool flag = true;
			for (int i = 0; i + 1 < m && flag; ++i) {
				sum += B[i];
				if (sum < 1LL * i * (i + 1)) flag = false;
			}
			sum += B[m - 1];
			if (sum != 1LL * m * (m - 1)) flag = false;
			if (flag) printf("T\n");
			else printf("F\n");
		}	
	}
	return 0;
}