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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 500 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, K, A[MAX_N], B[MAX_N];
vector<Pii> ans;

bool solve(int l, int r) {
	int imax = 0, it = -1;
	for (int i = l; i < r; ++i)
		if (imax <= A[i] && ((i > l && A[i] > A[i - 1]) || (i + 1 < r && A[i] > A[i + 1]))){
			it = i;
			imax = A[i];
		}
	if (it == -1 && l + 1 != r) return false;
	while (r - l > 1) {
		bool f = false;
		if (it > l && A[it] > A[it - 1]) {
			A[it - 1] += A[it];
			ans.push_back(Pii(it, 0)); --N;
			for (int i = it; i < N; ++i)
				A[i] = A[i + 1];
			--it;
			f = true;
			--r;
		}
		if (it + 1 < r && A[it] > A[it + 1]) {
			A[it] += A[it + 1];
			ans.push_back(Pii(it, 1)); --N;
			for (int i = it + 1; i < N; ++i)
				A[i] = A[i + 1];
			f = true;
			--r;
		}
		if (!f) return f;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", A + i);
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
		scanf("%d", B + i);
	bool flag = true;
	int l = 0, r;
	for (int i = 0; i < K; ++i)	{
		r = l;
		int sum = 0;
		while (r < N && sum < B[i]) 
			sum += A[r++];
		if (sum != B[i] || (r == N && i + 1 != K)) {
			flag = false;
			break;
		}
		flag = solve(l, r);
		++l;
	}
	if (flag && N == K) {
		printf("YES\n");
		for (int i = 0; i < ans.size(); ++i)
			printf("%d %c\n", ans[i].first + 1, ans[i].second ? 'R' : 'L');
	} else
		printf("NO\n");
	return 0;
}