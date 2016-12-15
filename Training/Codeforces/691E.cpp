#include <bits/stdc++.h>

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
const int MAX_N = 100 + 10;
const int MOD = 1e9 + 7;

template <typename T>
inline T sqr(T a) { return a * a;}

int N;
ll K, A[MAX_N];

typedef vector<int> vec;
typedef vector<vec> mat;
mat G(MAX_N);

inline int add(int a, int b) { return a + b >= MOD? a + b - MOD : a + b; }
inline void inc(int &a, int b) { a = add(a, b); }
inline int mul(int a, int b) { return int(a * 1ll * b % MOD); }

mat mat_mul(mat &A, mat &B) {
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < A.size(); ++i)
		for (int k = 0; k < B.size(); ++k)
			for (int j = 0; j < B[0].size(); ++j) 
				inc(C[i][j], mul(A[i][k], B[k][j]));
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

int main(int argc, char const *argv[])
{
	cin >> N >> K;
	G.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			if (__builtin_popcountll(A[i] ^ A[j]) % 3 == 0)
				G[i].push_back(1);
			else G[i].push_back(0); 
	}
	G = pow(G, K - 1);
	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			inc(ans, G[i][j]);
	cout << ans << endl;
	return 0;
}