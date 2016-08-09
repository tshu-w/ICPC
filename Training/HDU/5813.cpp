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

int t, cs = 0, N;
Pii A[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &A[i].first);
			A[i].second = i + 1;
			sum += A[i].first;
		}
		sort(A, A + N);
		bool flag = true;
		for (int i = 0; i < N && flag; ++i)
			if (A[i].first > i) flag = false;
		if (flag) {
			printf("Case #%d: Yes\n%d\n", ++cs, sum);
			for (int i = 0; i < N; ++i) 
				for (int j = 0; j < A[i].first; ++j) {
					printf("%d %d\n", A[i].second, A[j].second);
				}	
		} else {
			printf("Case #%d: No\n", ++cs);
		}
	}
	return 0;
}