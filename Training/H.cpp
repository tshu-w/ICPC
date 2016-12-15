#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename "H"
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll MOD = 1e9 + 7;

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B) {
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
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}
int main(int argc, char const *argv[])
{
	setfile();
	ll n;
	while (cin >> n && n) {
		mat A(2, vec(2));
		A[0][0] = 1; A[0][1] = 1;
		A[1][0] = 1; A[1][1] = 0;
		A = pow(A, n + 1);
		cout << A[0][1] << endl;
	}
	resetfile();
	return 0;
}