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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

ll N;

int eluer_phi(int n) {
	int res = n;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			res = res / i * (i - 1);
			for (; n % i == 0; n /= i);
		}
	}
	if (n != 1) res = res / n * (n - 1);
	return res;
}

int main(int argc, char const *argv[])
{
	while (~scanf("%lld", &N) && N) {
		printf("%d\n", eluer_phi(N));
	}	
	return 0;
}