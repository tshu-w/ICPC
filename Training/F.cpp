#include <bits/stdc++.h>

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

const int a[7][7] = {
	{1, 0, -1, -1, -1, -2, -2},
	{0},
	{0},
	{0},
	{0},
	{0, 1, 1, 2, 3, 5, 8},
	{0, 1, 2, 3, 5, 8, 13}
};
const int b[7] = {1, 18, 28, 46, 75, 121, 197};

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
	ll n;
	while (~scanf("%lld", &n)) {
		if (n <= 1) {
			if (n == 0) cout << 7 << endl;
			else cout << 11 << endl;
		} else {
			mat A(7, vec(7));
			mat B(1, vec(7));
			for (int i = 0; i < 7; ++i) {
				for (int j = 0; j < 7; ++j)
					A[i][j] = a[i][j];
				B[0][i] = b[i];
			}
			mat C(1, vec(7));
			A = pow(A, (n - 2) / 6);
			C = mul(B, A);
			cout << C[0][(n - 2) % 6 + 1] << endl;
		}
	}
	return 0;
}