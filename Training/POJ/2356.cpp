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
const int MAX_N = 1e4 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, A[MAX_N], sum[MAX_N], flag[MAX_N];

int main(int argc, char const *argv[])
{
	cin >> n;
	memset(flag, 0, sizeof flag);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];	
		sum[i + 1] = sum[i] + A[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (sum[i] % n == 0) {
			cout << i << endl;
			for (int j = 0; j < i; ++j)
				cout << A[j] << endl;
			return 0;
		}
		if (flag[sum[i] % n]) {
			cout << i - flag[sum[i] % n] << endl;
			for (int j = flag[sum[i] % n]; j < i; ++j)
				cout << A[j] << endl;
			return 0;
		} else flag[sum[i] % n] = i;
	}
	return 0;
}