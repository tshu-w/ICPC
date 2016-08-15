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
const int MAX_N = 15;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N, A[MAX_N], cs = 0;

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		int sum = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", A + i);
			sum += A[i];
		}
		int p1 = 0, p2 = 1, cnt = 0, nxt = 2;
		while (cnt < sum / 2) {
			if (A[p1] > 0) {
				--A[p1];	
				++cnt;
				swap(p1, p2);
			} else {
				p1 = nxt;
				++nxt;
			}
		}
		printf("Case #%d: %d\n", ++cs, cnt);
	}	
	return 0;
}