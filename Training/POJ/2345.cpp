// written at 21:29 on 12 Feb 2017 
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
typedef vector<int> vec;
typedef vector<vec> mat;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 250 + 10;

int N, a;

vec gauss_joedan_xor(const mat& A, const vec& b) {
	int n = A.size();
	mat B(n, vec(n + 1));
	rep(i, 0, n) rep(j, 0, n) B[i][j] = A[i][j];
	rep(i, 0, n) B[i][n] = b[i];

	rep(i, 0, n) {
		int pivot = i;
		rep(j, i, n) if (B[j][i]) {
			pivot = j; break;
		}
		if (pivot != i) swap(B[i], B[pivot]);

		rep(j, 0, n) if (i != j && B[j][i]) {
			rep(k, i + 1, n + 1) B[j][k] ^= B[i][k];
		}
	}
	vec x(n);
	rep(i, 0, n) x[i] = B[i][n];
	return x;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	mat A(N, vec(N, 0));
	vec b(N, 1);
	rep(i, 0, N) {
		while (scanf("%d", &a) && a != -1) {
			--a;
			A[a][i] = 1;
		}
	}	
	vec x = gauss_joedan_xor(A, b);
	vector<int> v;
	rep(i, 0, N) if (x[i]) v.push_back(i + 1);
	rep(i, 0, v.size()) printf("%d%c", v[i], " \n"[i + 1 == v.size()]);
	return 0;
}