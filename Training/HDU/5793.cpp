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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;
const long long MOD = 1e9 + 7;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B) {
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < A.size(); ++i)
		for (int k = 0; k < B.size(); ++k)
			for (int j = 0; j < B[0].size(); ++j) 
				C[i][j] = (C[i][j] + A[i][k] % MOD * B[k][j] % MOD + MOD) % MOD;

	return C;
}

mat pow(mat A, int n) {
	mat B(A.size(), vec(A.size()));
	for (int i = 0; i < A.size(); ++i)
		B[i][i] = 1;
	while (n > 0) {
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}
int main(int argc, char const *argv[])
{
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		mat A(2, vec(2));
		A[0][0] = m; A[0][1] = 1;
		A[1][0] = 0; A[1][1] = 1;
		A = pow(A, n);
		cout << (A[0][0] + A[0][1] + MOD) % MOD << endl;
	}
	return 0;
}