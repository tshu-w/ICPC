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
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, A[MAX_N];
set<int> s;

bool C(int m) {
	int last = m % 10;
	m /= 10;
	while (m) {
		if (m % 10 + 1 != last) return false;
		last = m % 10;
		m /= 10;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", A + i);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (C(A[i] * A[j])) s.insert(A[i] * A[j]);
	if (s.size())
		printf("%d\n", *s.rbegin());
	else printf("%d\n", -1);
	return 0;
}