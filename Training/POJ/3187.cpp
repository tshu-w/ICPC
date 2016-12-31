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
const int MAX_N = 15;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
	int N, A[MAX_N], B[MAX_N][MAX_N], sum;
	cin >> N >> sum;
	for (int i = 0; i < N; ++i)
		A[i] = i + 1;	
	do {
		for (int i = 0; i < N; ++i)
			B[0][i] = A[i];
		for (int i = 1; i < N; ++i)
			for (int j = 0; j + i < N; ++j)
				B[i][j] = B[i - 1][j] + B[i - 1][j + 1];
		if (sum == B[N - 1][0]) break;
	} while (next_permutation(A, A + N));
	for (int i = 0; i < N; ++i)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}