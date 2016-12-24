// written at 22:15 on 22 Dec 2016 
// #include <bits/stdc++.h>
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 17;
const int MAX_S = 1 << 17;

int n, dp[MAX_S], X[MAX_N], Y[MAX_N];
vector<Pii> v;

bool in(int a, int b, int c) {
	return (min(X[b], X[c]) <= X[a] && X[a] <= max(X[b], X[c]) && min(Y[b], Y[c]) <= Y[a] && Y[a] <= max(Y[b], Y[c]));
}

void init() {
	v.clear();
	rep(i, 0, n)
		rep(j, i + 1, n) {
			Pii p = Pii((1 << i | 1 << j), max(1, abs(X[i] - X[j])) * max(1, abs(Y[i] - Y[j])));
			rep (k, 0, n)
				if (in(k, i, j))
					p.first |= 1 << k;
			v.push_back(p);
		}
	// for(auto it : v)
		// cout << it.first << " " << it.second << endl;
	// cout << endl;
}

void solve() {
	fill(dp, dp + (1 << n), INF);
	dp[0] = 0;
	rep(it, 0, v.size())
		rep(S, 0, 1 << n) {
			int T = S | v[it].first;
			if (dp[S] != INF && T != S)
				dp[T] = min(dp[T], dp[S] + v[it].second);
		}
	printf("%d\n", dp[(1 << n) - 1]);
}

int main(void) {
	while (scanf("%d", &n) && n) {
		rep(i, 0, n)
			scanf("%d%d", X + i, Y + i);
		init();
		solve();
	}
	return 0;
}
