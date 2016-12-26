// written at 15:49 on 25 Dec 2016 
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
const int MAX_N = 30 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, k, MOD;

typedef vector<int> vec;
typedef vector<vec> mat;
mat A(MAX_N, vec(MAX_N));

mat mat_mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); ++i)
        for (int k = 0; k < B.size(); ++k)
            for (int j = 0; j < B[0].size(); ++j)
                C[i][j] = (C[i][j] + A[i][k] % MOD * B[k][j] % MOD + MOD) % MOD;
    return C;
}

mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); ++i)
        B[i][i] = 1;
    while (n > 0) {
        if (n & 1) B = mat_mul(B, A);
        A = mat_mul(A, A);
        n >>= 1;
    }
    return B;
}
void solve() {
    mat B(n * 2, vec(n * 2));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j)
    		B[i][j + n] = B[i + n][j + n] = A[i][j];
        B[i][i] = 1;
    }
    B = pow(B, k);
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; ++j) {
    		int a = B[i][j + n] % MOD;
    		printf("%d%c", a, j + 1 == n? '\n' : ' '); 
    	}
}

int main(int argc, char const *argv[])
{	
	scanf("%d%d%d", &n, &k, &MOD);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &A[i][j]);
	solve();
	return 0;
}