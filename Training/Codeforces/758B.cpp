// written at 22:31 on 19 Jan 2017 
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
const int MAX_N = 1e2 + 10;

int A[10], B[10];
string s;

int main(int argc, char const *argv[])
{
	cin >> s;
	rep(i, 0, s.size()) {
		if (s[i] == 'R')
			B[i % 4] = 0;
		if (s[i] == 'B')
			B[i % 4] = 1;
		if (s[i] == 'Y')
			B[i % 4] = 2;
		if (s[i] == 'G')
			B[i % 4] = 3;
	}
	rep(i, 0, s.size())
		if (s[i] == '!') A[B[i % 4]]++;
	rep(i, 0, 4) 
		printf("%d%c", A[i], i == 3? '\n' : ' ');
	return 0;
}