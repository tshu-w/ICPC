// written at 08:44 on 26 Dec 2016 
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
const int MAX_N = 1e5 + 10;

int n, k, m;

typedef vector<ll> vec;
typedef vector<vec> mat;
mat B;
mat mat_mul(mat &A, mat &B) {
	mat C(A.size(), vec(B[0].size()));
	rep(i, 0, A.size()) rep(k, 0, B.size()) if (A[i][k]) rep(j, 0, B[0].size())
		C[i][j] += A[i][k] * B[k][j];
	return C;
}
mat mat_pow(mat &A, int n) {
	mat B(A.size(), vec(A.size()));
	rep(i, 0, A.size()) B[i][i] = 1;
	while (n) {
		if (n & 1) B = mat_mul(B, A);
		A = mat_mul(A, A);
		n >>= 1;
	}
	return B;
}
mat gen(int tp, int a, int b = 0) {
	mat B(n + 1, vec(n + 1));
	rep(i, 0, n + 1) B[i][i] = 1;
	if (tp == 0) {
		B[a][n] = 1;
		return B;
	}
	if (tp == 1) {
		B[a][a] = 0;
		return B;
	}
	if (tp == 2) {
		B[a][a] = 0; B[a][b] = 1;
		B[b][b] = 0; B[b][a] = 1;
		return B;
	}
	return B;
}

int main(int argc, char const *argv[])
{
	while (scanf("%d%d%d", &n, &m, &k) && n + m + k) {
		mat A(n + 1, vec(n + 1)), B(n + 1, vec(n + 1));
		rep(i, 0, n + 1) A[i][i] = 1;
		rep(i, 0, k) {
			char opt[4];
			int a, b;
			scanf("%s", opt);
			if (opt[0] == 'g') {
				scanf("%d", &a); --a;
				++A[a][n];
			}
			if (opt[0] == 'e') {
				scanf("%d", &a); --a;
				rep(i, 0, n + 1) A[a][i] = 0;
			}
			if (opt[0] == 's') {
				scanf("%d%d", &a, &b); --a, --b;
				rep(i, 0, n + 1) swap(A[a][i], A[b][i]);
			}
		}
		A = mat_pow(A, m);
		rep(i, 0, n) printf("%lld%c", A[i][n], i == n - 1? '\n' : ' ');
	}
	return 0;
}