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

int N, M, R, dp[MAX_N], ans = 0;
pair<Pii, int> A[MAX_N];

int main(int argc, char const *argv[])
{
	cin >> N >> M >> R;
	for (int i = 0; i < M; ++i)
		cin >> A[i].first.first >> A[i].first.second >> A[i].second;
	sort(A, A + M);
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < i; ++j)
			if (A[j].first.second + R <= A[i].first.first) 
				dp[i] = max(dp[i], dp[j]);
		dp[i] += A[i].second;
		ans = max(ans, dp[i]);	
	}
	cout << ans << endl;
	return 0;
}